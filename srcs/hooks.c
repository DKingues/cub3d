/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:07:44 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/10 16:19:15 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void run(void)
{
	ins_map();
	mlx_loop_hook(game()->mlx, move, NULL);
	mlx_hook(game()->win, 2, 1L<<0, press, NULL);
	mlx_hook(game()->win, 6, 1L<<6, mouse_move, NULL);
	mlx_hook(game()->win, 3, 1L<<1, release, NULL);
	mlx_hook(game()->win, 17, 0, clean_exit, NULL);
	mlx_loop(game()->mlx);
}

int	move(void *nada)
{
	float change;

	(void)nada;
	change = 0.05;
	if(game()->paused < 0)
		return (0);
	if (game()->player.diff == 1)
		change = 0.1;
	if (game()->player.moving_d == 1 && game()->map.map[(int)(game()->player.player_y)][(int)(game()->player.player_x + 0.1)] != '1')
		game()->player.player_x += change;
	if (game()->player.moving_s == 1 && game()->map.map[(int)(game()->player.player_y + 0.1)][(int)game()->player.player_x] != '1')
		game()->player.player_y += change;
	if (game()->player.moving_a == 1 && game()->map.map[(int)(game()->player.player_y)][(int)(game()->player.player_x - 0.1)] != '1')
		game()->player.player_x -= change;
	if (game()->player.moving_w == 1 && game()->map.map[(int)(game()->player.player_y - 0.1)][(int)game()->player.player_x] != '1')
		game()->player.player_y -= change;
	if(game()->player.rot_l == 1)
		rotate_ray(-1);
	if(game()->player.rot_r == 1)
		rotate_ray(1);
	mlx_destroy_image(game()->mlx, game()->canvas.img);
	game()->canvas.img = mlx_new_image(game()->mlx, (1920), (1024));
	game()->canvas.addr = mlx_get_data_addr(game()->canvas.img,
			&game()->canvas.bits_per_pixel, &game()->canvas.line_length,
			&game()->canvas.endian);
	ins_map();
	if(game()->paused > 0)
		mlx_put_image_to_window(game()->mlx, game()->win, game()->canvas.img, 0, 0);
	return (0);
}

void	draw_dim_img(t_data *src, t_data *dst, int x, int y, float factor)
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
				my_mlx_pixel_get_dim(src, sx + x, sy + y, factor));
			sx++;
		}
		sy++;
	}
}

void	ins_pmenu(void)
{
	int	var2;
	int	var;
	float	factor = 1.0;

	while(factor >= 0.1)
	{
		var2 = 0;
		mlx_destroy_image(game()->mlx, game()->p_menu.img);
		game()->p_menu.img = mlx_new_image(game()->mlx, (1920), (1024));
		game()->p_menu.addr = mlx_get_data_addr(game()->p_menu.img,
				&game()->p_menu.bits_per_pixel, &game()->p_menu.line_length,
				&game()->p_menu.endian);
		while (game()->map.map[var2])
		{
			var = 0;
			while (game()->map.map[var2][var])
			{
				draw_dim_img(&game()->canvas, &game()->p_menu, (var * 64), (var2 * 64), factor);
				var++;
			}
			var2++;
		}
		//draw_img(&game()->pause, &game()->p_menu, 0, 0);
		mlx_put_image_to_window(game()->mlx, game()->win, game()->p_menu.img, 0, 0);
		factor -= 0.05;
	}
}

void	des_pmenu(void)
{
	int	var2;
	int	var;
	float	factor = 0.1;

	while(factor <= 1.0)
	{
		var2 = 0;
		mlx_destroy_image(game()->mlx, game()->p_menu.img);
		game()->p_menu.img = mlx_new_image(game()->mlx, (1920), (1024));
		game()->p_menu.addr = mlx_get_data_addr(game()->p_menu.img,
				&game()->p_menu.bits_per_pixel, &game()->p_menu.line_length,
				&game()->p_menu.endian);
		while (game()->map.map[var2])
		{
			var = 0;
			while (game()->map.map[var2][var])
			{
				draw_dim_img(&game()->canvas, &game()->p_menu, (var * 64), (var2 * 64), factor);
				var++;
			}
			var2++;
		}
		//draw_img(&game()->pause, &game()->p_menu, 0, 0);
		mlx_put_image_to_window(game()->mlx, game()->win, game()->p_menu.img, 0, 0);
		factor += 0.05;
	}
}
int	pause_game(void)
{
	game()->player.moving_w = 0;
	game()->player.moving_a = 0;
	game()->player.moving_s = 0;
	game()->player.moving_d = 0;
	game()->player.rot_r = 0;
	game()->player.rot_l = 0;
	if (game()->paused > 0)
		return (des_pmenu(), 0);
	ins_pmenu();
	return (1);
}

int	press(int keycode, t_game *nada)
{
	(void)nada;
	if (keycode == XK_Escape)
		clean_exit(NULL);
	if (keycode == XK_p)
	{
		game()->paused *= -1;
		pause_game();
	}
	if(game()->paused < 0)
		return (0);
	if (keycode == XK_Shift_L)
		game()->player.diff = 1;
	if (keycode == XK_d)
		game()->player.moving_d = 1;
	if (keycode == XK_s)
		game()->player.moving_s = 1;
	if (keycode == XK_a)
		game()->player.moving_a = 1;
	if (keycode == XK_w)
		game()->player.moving_w = 1;
	if(keycode == XK_Right)
		game()->player.rot_r = 1;
	if(keycode == XK_Left)
		game()->player.rot_l = 1;
	return 0;
}

int	release(int keycode, t_game *nada)
{
	(void)nada;
	if (keycode == XK_Shift_L)
		game()->player.diff = 0;
	if (keycode == XK_d)
		game()->player.moving_d = 0;
	if (keycode == XK_s)
		game()->player.moving_s = 0;
	if (keycode == XK_a)
		game()->player.moving_a = 0;
	if (keycode == XK_w)
		game()->player.moving_w = 0;
	if(keycode == XK_Right)
		game()->player.rot_r = 0;
	if(keycode == XK_Left)
		game()->player.rot_l = 0;
	return 0;
}
