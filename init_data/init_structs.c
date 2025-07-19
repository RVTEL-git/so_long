/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:58:05 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/19 17:24:37 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	init_struct(t_mlx_data *data, char *av)
{
	data->img_ptr = malloc(sizeof (t_mlx_img) * 1);
	if (!data->img_ptr)
		return (False);
	if (!parse_map(av, data))
	{
		free(data->img_ptr);
		return (False);
	}
	if (!init_window(data))
	{
		free_map(data->img_ptr->game);
		free(data->img_ptr);
		return (False);
	}
	free(data->img_ptr);
	return (True);
}
