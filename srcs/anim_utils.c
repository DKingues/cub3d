/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:25:50 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/18 18:31:48 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_dim_img(t_data *src, t_data *dst, int arr[2], float factor)
{
	int	sx;
	int	sy;
	int	x;
	int	y;

	sy = 0;
	x = arr[0] * 64;
	y = arr[1] * 64;
	while (sy < 64)
	{
		sx = 0;
		if (sy + y > 1080)
			return ;
		while (sx < 64)
		{
			my_mlx_pixel_put(dst, sx + x, sy + y,
				my_mlx_pixel_get_dim(src, sx + x, sy + y, factor));
			sx++;
		}
		sy++;
	}
}

void	darken(t_data src, float st_factor, float max_factor)
{
	t_data	temp;
	int		arr[2];

	while (st_factor >= max_factor)
	{
		arr[1] = 0;
		temp.img = mlx_new_image(game()->mlx, 1920, 1080);
		temp.addr = mlx_get_data_addr(temp.img,
				&temp.bits_per_pixel, &temp.line_length,
				&temp.endian);
		while (arr[1] < 18)
		{
			arr[0] = 0;
			while (arr[0] < 30)
			{
				draw_dim_img(&src, &temp, arr, st_factor);
				arr[0]++;
			}
			arr[1]++;
		}
		mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
		mlx_destroy_image(game()->mlx, temp.img);
		st_factor -= 0.05;
	}
}

void	lighten(t_data src, float st_factor)
{
	t_data	temp;
	int		arr[2];

	while (st_factor <= 1.0)
	{
		arr[1] = 0;
		temp.img = mlx_new_image(game()->mlx, 1920, 1080);
		temp.addr = mlx_get_data_addr(temp.img,
				&temp.bits_per_pixel, &temp.line_length,
				&temp.endian);
		while (arr[1] < 18)
		{
			arr[0] = 0;
			while (arr[0] < 30)
			{
				draw_dim_img(&src, &temp, arr, st_factor);
				arr[0]++;
			}
			arr[1]++;
		}
		mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
		mlx_destroy_image(game()->mlx, temp.img);
		st_factor += 0.05;
	}
}
