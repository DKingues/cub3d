/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:07:44 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/20 18:14:47 by rmota-ma         ###   ########.fr       */
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
	draw_img(&game()->st_anim[game()->frame.anim_tg], &temp, 0, 0, 1.0);
	draw_img(&game()->maze_nm, &temp, 404, 166, 1.0);
	draw_img(&game()->play_bt[game()->frame.play_tg], &temp, 672, 500, 1.0);
	draw_img(&game()->option_bt[game()->frame.option_tg], &temp, 672, 666, 1.0);
	draw_img(&game()->quit_bt[game()->frame.quit_tg], &temp, 672, 831, 1.0);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	game()->frame.anim_tg++;
	ft_usleep(15000);
	mlx_destroy_image(game()->mlx, temp.img);
	return 0;
}

void opt_m_put(void)
{
	t_data temp;

	if(game()->frame.anim_tg == 167)
		game()->frame.anim_tg = 0;
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
		&temp.bits_per_pixel, &temp.line_length,
		&temp.endian);
	draw_img(&game()->st_anim[game()->frame.anim_tg], &temp, 0, 0, 1.0);
	draw_img(&game()->option_bt[1], &temp, 672, 234, 1.0);
	draw_img(&game()->sens_bt, &temp, 532, 462, 1.0);
	draw_img(&game()->diff_bt, &temp, 532, 562, 1.0);
	draw_img(&game()->ctrl_bt[game()->frame.ctrl_tg], &temp, 532, 663, 1.0);
	draw_img(&game()->back_bt[game()->frame.back_tg], &temp, 532, 764, 1.0);
	
	draw_img(&game()->left_bt[game()->frame.sleft_tg], &temp, 1005, 484, 1.0);
	draw_img(&game()->right_bt[game()->frame.sright_tg], &temp, 1353, 484, 1.0);
	
	draw_img(&game()->left_bt[game()->frame.dleft_tg], &temp, 1005, 579, 1.0);
	draw_img(&game()->right_bt[game()->frame.dright_tg], &temp, 1353, 579, 1.0);
	draw_img(&game()->sens_nb[game()->frame.sens_tg], &temp, 1178, 484, 1.0);

	if (game()->frame.diff_tg == 0)
		draw_img(&game()->diff_nb[0], &temp, 1128, 579, 1.0);
	else if (game()->frame.diff_tg == 1)
		draw_img(&game()->diff_nb[1], &temp, 1095, 579, 1.0);
	else if (game()->frame.diff_tg == 2)
		draw_img(&game()->diff_nb[2], &temp, 1128, 579, 1.0);

	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	game()->frame.anim_tg++;
	ft_usleep(15000);
	mlx_destroy_image(game()->mlx, temp.img);
}

void ctrl_m_put(void)
{
	t_data temp;

	if(game()->frame.anim_tg == 167)
		game()->frame.anim_tg = 0;
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
		&temp.bits_per_pixel, &temp.line_length,
		&temp.endian);
	draw_img(&game()->st_anim[game()->frame.anim_tg], &temp, 0, 0, 1.0);
	draw_img(&game()->ctrl_menu, &temp, 0, 0, 1.0);
	draw_img(&game()->ctrlback_bt[game()->frame.ctrlback_tg], &temp, 362, 914, 1.0);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	game()->frame.anim_tg++;
	ft_usleep(15000);
	mlx_destroy_image(game()->mlx, temp.img);
}
//531x512
void opt_p_put(void)
{
	t_data temp;

	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
		&temp.bits_per_pixel, &temp.line_length,
		&temp.endian);
	draw_img(&game()->canvas, &temp, 0, 0, 0.40);
	draw_img(&game()->option_bt[1], &temp, 672, 286, 1.0);
	draw_img(&game()->sens_bt, &temp, 531, 512, 1.0);
	draw_img(&game()->left_bt[game()->frame.sleft_tg], &temp, 989, 535, 1.0);
	draw_img(&game()->right_bt[game()->frame.sright_tg], &temp, 1337, 535, 1.0);
	draw_img(&game()->sens_nb[game()->frame.sens_tg], &temp, 1162, 536, 1.0);
	draw_img(&game()->ctrl_bt[game()->frame.ctrl_tg], &temp, 532, 612, 1.0);
	draw_img(&game()->back_bt[game()->frame.back_tg], &temp, 532, 713, 1.0);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
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
	else if(game()->state == CTRL_M)
		ctrl_m_put();
	else if(game()->state == PAUSE)
		pause_put();
	else if (game()->state == OPT_P)
		opt_p_put();
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

void	press_game(int keycode)
{
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
}

int	key_press(int keycode, t_game *nada)
{
	(void)nada;

	if (keycode == XK_Escape)
		clean_exit(NULL);
	if(game()->state == MENU || game()->state == OPT_M || game()->state == CTRL_M)
		return (0);
	if(game()->state == GAME)
		press_game(keycode);
	else if (keycode == XK_p)
		game()->state = GAME;
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
