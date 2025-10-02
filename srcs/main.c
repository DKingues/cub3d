/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:47:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/02 18:11:52 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "../includes/cub3d.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

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
        if (game()->map[(int)(y0 / 64)][(int)(x0 / 64)] == '1')
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

void dda_test2(void)
{
    double posX = game()->player.player_x, posY = game()->player.player_y;
    double rayDirX = 0.5, rayDirY = 0.5; // 45 degree (NE direction)

    int mapX = (int)posX;
    int mapY = (int)posY;

    double deltaDistX = fabs(1.0 / rayDirX);
    double deltaDistY = fabs(1.0 / rayDirY);

    int stepX, stepY;
    double sideDistX, sideDistY;

    // Calculate step and initial sideDist
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

    // Calculate perpendicular wall distance
    double perpWallDist;
    if (side == 0)
        perpWallDist = (mapX - posX + (1 - stepX) / 2.0) / rayDirX;
    else
        perpWallDist = (mapY - posY + (1 - stepY) / 2.0) / rayDirY;

    // Calculate exact intersection point (float)
    double hitX = posX + rayDirX * perpWallDist;
    double hitY = posY + rayDirY * perpWallDist;
    draw_line(posX * 64, posY * 64, hitX * 64, hitY * 64);
}

void dda_test(double rayDirX, double rayDirY)
{
    double posX = game()->player.player_x, posY = game()->player.player_y;

    int mapX = (int)posX;
    int mapY = (int)posY;

    double deltaDistX = fabs(1.0 / rayDirX);
    double deltaDistY = fabs(1.0 / rayDirY);

    int stepX, stepY;
    double sideDistX, sideDistY;

    // Calculate step and initial sideDist
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

    // Calculate perpendicular wall distance
    double perpWallDist;
    if (side == 0)
        perpWallDist = (mapX - posX + (1 - stepX) / 2.0) / rayDirX;
    else
        perpWallDist = (mapY - posY + (1 - stepY) / 2.0) / rayDirY;

    // Calculate exact intersection point (float)
    double hitX = posX + rayDirX * perpWallDist;
    double hitY = posY + rayDirY * perpWallDist;

    draw_line(posX * 64, posY * 64, hitX * 64, hitY * 64);
}

int exit1(void * nada)
{
	(void)nada;
	exit(0);
	return 0;
}

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

void	ins_map(void)
{
	int	var2;
	int	var;

	var2 = 0;
	game()->player.player_x -= 0.5;
	game()->player.player_y -= 0.5;
	double initial_x = game()->ray_x;
	double initial_y = game()->ray_y;
	while (game()->map[var2])
	{
		var = 0;
		while (game()->map[var2][var])
		{
			if (game()->map[var2][var] == '1')
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
	while(game()->ray_x <= 1)
	{
		dda_test(game()->ray_x, game()->ray_y);
		game()->ray_x += 0.01;
	}
	game()->ray_x = initial_x;
	while(game()->ray_y <= 1)
	{
		dda_test(game()->ray_x, game()->ray_y);
		game()->ray_y += 0.01;
	}
	game()->ray_y = initial_y;
	//dda_test(-1, -1);
//	dda_test2();
}

t_data	load_img(char *path)
{
	t_data	img;

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

int	move(t_game *nada)
{
	(void)nada;
	float change = 0.05;
	//mlx_clear_window(game()->mlx, game()->win);
	if(game()->diff == 1)
		change = 0.009;
	if (game()->moving_d == 1 && game()->map[(int)(game()->player.player_y)][(int)(game()->player.player_x + 0.1)] != '1')
		game()->player.player_x += change;
	if (game()->moving_s == 1 && game()->map[(int)(game()->player.player_y + 0.1)][(int)game()->player.player_x] != '1')
		game()->player.player_y += change;
	if (game()->moving_a == 1 && game()->map[(int)(game()->player.player_y)][(int)(game()->player.player_x - 0.1)] != '1')
		game()->player.player_x -= change;
	if (game()->moving_w == 1 && game()->map[(int)(game()->player.player_y - 0.1)][(int)game()->player.player_x] != '1')
		game()->player.player_y -= change;
	mlx_destroy_image(game()->mlx, game()->canvas.img);
	game()->canvas.img = mlx_new_image(game()->mlx, (1920), (1024));
	game()->canvas.addr = mlx_get_data_addr(game()->canvas.img,
			&game()->canvas.bits_per_pixel, &game()->canvas.line_length,
			&game()->canvas.endian);	
	ins_map();
	mlx_put_image_to_window(game()->mlx, game()->win, game()->canvas.img, 0, 0);
	return 0;
}

int	press(int keycode, t_game *nada)
{
	(void)nada;
	if (keycode == XK_Shift_L)
		game()->diff = 1;
	if (keycode == XK_Escape)
		exit(0);
	if (keycode == XK_d)
	{
		game()->moving_d = 1;
	}
	if (keycode == XK_s)
	{
		game()->moving_s = 1;
	}
	if (keycode == XK_a)
	{
		game()->moving_a = 1;
	}
	if (keycode == XK_w)
	{
		game()->moving_w = 1;
	}
	return 0;
}

int	release(int keycode, t_game *nada)
{
	(void)nada;
	if (keycode == XK_Shift_L)
		game()->diff = 0;
	if (keycode == XK_d)
	{
		game()->moving_d = 0;
	}
	if (keycode == XK_s)
	{
		game()->moving_s = 0;
	}
	if (keycode == XK_a)
	{
		game()->moving_a = 0;
	}
	if (keycode == XK_w)
	{
		game()->moving_w = 0;
	}
	if(keycode == XK_Right)
	{
		game()->ray_x -= 0.1;
		game()->ray_y += 0.1;
	}
	if(keycode == XK_Left)
	{
		game()->ray_x += 0.1;
		game()->ray_y -= 0.1;
	}
	return 0;
}

void run(void)
{
	t_game *nada;

	nada = NULL;
	ins_map();
	mlx_loop_hook(game()->mlx, move, nada);
	mlx_hook(game()->win, 2, 1L<<0, press, NULL);
	mlx_hook(game()->win, 3, 1L<<1, release, NULL);
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
	game()->diff = 0;
	game()->moving_w = 0;
	game()->moving_a = 0;
	game()->moving_s = 0;
	game()->moving_d = 0;
	game()->ray_x = 1;
	game()->ray_y = 0;
	run();
    return (0);
}
