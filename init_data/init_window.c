/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:21:32 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/19 19:59:44 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_image(t_mlx_data *d, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->img_ptr->wall, x * 64, y * 64);
	else if (c == '0')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->img_ptr->floor, x * 64, y * 64);
	else if (c == 'P')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->img_ptr->player[d->img_ptr->player_frame], x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->img_ptr->cons[d->img_ptr->cons_frame], x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->img_ptr->exit, x * 64, y * 64);
}

void	init_image(t_mlx_data *data)
{
	int	w;
	int	h;

	data->img_ptr->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/0.xpm", &w, &h);
	data->img_ptr->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/1.xpm", &w, &h);
	data->img_ptr->player[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/P.xpm", &w, &h);
	data->img_ptr->player[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/P_1.xpm", &w, &h);
	data->img_ptr->player[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/P_2.xpm", &w, &h);
	data->img_ptr->exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/E.xpm", &w, &h);
	data->img_ptr->cons[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/C.xpm", &w, &h);
	data->img_ptr->cons[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/C_1.xpm", &w, &h);
	data->img_ptr->cons[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"tiles_xpm/C_2.xpm", &w, &h);
	data->img_ptr->player_frame = 0;
	data->img_ptr->cons_frame = 0;
	gettimeofday(&data->img_ptr->last_anim, NULL);
	if (!data->img_ptr->floor || !data->img_ptr->wall
		|| !data->img_ptr->player[0] || !data->img_ptr->exit
		|| !data->img_ptr->cons[0])
		exit_game(data, 1);
}

void	print_image(t_mlx_data *d)
{
	int	x;
	int	y;

	y = 0;
	init_image(d);
	while (d->img_ptr->game->map[y])
	{
		x = 0;
		while (d->img_ptr->game->map[y][x])
		{
			if (d->img_ptr->game->map[y][x] == '1')
				put_image(d, '1', x, y);
			else
				put_image(d, '0', x, y);
			if (d->img_ptr->game->map[y][x] == 'P')
				put_image(d, 'P', x, y);
			else if (d->img_ptr->game->map[y][x] == 'C')
				put_image(d, 'C', x, y);
			else if (d->img_ptr->game->map[y][x] == 'E')
				put_image(d, 'E', x, y);
			x++;
		}
		y++;
	}
}

bool	init_window(t_mlx_data *data)
{
	int	height;
	int	width;

	height = data->img_ptr->game->size->y * 64;
	width = data->img_ptr->game->size->x * 64;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (False);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "so_long");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free_map(data->img_ptr->game);
		free(data->mlx_ptr);
		return (False);
	}
	print_image(data);
	mlx_hook(data->win_ptr, 17, 0, end_game, data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_loop_hook(data->mlx_ptr, &animate_sprites, data);
	mlx_loop(data->mlx_ptr);
	return (True);
}
