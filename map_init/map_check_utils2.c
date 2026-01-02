/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:28:39 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/21 13:12:16 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_fill(char **m)
{
	int	index_y;
	int	index_x;

	index_y = 0;
	while (m[index_y])
	{
		index_x = 0;
		while (m[index_y][index_x])
		{
			if (is_target("EPC", m[index_y][index_x]))
			{
				ft_putstr_fd("Error\nSomething is not accessible\n", 2);
				return (False);
			}
			index_x++;
		}
		index_y++;
	}
	return (True);
}

bool	check_dblstr(t_game *g)
{
	int	index_y;

	index_y = g->size->y - 1;
	while (index_y != 0)
	{
		if (g->map[index_y][0] != '1' || g->map[index_y][g->size->x - 1] != '1')
			return (False);
		index_y--;
	}
	return (True);
}

bool	check_string(char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] != '1')
			return (False);
		index++;
	}
	return (True);
}

bool	check_outline(t_game *g)
{
	if (!check_string(g->map[0]))
	{
		ft_putstr_fd("Error\nOutiline not full 1\n", 2);
		return (False);
	}
	if (!check_string(g->map[g->size->y - 1]))
	{
		ft_putstr_fd("Error\nOutiline not full 2\n", 2);
		return (False);
	}
	if (!check_dblstr(g))
	{
		ft_putstr_fd("Error\nOutiline not full 3\n", 2);
		return (False);
	}
	return (True);
}

bool	check_size(char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (index > 100)
			return (False);
		index ++;
	}
	return (True);
}

