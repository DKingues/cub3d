/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:20:48 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/21 16:26:02 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	singleton_free(void)
{
	if(game()->map.map)
		ft_free(game()->map.map);
	if(game()->map.info)
		ft_free(game()->map.info);
	if(game()->map.map_F)
		ft_free(game()->map.map_F);
	if(game()->map.map_C)
		ft_free(game()->map.map_C);
}

int clean_exit(void *nada)
{
	(void)nada;
	mlx_destroy_image(game()->mlx, game()->canvas.img);
	mlx_destroy_image(game()->mlx, game()->wall.img);
	mlx_destroy_image(game()->mlx, game()->floor.img);
	mlx_destroy_image(game()->mlx, game()->person.img);
	mlx_destroy_image(game()->mlx, game()->p_menu.img);
	mlx_destroy_window(game()->mlx, game()->win);
	mlx_destroy_display(game()->mlx);
	free(game()->mlx);
	singleton_free();
	exit(0);
	return (0);
}
