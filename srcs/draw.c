/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:05:06 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/24 16:31:45 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	assign_f(void)
{
	char	*temp;
	char	*f_color;

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
	game()->map.F = ft_strtol(f_color);
	free(f_color);
}

void	draw_glitch(int var, int var2)
{
	static int	i;

	if (i == 10)
		i = 0;
	draw_img(&game()->glitch.glitch[i], &game()->canvas, var * 64, var2 * 64);
	i++;
}

void	my_mlx_pixel_put3(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (color == 0x00FF00)
		color = my_mlx_pixel_get(&game()->canvas, x, y);
	if (color == 0xFF0000)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_circle(t_data *src, t_data *dst, int x, int y)
{
	int	sx;
	int	sy;

	sy = 0;
	while (sy < src->res_y)
	{
		sx = 0;
		while (sx < src->res_x)
		{
			my_mlx_pixel_put3(dst, sx + x, sy + y,
				my_mlx_pixel_get(src, sx + x, sy + y));
			sx++;
		}
		sy++;
	}
}

void	ins_map(void)
{
	static int	offset = 0;

	offset++;
	if (offset % 5 == 0)
	{
		game()->frame.glitch_tg++;
		if (game()->frame.glitch_tg == 10)
			game()->frame.glitch_tg = 0;
		offset = 0;
	}
	draw_fc(0, 0, 0.7);
	draw_minimap(0, 0);
	dda_fov();
	draw_img(&game()->timer, &game()->canvas, 0, 0);
	draw_time();
	draw_sprint();
	draw_img(&game()->minimap, &game()->canvas, 47, 96);
}
