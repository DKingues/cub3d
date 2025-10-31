/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:06:48 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/22 12:55:53 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if(color == 0x66FF00)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	my_mlx_pixel_get_dim(t_data *data, int x, int y, float factor)
{
	unsigned int color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	(void)factor;
	color = my_mlx_pixel_get(data, x, y);
	if(color == 0x66FF00)
		return color;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (unsigned char)(r * factor);
	g = (unsigned char)(g * factor);
	b = (unsigned char)(b * factor);
	return ((r << 16) | (g << 8) | b);
}

t_data	load_img(char *path)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image(game()->mlx, path, &img.w, &img.h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

float sign (t_cord p1, t_cord p2, t_cord p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

int find_point(t_cord pt, t_cord v1, t_cord v2, t_cord v3)
{
    float d1, d2, d3;
    int has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}


int	ft_usleep(int micro)
{
	struct timeval start;
	struct timeval curr;
	long elapsed;
	
	elapsed = 0;
	gettimeofday(&start, NULL);
	while(elapsed < micro)
	{
		gettimeofday(&curr, NULL);
		elapsed = (curr.tv_sec - start.tv_sec) * 1000000 + (curr.tv_usec - start.tv_usec);
	}
	return (0);
}