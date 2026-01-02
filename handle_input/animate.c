/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:15:00 by barmarti          #+#    #+#             */
/*   Updated: 2025/12/30 14:15:00 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	animate_sprites(t_mlx_data *data)
{
	struct timeval	current_time;
	long			elapsed_time;

	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - data->img_ptr->last_anim.tv_sec)
		* 1000000 + (current_time.tv_usec - data->img_ptr->last_anim.tv_usec);
	if (elapsed_time >= ANIM_SPEED)
	{
		data->img_ptr->player_frame = (data->img_ptr->player_frame + 1)
			% ANIM_FRAMES;
		data->img_ptr->cons_frame = (data->img_ptr->cons_frame + 1)
			% ANIM_FRAMES;
		data->img_ptr->last_anim = current_time;
		destroy_image(data);
		print_image(data);
	}
	return (0);
}
