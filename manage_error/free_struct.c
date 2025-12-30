/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:02:59 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/18 19:21:21 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_game *g)
{
	if (g->map)
		free_dble_str(g->map);
	free(g->size);
	free(g->pl_pos);
	free(g->ext_pos);
	free(g);
}

void	destroy_image(t_mlx_data *d)
{
	int	i;

	if (d->img_ptr->floor)
		mlx_destroy_image(d->mlx_ptr, d->img_ptr->floor);
	if (d->img_ptr->wall)
		mlx_destroy_image(d->mlx_ptr, d->img_ptr->wall);
	i = 0;
	while (i < ANIM_FRAMES)
	{
		if (d->img_ptr->cons[i])
			mlx_destroy_image(d->mlx_ptr, d->img_ptr->cons[i]);
		if (d->img_ptr->player[i])
			mlx_destroy_image(d->mlx_ptr, d->img_ptr->player[i]);
		i++;
	}
	if (d->img_ptr->exit)
		mlx_destroy_image(d->mlx_ptr, d->img_ptr->exit);
}

void	exit_game(t_mlx_data *data, int exit_code)
{
	if (data->img_ptr->game->move)
		ft_printf("Well done !\nYou've beat the game in %d !\n",
			data->img_ptr->game->move);
	destroy_image(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_map(data->img_ptr->game);
	free(data->mlx_ptr);
	free(data->img_ptr);
	free(data);
	exit(exit_code);
}
