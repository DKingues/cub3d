/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:39:48 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/24 16:39:56 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	load_img(char *path)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image(game()->mlx, path, &img.w, &img.h);
	if (!img.img)
		return (printf("Error\nError loading texture, \
		check if you're inside the repo.\n"), clean_exit(NULL), img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	if (!img.addr)
		return (printf("Error\nError loading texture, \
		check if you're inside the repo.\n\n"), clean_exit(NULL), img);
	img.loaded = 1;
	return (img);
}

float	sign(t_cord p1, t_cord p2, t_cord p3)
{
	return ((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y));
}

int	find_point(t_cord pt, t_cord v1, t_cord v2, t_cord v3)
{
	int		has_neg;
	int		has_pos;
	float	d1;
	float	d2;
	float	d3;

	d1 = sign(pt, v1, v2);
	d2 = sign(pt, v2, v3);
	d3 = sign(pt, v3, v1);
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return (!(has_neg && has_pos));
}

int	ft_usleep(int micro)
{
	struct timeval	start;
	struct timeval	curr;
	long			elapsed;

	elapsed = 0;
	gettimeofday(&start, NULL);
	while (elapsed < micro)
	{
		gettimeofday(&curr, NULL);
		elapsed = (curr.tv_sec - start.tv_sec)
			* 1000000 + (curr.tv_usec - start.tv_usec);
	}
	return (0);
}

char	*nbr_hx_clr(int nbr)
{
	int		var;
	int		temp;
	char	*res;

	var = 1;
	res = ft_calloc(sizeof(char), 3);
	if (!res)
		return (NULL);
	while (nbr != 0)
	{
		temp = nbr % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 55;
		res[var] = temp;
		nbr = nbr / 16;
		var--;
	}
	while (var >= 0)
	{
		res[var] = '0';
		var--;
	}
	return (res);
}
