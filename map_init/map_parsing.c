/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:27:52 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/21 13:34:37 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Get the height object from the map file
 * The height is define by the number of usable line
 * in the .ber file
 * @param fd The file descriptor contening the map
 * @return size_t the len of the map
 */
void	get_height(int fd, t_game *m)
{
	char	*buff_temp;
	int		len;

	len = 0;
	buff_temp = get_next_line(fd);
	while (buff_temp)
	{
		if (!ft_isspace(buff_temp[0]))
			len++;
		free(buff_temp);
		buff_temp = get_next_line(fd);
	}
	m->size->y = len;
	free(buff_temp);
}

bool	manage_dup(char *src, t_game *m, int index, bool nl)
{
	if (nl)
	{
		if (!check_size(src))
		{
			m->map[index] = NULL;
			dup_error(src);
			return (False);
		}
		m->map[index] = ft_strndup(src, (ft_strlen(src) - 1));
		if (!m->map[index])
			return (False);
	}
	else
	{
		if (!check_size(src))
		{
			m->map[index] = NULL;
			dup_error(src);
			return (False);
		}
		m->map[index] = ft_strndup(src, (ft_strlen(src)));
		if (!m->map[index])
			return (False);
	}
	return (True);
}

bool	fill_up(int fd, t_game *m)
{
	char	*temp;
	int		index;

	m->map = (char **)malloc(sizeof(char *) * (m->size->y + (sizeof(char *))));
	index = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		if (!ft_isspace(temp[0]) && temp[ft_strlen(temp) - 1] == '\n')
		{
			if (!manage_dup(temp, m, index, 1))
				return (False);
			index++;
		}
		else if (!ft_isspace(temp[0]))
		{
			if (!manage_dup(temp, m, index, 0))
				return (False);
			index++;
		}
		free(temp);
		temp = get_next_line(fd);
	}
	m->map[index] = NULL;
	return (True);
}

/**
 * @brief initialize the map struct with all the inforamtion needed and
 * check if the map is valide or not
 * 
 * @param map_av the map .ber
 * @param m the map struct
 */
bool	init(char *map_av, t_game *m)
{
	int	fd;

	if (!init_fd(map_av, m))
		return (False);
	fd = open(map_av, O_RDONLY);
	if (fd < 0)
		return (False);
	if (!fill_up(fd, m))
	{
		free_gnl(fd);
		return (False);
	}
	m->size->x = ft_strlen(m->map[0]);
	if (!init_game(m))
	{
		return (False);
		close (fd);
	}
	if (!final_check(m))
	{
		close (fd);
		return (False);
	}
	return (True);
}

/**
 * @brief verify if the argument is usable and start init some info
 * needed for the game to work
 * 
 * @param arg_map the .ber map file
 */
bool	parse_map(char *arg_map, t_mlx_data *d)
{
	d->img_ptr->game = malloc(sizeof(t_game) * 1);
	if (!d->img_ptr->game)
		return (False);
	init_struct_null(d->img_ptr->game);
	if (!check_ext(arg_map))
	{
		free_map(d->img_ptr->game);
		return (False);
	}
	if (!init(arg_map, d->img_ptr->game))
	{
		free_map(d->img_ptr->game);
		return (False);
	}
	return (True);
}
