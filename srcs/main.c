/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:47:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/29 17:03:34 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "../includes/cub3d.h"
/*
void dda_test(void)
{
	double posX = game()->player.player_x, posY = game()->player.player_y;
	double rayDirX = 0.7, rayDirY = 0.4;
	
	int mapX = (int)posX;
	int mapY = (int)posY;
	
	double deltaDistX = fabs(1.0 / rayDirX);
	double deltaDistY = fabs(1.0 / rayDirY);
	
	int stepX, stepY;
	double sideDistX, sideDistY;
	
	if (rayDirX < 0) {
	    stepX = -1;
	    sideDistX = (posX - mapX) * deltaDistX;
	} else {
	    stepX = 1;
	    sideDistX = (mapX + 1.0 - posX) * deltaDistX;
	}
	if (rayDirY < 0) {
	    stepY = -1;
	    sideDistY = (posY - mapY) * deltaDistY;
	} else {
	    stepY = 1;
	    sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	}
	
	int hit = 0;
	int side;
	while (!hit) {
	    if (sideDistX < sideDistY) {
	        sideDistX += deltaDistX;
	        mapX += stepX;
	        side = 0;
	    } else {
	        sideDistY += deltaDistY;
	        mapY += stepY;
	        side = 1;
	    }
	    if (game()->map[mapY][mapX] == '1') 
			hit = 1;
	}
	
	double perpWallDist;
	if (side == 0)
	    perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
	else
	    perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
	printf("SIDE WALL DIST: %f\n", perpWallDist);
}*/

int exit1(void * nada)
{
	(void)nada;
	exit(0);
	return 0;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_img(t_img *src, t_img *dst, int x, int y)
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

void	ins_map(void)
{
	int	var2;
	int	var;

	var2 = 0;
	while (game()->map[var2])
	{
		var = 0;
		while (game()->map[var2][var])
		{
			if (game()->map[var2][var] == '1')
				draw_img(&game()->wall, &game()->canvas, (var * 64), (var2 * 64));
			if (game()->map[var2][var] == '0')
				draw_img(&game()->floor, &game()->canvas, (var * 64), (var2 * 64));
			if (game()->map[var2][var] == 'S')
				draw_img(&game()->person, &game()->canvas, (var * 64), (var2 * 64));
			var++;
		}
		var2++;
	}
}

t_img	load_img(char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(game()->mlx, path, &img.w, &img.h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

void init(void)
{
	game()->canvas.img = mlx_new_image(game()->mlx, (1920), (1024));
	game()->wall = load_img("textures/1.xpm");
	game()->floor = load_img("textures/2.xpm");
	game()->person = load_img("textures/3.xpm");
	game()->canvas.addr = mlx_get_data_addr(game()->canvas.img,
			&game()->canvas.bits_per_pixel, &game()->canvas.line_length,
			&game()->canvas.endian);
}

void run(void)
{
	ins_map();
	mlx_put_image_to_window(game()->mlx, game()->win, game()->canvas.img, 0, 0);
	mlx_loop(game()->mlx);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (printf("Insert a map name.\n"), 1);
	if (ac > 2)
		return (printf("Too many arguments.\n"), 1);
	if (parsing(av))
		return (1);
	game()->mlx = mlx_init();
	game()->win = mlx_new_window(game()->mlx, 1920, 1024, "cub3d");
	init();
	run();
    return (0);
}
