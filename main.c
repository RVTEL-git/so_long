/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:09:38 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/18 15:38:43 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int ac, char **av)
{
	t_mlx_data	*data;

	if (ac == 2)
	{
		data = malloc(sizeof (t_mlx_data) * 1);
		if (!data)
			return (1);
		if (!init_struct(data, av[1]))
		{
			free(data);
			return (1);
		}
	}
	else
	{
		ft_putstr_fd("Error\nPlease check args\n", 2);
		return (1);
	}
	return (0);
}
