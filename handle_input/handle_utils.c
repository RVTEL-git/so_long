/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:31:22 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/19 19:06:09 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_pos(t_game *game, int y, int x)
{
	if (game->pl_pos->y + y < 0 || game->pl_pos->x + x < 0)
		return (False);
	if (game->pl_pos->x + x > game->size->x
		|| game->pl_pos->y + y > game->size->y)
		return (False);
	if (game->map[game->pl_pos->y + y] == NULL
		|| game->map[game->pl_pos->y + y][game->pl_pos->x + x] == '\0')
		return (False);
	if (game->map[game->pl_pos->y + y][game->pl_pos->x + x] == '1')
		return (False);
	else
		return (True);
}

void	change_data(t_game *g, int new_y, int new_x)
{
	g->pl_pos->y = new_y;
	g->pl_pos->x = new_x;
}
