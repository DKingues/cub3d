/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:05:06 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/23 13:05:06 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_img(t_data *src, t_data *dst, int x, int y, float factor)
{
	int	sx;
	int	sy;

	sy = 0;
	while (sy < src->res_y)
	{
		sx = 0;
		while (sx < src->res_x)
		{
			my_mlx_pixel_put(dst, sx + x, sy + y,
				my_mlx_pixel_get_dim(src, sx, sy, factor));
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
        if (game()->map.map[(int)(y0 / 64)][(int)(x0 / 64)] == '1' || game()->map.map[(int)(y0 / 64)][(int)(x0 / 64)] == 'C')
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

void draw_glitch(int var, int var2)
{
	static int i;

	if (i == 10)
		i = 0;
	draw_img(&game()->glitch.glitch[i], &game()->canvas, var * 64, var2 * 64, 1.0);
	i++;
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
				draw_img(&game()->wall, &game()->canvas, (var * 64), (var2 * 64), 1.0);
			else if (game()->map.map[var2][var] == 'C')
				draw_img(&game()->closed_door, &game()->canvas, (var * 64), (var2 * 64), 1.0);
			else if (game()->map.map[var2][var] == 'O')
				draw_img(&game()->open_door, &game()->canvas, (var * 64), (var2 * 64), 1.0);
			else if (game()->map.map[var2][var] == 'G') 
				draw_glitch(var, var2);
			else
				draw_img(&game()->floor, &game()->canvas, (var * 64), (var2 * 64), 1.0);
			var++;
		}
		var2++;
	}
	draw_img(&game()->person, &game()->canvas, (game()->player.player_x * 64), (game()->player.player_y * 64), 1.0);
	game()->player.player_x += 0.5;
	game()->player.player_y += 0.5;
	dda_fov();
	draw_img(&game()->timer, &game()->canvas, 0, 0, 1.0);
	draw_time();
}
