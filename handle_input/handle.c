/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:38:05 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/19 19:20:21 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move(t_mlx_data *data, t_game *g, int dy, int dx)
{
	static int	move_count;

	if (!check_pos(data->img_ptr->game, dy, dx))
		return ;
	if (g->map[g->pl_pos->y + dy][g->pl_pos->x + dx] == 'C')
		g->collectible--;
	if (g->map[g->pl_pos->y + dy][g->pl_pos->x + dx] == 'E')
	{
		if (data->img_ptr->game->collectible == 0)
		{
			printf("Well done, everything have been collected !\n");
			exit_game(data, 0);
		}
	}
	if (g->pl_pos->y == data->img_ptr->game->ext_pos->y
		&& g->pl_pos->x == data->img_ptr->game->ext_pos->x)
		g->map[g->pl_pos->y][g->pl_pos->x] = 'E';
	else
		g->map[g->pl_pos->y][g->pl_pos->x] = '0';
	g->map[g->pl_pos->y + dy][g->pl_pos->x + dx] = 'P';
	change_data(g, (g->pl_pos->y + dy), (g->pl_pos->x + dx));
	move_count++;
	printf("Moves : %d\n", move_count);
	destroy_image(data);
	print_image(data);
}

int	end_game(t_mlx_data *data)
{
	ft_printf("See you !\n");
	exit_game(data, 0);
	return (0);
}

/**
 * @brief handler to behave in a certain way depending on wich key is pressed
 * 
 * @param keysym the abstract representation of a key when is pressed
 * (A KEYCODE IS THE HARDWARE-SPECIFIC CODE SENT BY THE KEYBOARD -LOGICAL-)
 * ---------------------------------------
 * | keyboard | keysym    | keycode      |
 * | ---------|-----------|--------------|
 * | qwerty   | Q = Q     | Q = position |
 * | azerty   | A = A     | A = position |
 * |----------|-----------|--------------|
 * |          | different | identique    |
 * ---------------------------------------
 * 
 * @param data the event have to interact with window as with the
 * connection to be sure that everything exit proprely
 * @return *A VOIR*
 */
int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		end_game(data);
	else if (keysym == XK_Up || keysym == XK_W || keysym == XK_w)
		ft_move(data, data->img_ptr->game, -1, 0);
	else if (keysym == XK_Down || keysym == XK_S || keysym == XK_s)
		ft_move(data, data->img_ptr->game, 1, 0);
	else if (keysym == XK_Left || keysym == XK_A || keysym == XK_a)
		ft_move(data, data->img_ptr->game, 0, -1);
	else if (keysym == XK_Right || keysym == XK_D || keysym == XK_d)
		ft_move(data, data->img_ptr->game, 0, 1);
	return (0);
}
