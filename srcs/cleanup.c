/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:20:48 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/23 18:23:23 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	singleton_free(void)
{
	if(game()->map.map)
		ft_free(game()->map.map);
	if(game()->map.info)
		ft_free(game()->map.info);
	
}

int clean_exit(void *nada)
{
	(void)nada;
	mlx_destroy_image(game()->mlx, game()->canvas.img);
	mlx_destroy_image(game()->mlx, game()->wall.img);
	mlx_destroy_image(game()->mlx, game()->floor.img);
	mlx_destroy_image(game()->mlx, game()->person.img);
	mlx_destroy_window(game()->mlx, game()->win);
	mlx_destroy_display(game()->mlx);
	free(game()->mlx);
	singleton_free();
	exit(0);
	return (0);
}
