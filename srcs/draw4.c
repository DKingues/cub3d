/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:31:46 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/24 16:31:55 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_sp_img(t_data *src, t_data *dst, int x, float factor)
{
	int	sx;
	int	sy;
	int	y;

	sy = 0;
	y = 0;
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

void	draw_img(t_data *src, t_data *dst, int x, int y)
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
				my_mlx_pixel_get_dim(src, sx, sy, 1.0));
			sx++;
		}
		sy++;
	}
}

long	ft_strtol(const char *str)
{
	int		a;
	int		b;
	long	dec;
	long	res;

	a = ft_strlen(str) - 1;
	b = 0;
	dec = 0;
	res = 0;
	while (a >= 2)
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

void	draw_fc(int sx, int sy, float factor)
{
	factor = 0.7;
	while (sy < 540)
	{
		sx = 0;
		while (sx < 1920)
		{
			my_mlx_pixel_put2(&game()->canvas, sx, sy,
				(dim_clr(game()->map.C, factor)));
			sx++;
		}
		if (factor > 0)
			factor -= 0.00148;
		sy++;
	}
	while (sy < 1080)
	{
		sx = 0;
		while (sx < 1920)
		{
			my_mlx_pixel_put2(&game()->canvas, sx, sy,
				(dim_clr(game()->map.F, 1.0)));
			sx++;
		}
		sy++;
	}
}

void	assign_c(void)
{
	char	*temp;
	char	*c_color;

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
	game()->map.C = ft_strtol(c_color);
	free(c_color);
}
