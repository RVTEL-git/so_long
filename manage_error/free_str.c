/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:55:28 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/13 13:31:35 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	dup_error(char *src)
{
	free(src);
	ft_putstr_fd("Error\nMap is too big\n", 2);
}

void	free_gnl(int fd)
{
	char	*buff_temp;

	buff_temp = get_next_line(fd);
	while (buff_temp)
	{
		free(buff_temp);
		buff_temp = get_next_line(fd);
	}
	free(buff_temp);
}

void	free_dble_str(char **ptr)
{
	int	index;

	index = 0;
	if (!ptr)
		return ;
	while (ptr[index])
	{
		free(ptr[index]);
		index++;
	}
	free(ptr);
}
