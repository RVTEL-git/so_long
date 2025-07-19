/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:11:29 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/18 17:24:03 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	change_it(char c, bool use)
{
	if (use)
	{
		if (c == 'P')
			c = 'p';
		else if (c == '0')
			c = 'o';
		else if (c == 'C')
			c = 'c';
		else if (c == 'E')
			c = 'e';
	}
	else
	{
		if (c == 'p')
			c = 'P';
		else if (c == 'o')
			c = '0';
		else if (c == 'c')
			c = 'C';
		else if (c == 'e')
			c = 'E';
	}
	return (c);
}

bool	didit_change(char c, bool use)
{
	if (!use)
	{
		if (c == 'E' || c == 'C' || c == '0' || c == 'P')
			return (True);
		else
			return (False);
	}
	else
	{
		if (c == 'e' || c == 'c' || c == 'o' || c == 'p')
			return (True);
		else
			return (False);
	}
}

bool	is_target(char	*target, char c)
{
	int	index;

	index = 0;
	while (target[index])
	{
		if (c == target[index])
			return (True);
		index++;
	}
	return (False);
}

void	fill(char **map, t_point *size, int pos_y, int pos_x)
{
	char	*target;

	target = "0EPC";
	if (size->x < 0 || size->y < 0 || pos_x > size->x || pos_y > size->y)
		return ;
	if (!is_target(target, map[pos_y][pos_x])
		|| !didit_change(map[pos_y][pos_x], False))
		return ;
	map[pos_y][pos_x] = change_it(map[pos_y][pos_x], True);
	fill(map, size, pos_y + 1, pos_x);
	fill(map, size, pos_y - 1, pos_x);
	fill(map, size, pos_y, pos_x + 1);
	fill(map, size, pos_y, pos_x - 1);
}

void	flood_fill(t_game *m, bool use)
{
	if (use)
		fill(m->map, m->size, m->pl_pos->y, m->pl_pos->x);
	else
		rfill(m->map, m->size, m->pl_pos->y, m->pl_pos->x);
}
