/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:26:34 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/12 14:01:53 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	rfill(char **map, t_point *size, int pos_y, int pos_x)
{
	char	*target;

	target = "oepc";
	if (size->x < 0 || size->y < 0 || pos_x > size->x || pos_y > size->y)
		return ;
	if (!is_target(target, map[pos_y][pos_x])
		|| !didit_change(map[pos_y][pos_x], True))
		return ;
	map[pos_y][pos_x] = change_it(map[pos_y][pos_x], False);
	rfill(map, size, pos_y + 1, pos_x);
	rfill(map, size, pos_y - 1, pos_x);
	rfill(map, size, pos_y, pos_x + 1);
	rfill(map, size, pos_y, pos_x - 1);
}
