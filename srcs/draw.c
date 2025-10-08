/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:05:06 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/08 21:23:05 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_img(t_data *src, t_data *dst, int x, int y)
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
				my_mlx_pixel_get(src, sx, sy));
			sx++;
		}
		sy++;
	}
}

void draw_line(float x0, float y0, float x1, float y1)
{
    float dx = fabs(x1 - x0);
    float dy = fabs(y1 - y0);
    float sx = x0 < x1 ? 1 : -1;
    float sy = y0 < y1 ? 1 : -1;
    float err = dx - dy;
    float e2;
    while (1)    
	{
        my_mlx_pixel_put(&game()->canvas, (x0), (y0), 0x0096FF);
        if (game()->map.map[(int)(y0 / 64)][(int)(x0 / 64)] == '1')
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void	ins_map(void)
{
	int	var2;
	int	var;

	var2 = 0;
	game()->player.player_x -= 0.5;
	game()->player.player_y -= 0.5;
	while (game()->map.map[var2])
	{
		var = 0;
		while (game()->map.map[var2][var])
		{
			if (game()->map.map[var2][var] == '1')
				draw_img(&game()->wall, &game()->canvas, (var * 64), (var2 * 64));
			else
				draw_img(&game()->floor, &game()->canvas, (var * 64), (var2 * 64));
			var++;
		}
		var2++;
	}
	draw_img(&game()->person, &game()->canvas, (game()->player.player_x * 64), (game()->player.player_y * 64));
	game()->player.player_x += 0.5;
	game()->player.player_y += 0.5;
	dda_fov();
}
