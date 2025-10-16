/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:07:44 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/16 17:50:57 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
#include "../includes/cub3d.h"

void gameplay(void)
{
	mlx_mouse_hook(game()->win, mouse_press, NULL);
	mlx_hook(game()->win, 6, 1L<<6, mouse_move, NULL);
	mlx_hook(game()->win, 2, 1L<<0, key_press, NULL);
	mlx_hook(game()->win, 3, 1L<<1, key_release, NULL);
	mlx_hook(game()->win, 17, 0, clean_exit, NULL);
	mlx_loop_hook(game()->mlx, move, NULL);
	mlx_loop(game()->mlx);
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

int	vid_put(int keycode, void *nada)
{
	(void)keycode;
	(void)nada;
	t_data temp;

	if(game()->frame.anim_tg == 167)
		game()->frame.anim_tg = 0;
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
	&temp.bits_per_pixel, &temp.line_length,
	&temp.endian);
	draw_img(&game()->st_anim[game()->frame.anim_tg], &temp, 0, 0);
	draw_img(&game()->maze_nm, &temp, 404, 166);
	draw_img(&game()->play_bt[game()->frame.play_tg], &temp, 672, 500);
	draw_img(&game()->option_bt[game()->frame.option_tg], &temp, 672, 666);
	draw_img(&game()->quit_bt[game()->frame.quit_tg], &temp, 672, 831);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	game()->frame.anim_tg++;
	ft_usleep(15000);
	mlx_destroy_image(game()->mlx, temp.img);
	return 0;
}
//1005x484
void opt_m_put(void)
{
	t_data temp;

	if(game()->frame.anim_tg == 167)
		game()->frame.anim_tg = 0;
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
		&temp.bits_per_pixel, &temp.line_length,
		&temp.endian);
	draw_img(&game()->st_anim_dim[game()->frame.anim_tg], &temp, 0, 0);
	draw_img(&game()->option_bt[1], &temp, 672, 234);
	draw_img(&game()->sens_bt, &temp, 532, 462);
	draw_img(&game()->diff_bt, &temp, 532, 562);
	draw_img(&game()->ctrl_bt[game()->frame.ctrl_tg], &temp, 532, 663);
	draw_img(&game()->back_bt[game()->frame.back_tg], &temp, 532, 764);
	draw_img(&game()->left_bt[game()->frame.sleft_tg], &temp, 1005, 484);
	draw_img(&game()->right_bt[game()->frame.sright_tg], &temp, 1353, 484);
	draw_img(&game()->left_bt[game()->frame.dleft_tg], &temp, 1005, 579);
	draw_img(&game()->right_bt[game()->frame.dright_tg], &temp, 1353, 579);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	game()->frame.anim_tg++;
	ft_usleep(15000);
	mlx_destroy_image(game()->mlx, temp.img);
}

int	move(void *nada)
{
	float change;

	(void)nada;
	change = 0.05;
	if(game()->state == MENU)
		vid_put(0, NULL);
	else if(game()->state == OPT_M)
		opt_m_put();
	if(game()->state != GAME)
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
	game()->canvas.img = mlx_new_image(game()->mlx, 1920, 1024);
	game()->canvas.addr = mlx_get_data_addr(game()->canvas.img,
			&game()->canvas.bits_per_pixel, &game()->canvas.line_length,
			&game()->canvas.endian);
	ins_map();
	mlx_put_image_to_window(game()->mlx, game()->win, game()->canvas.img, 0, 0);
	return (0);
}

int	key_press(int keycode, t_game *nada)
{
	(void)nada;

	if (keycode == XK_Escape)
		clean_exit(NULL);
	if(game()->state != GAME)
		return (0);
	if (keycode == XK_p)
		pause_game();
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
	return (0);
}

int	key_release(int keycode, t_game *nada)
{
	(void)nada;
	if(game()->state != GAME)
		return (0);
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
