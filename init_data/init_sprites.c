/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:20:00 by barmarti          #+#    #+#             */
/*   Updated: 2025/12/30 14:20:00 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_player_sprites(t_mlx_data *data, int *w, int *h)
{
	data->img_ptr->player[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/P.xpm", w, h);
	data->img_ptr->player[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/P_1.xpm", w, h);
	data->img_ptr->player[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/P_2.xpm", w, h);
}

static void	load_collectible_sprites(t_mlx_data *data, int *w, int *h)
{
	data->img_ptr->cons[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/C.xpm", w, h);
	data->img_ptr->cons[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/C_1.xpm", w, h);
	data->img_ptr->cons[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/C_2.xpm", w, h);
}

void	init_image(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img_ptr->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/0.xpm", &w, &h);
	data->img_ptr->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/1.xpm", &w, &h);
	load_player_sprites(data, &w, &h);
	data->img_ptr->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/E.xpm", &w, &h);
	load_collectible_sprites(data, &w, &h);
	data->img_ptr->player_frame = 0;
	data->img_ptr->cons_frame = 0;
	gettimeofday(&data->img_ptr->last_anim, NULL);
	if (!data->img_ptr->floor || !data->img_ptr->wall
		|| !data->img_ptr->player[0] || !data->img_ptr->exit
		|| !data->img_ptr->cons[0])
		exit_game(data, 1);
}
