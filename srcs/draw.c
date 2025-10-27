/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:05:06 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/23 18:27:05 by rmota-ma         ###   ########.fr       */
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

long	ft_strtol(const char *str)
{
	int	a, b = 0;
	long dec = 0;
	long	res;

	a = ft_strlen(str) - 1;
	res = 0;
	while(a >= 2)
	{
		if (str[a] >= '0' && str[a] <= '9')
			res = str[a] - '0';
		else
			res = str[a] - 'A' + 10;
		dec = dec + res * pow(16, b);
		b++;
		a--;
	}
	return (dec);
}

void	draw_fc(void)
{
	int	sx;
	int	sy;

	sy = 0;
	while (sy < 540)
	{
		sx = 0;
		while (sx < 1920)
		{
			my_mlx_pixel_put(&game()->canvas, sx, sy,
				game()->map.C);
			sx++;
		}
		sy++;
	}
	while (sy < 1080)
	{
		sx = 0;
		while (sx < 1920)
		{
			my_mlx_pixel_put(&game()->canvas, sx, sy,
				game()->map.F);
			sx++;
		}
		sy++;
	}
}

void	assign_c(void)
{
	char *temp;
	char *c_color;

	temp = nbr_hx_clr(ft_atoi(game()->map.map_C[0]));
	c_color = ft_strdup("0x");
	c_color = ft_strjoin(c_color, temp);
	free(temp);
	temp = nbr_hx_clr(ft_atoi(game()->map.map_C[1]));
	c_color = ft_strjoin(c_color, temp);
	free(temp);
	temp = nbr_hx_clr(ft_atoi(game()->map.map_C[2]));
	c_color = ft_strjoin(c_color, temp);
	free(temp);
	ft_free(game()->map.map_C);
	game()->map.map_C = ft_calloc(sizeof(char *), 2);
	game()->map.map_C[0] = ft_strdup(c_color);
	game()->map.map_C[1] = ft_strdup("");
	free(c_color);
	game()->map.C = ft_strtol(game()->map.map_C[0]);
}

void	assign_f(void)
{
	char *temp;
	char *f_color;

	temp = nbr_hx_clr(ft_atoi(game()->map.map_F[0]));
	f_color = ft_strdup("0x");
	f_color = ft_strjoin(f_color, temp);
	free(temp);
	temp = nbr_hx_clr(ft_atoi(game()->map.map_F[1]));
	f_color = ft_strjoin(f_color, temp);
	free(temp);
	temp = nbr_hx_clr(ft_atoi(game()->map.map_F[2]));
	f_color = ft_strjoin(f_color, temp);
	free(temp);
	ft_free(game()->map.map_F);
	game()->map.map_F = ft_calloc(sizeof(char *), 2);
	game()->map.map_F[0] = ft_strdup(f_color);
	game()->map.map_F[1] = ft_strdup("");
	free(f_color);
	game()->map.F = ft_strtol(game()->map.map_F[0]);
}

void	ins_map(void)
{
	int	var2;
	int	var;

	var2 = 0;
	game()->player.player_x -= 0.5;
	game()->player.player_y -= 0.5;
	draw_fc();
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
	draw_img(&game()->timer, &game()->canvas, 770, 0, 1.0);
	draw_time();
	
}
