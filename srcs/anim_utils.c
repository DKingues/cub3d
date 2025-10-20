/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:25:50 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/20 11:55:54 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_dim_img(t_data *src, t_data *dst, int x, int y, float factor)
{
	int	sx;
	int	sy;

	sy = 0;
	while (sy < 64)
	{
		sx = 0;
		while (sx < 64)
		{
			my_mlx_pixel_put(dst, sx + x, sy + y,
				my_mlx_pixel_get_dim(src, sx + x, sy + y, factor));
			sx++;
		}
		sy++;
	}
}

void	darken(t_data src, float max_factor)
{
	int	var2;
	int	var;
	float	factor = 1.0;

	while(factor >= max_factor)
	{
		var2 = 0;
		mlx_destroy_image(game()->mlx, game()->p_menu.img);
		game()->p_menu.img = mlx_new_image(game()->mlx, 1920, 1024);
		game()->p_menu.addr = mlx_get_data_addr(game()->p_menu.img,
				&game()->p_menu.bits_per_pixel, &game()->p_menu.line_length,
				&game()->p_menu.endian);
		while (game()->map.map[var2])
		{
			var = 0;
			while (game()->map.map[var2][var])
			{
				draw_dim_img(&src, &game()->p_menu, (var * 64), (var2 * 64), factor);
				var++;
			}
			var2++;
		}
		mlx_put_image_to_window(game()->mlx, game()->win, game()->p_menu.img, 0, 0);
		factor -= 0.05;
	}
}

void	lighten(t_data src, float st_factor)
{
	int	var2;
	int	var;

	while(st_factor <= 1.0)
	{
		var2 = 0;
		mlx_destroy_image(game()->mlx, game()->p_menu.img);
		game()->p_menu.img = mlx_new_image(game()->mlx, 1920, 1024);
		game()->p_menu.addr = mlx_get_data_addr(game()->p_menu.img,
				&game()->p_menu.bits_per_pixel, &game()->p_menu.line_length,
				&game()->p_menu.endian);
		while (game()->map.map[var2])
		{
			var = 0;
			while (game()->map.map[var2][var])
			{
				draw_dim_img(&src, &game()->p_menu, (var * 64), (var2 * 64), st_factor);
				var++;
			}
			var2++;
		}
		mlx_put_image_to_window(game()->mlx, game()->win, game()->p_menu.img, 0, 0);
		st_factor += 0.05;
	}
}
