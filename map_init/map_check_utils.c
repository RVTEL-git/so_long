/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:22:24 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/21 13:26:31 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_ext(char *map)
{
	size_t	len;

	len = ft_strlen(map);
	if (len <= 4)
	{
		ft_putstr_fd("Error\nWrong extention name\n", 2);
		return (False);
	}
	if (ft_strncmp(&map[len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nWrong extention name\n", 2);
		return (False);
	}
	return (True);
}

bool	check_len(t_game *g)
{
	int		time;
	size_t	len;

	time = g->size->y - 1;
	len = ft_strlen(g->map[0]);
	if (time < 2 || len < 2)
	{
		ft_putstr_fd("Error\nThe map is too small\n", 2);
		return (False);
	}
	while (time)
	{
		if (ft_strlen(g->map[time]) != len)
		{
			ft_putstr_fd("Error\nThe map is not rectangular\n", 2);
			return (False);
		}
		time--;
	}
	return (True);
}

bool	check_char(t_game *m, char c, int y, int x)
{
	if (c == 'P')
	{
		m->pl_pos->x = x;
		m->pl_pos->y = y;
		m->player++;
		return (True);
	}
	else if (c == 'C')
	{
		m->collectible++;
		return (True);
	}
	else if (c == 'E')
	{
		m->ext_pos->y = y;
		m->ext_pos->x = x;
		m->exit++;
		return (True);
	}
	else if (c == '1' || c == '0')
		return (True);
	else
		return (False);
}

bool	check_access(t_game *g)
{
	flood_fill(g, True);
	if (!check_fill(g->map))
		return (False);
	flood_fill(g, False);
	return (True);
}

bool	check_double(t_game *m)
{
	if (m->exit != 1)
	{
		ft_putstr_fd("Error\nWrong number of exit\n", 2);
		return (False);
	}
	else if (m->player != 1)
	{
		ft_putstr_fd("Error\nWrong number of player\n", 2);
		return (False);
	}
	else if (m->collectible <= 0)
	{
		ft_putstr_fd("Error\nNo collectible\n", 2);
		return (False);
	}
	else if (m->size->y * 64 > 900 || m->size->x * 64 > 1600)
	{
		ft_putstr_fd("Error\nMap toot big\n", 2);
		return (False);
	}
	return (True);
}
