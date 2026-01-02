/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:45:31 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/18 19:19:48 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	init_game(t_game *m)
{
	int	index_x;
	int	index_y;

	index_y = 0;
	while (m->map[index_y])
	{
		index_x = 0;
		while (m->map[index_y][index_x])
		{
			if (!check_char(m, m->map[index_y][index_x], index_y, index_x))
			{
				ft_putstr_fd("Error\nUnknown char\n", 2);
				return (False);
			}
			index_x++;
		}
		index_y++;
	}
	if (!check_double(m))
		return (False);
	return (True);
}

void	init_struct_null(t_game *m)
{
	m->collectible = 0;
	m->exit = 0;
	m->map = NULL;
	m->move = 0;
	m->ext_pos = malloc(sizeof(t_point) * 1);
	m->ext_pos->y = 0;
	m->ext_pos->x = 0;
	m->pl_pos = malloc(sizeof(t_point) * 1);
	m->pl_pos->x = 0;
	m->pl_pos->y = 0;
	m->player = 0;
	m->size = malloc(sizeof(t_point) * 1);
	m->size->x = 0;
	m->size->y = 0;
}

bool	many_maps(int fd)
{
	char	*buff_temp;

	buff_temp = get_next_line(fd);
	while (buff_temp)
	{
		while (buff_temp && ft_isspace(buff_temp[0]))
		{
			free(buff_temp);
			buff_temp = get_next_line(fd);
		}
		while (buff_temp && !ft_isspace(buff_temp[0]))
		{
			free(buff_temp);
			buff_temp = get_next_line(fd);
		}
		while (buff_temp && ft_isspace(buff_temp[0]))
		{
			free(buff_temp);
			buff_temp = get_next_line(fd);
		}
		if (buff_temp && !ft_isspace(buff_temp[0]))
			return (True);
	}
	return (False);
}

bool	final_check(t_game *m)
{
	if (!check_len(m))
		return (False);
	if (!check_outline(m))
		return (False);
	if (!check_access(m))
		return (False);
	return (True);
}

bool	init_fd(char *av, t_game *m)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (False);
	get_height(fd, m);
	close(fd);
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		free_gnl(fd);
		return (False);
	}
	if (many_maps(fd))
	{
		ft_putstr_fd("Error\nToo many maps\n", 2);
		free_gnl(fd);
		close(fd);
		return (False);
	}
	close(fd);
	return (True);
}
