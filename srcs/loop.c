/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:37:00 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/14 16:12:36 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	loop(void *nada)
{
	struct timeval	start;
	(void)nada;
	if(game()->state == MENU)
		menu_put(0, NULL);
	else if(game()->state == OPT_M)
		opt_m_put();
	else if(game()->state == CTRL_M)
		ctrl_m_put();
	else if(game()->state == PAUSE)
		pause_put();
	else if (game()->state == OPT_P)
		opt_p_put();
	else if (game()->state == CTRL_P)
		ctrl_p_put();
	else if (game()->state == GAME)
	{
		if (game()->game_start == -1)
		{
			gettimeofday(&start, NULL);
			game()->game_start = start.tv_sec;
		}
		game_loop(18);
	}
	else if (game()->state == G_OVER)
		g_over_put();
	else if (game()->state == G_WIN)
		g_win_put();
	else if (game()->state == OPT_G)
		opt_g_put();
	else if (game()->state == CTRL_G)
		ctrl_g_put();
	return (0);
}

int game_over_check(void)
{
	if (game()->map.map[(int)game()->player.player_y][(int)game()->player.player_x] == 'G' || (game()->minutes == 0 && game()->seconds == 0))
	{
		darken(game()->canvas, 1.0, -0.05);
		lighten(game()->st_anim[game()->frame.anim_tg], 0.0);
		game()->state = G_OVER;
		return (1);
	}
	return (0);
}

void	game_loop(int change)
{
	timer(game()->game_start, game()->time);
	glitch_consume(4);
	if(game()->player.sprint_count == 0)
		game()->offset = 5;
	else if (game()->player.sprint_count == 5)
		game()->offset = 0;
	if (game()->player.sprint == 1 && game()->player.sprint_count > game()->offset && (game()->player.moving_w == 1 || game()->player.moving_s == 1 || game()->player.moving_a == 1 || game()->player.moving_d == 1))
	{
		game()->player.sprint_count -= 1;
		change = 9;
	}
	else
		if(game()->player.sprint_count < 100)
			game()->player.sprint_count += 0.25;
	if (game()->player.moving_d == 1)
		d_move(change);
	if (game()->player.moving_s == 1)
		s_move(change);
	if (game()->player.moving_a == 1)
		a_move(change);
	if (game()->player.moving_w == 1)
		w_move(change);
	if(game()->player.rot_l == 1)
		rotate_ray(-1);
	if(game()->player.rot_r == 1)
		rotate_ray(1);
	door_handle();
	ins_map();
	//ft_usleep(13000);
	if(!game_over_check())
		mlx_put_image_to_window(game()->mlx, game()->win, game()->canvas.img, 0, 0);
}

int	menu_put(int keycode, void *nada)
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

int	pause_put(void)
{
	t_data temp;

	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
	&temp.bits_per_pixel, &temp.line_length,
	&temp.endian);
	draw_img(&game()->canvas, &temp, 0, 0, 0.4);
	draw_img(&game()->pause_bt, &temp, 672, 236, 1.0);
	draw_img(&game()->continue_bt[game()->frame.continue_tg], &temp, 754, 412, 1.0);
	draw_img(&game()->option_p_bt[game()->frame.option_p_tg], &temp, 754, 613, 1.0);
	draw_img(&game()->restart_bt[game()->frame.restart_tg], &temp, 754, 513, 1.0);
	draw_img(&game()->return_menu_bt[game()->frame.return_menu_tg], &temp, 754, 713, 1.0);
	draw_img(&game()->quit_p_bt[game()->frame.quit_p_tg], &temp, 754, 814, 1.0);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	mlx_destroy_image(game()->mlx, temp.img);
	return 0;
}

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

void ctrl_p_put(void)
{
	t_data temp;

	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
		&temp.bits_per_pixel, &temp.line_length,
		&temp.endian);
	draw_img(&game()->canvas, &temp, 0, 0, 0.4);
	draw_img(&game()->ctrl_menu, &temp, 0, 0, 1.0);
	draw_img(&game()->ctrlback_bt[game()->frame.ctrlback_tg], &temp, 362, 914, 1.0);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	mlx_destroy_image(game()->mlx, temp.img);
}

void g_win_put(void)
{
	t_data temp;
	int	star = floor(game()->frame.star_tg /10);
	if(game()->frame.anim_tg == 167)
		game()->frame.anim_tg = 0;
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
		&temp.bits_per_pixel, &temp.line_length,
		&temp.endian);
	draw_img(&game()->st_anim[game()->frame.anim_tg], &temp, 0, 0, 1.0);
	draw_img(&game()->g_win_bg, &temp, 0, 0, 1.0);
	draw_img(&game()->star[star], &temp, 701, 441, 1.0);
	draw_img(&game()->return_menu_bt[game()->frame.return_menu_tg], &temp, 755, 666, 1.0);
	draw_img(&game()->quit_p_bt[game()->frame.quit_p_tg], &temp, 755, 766, 1.0);
	game()->frame.anim_tg++;
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	ft_usleep(15000);
	mlx_destroy_image(game()->mlx, temp.img);
	if(game()->frame.star_tg <( game()->frame.diff_tg + 1) * 10)
		game()->frame.star_tg++;
}

void g_over_put(void)
{
	t_data temp;

	if(game()->frame.anim_tg == 167)
		game()->frame.anim_tg = 0;
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
		&temp.bits_per_pixel, &temp.line_length,
		&temp.endian);
	draw_img(&game()->st_anim[game()->frame.anim_tg], &temp, 0, 0, 1.0);
	draw_img(&game()->g_over, &temp, 0, 0, 1.0);
	draw_img(&game()->restart_bt[game()->frame.restart_tg], &temp, 754, 464, 1.0);
	draw_img(&game()->option_p_bt[game()->frame.option_p_tg], &temp, 754, 564, 1.0);
	draw_img(&game()->return_menu_bt[game()->frame.return_menu_tg], &temp, 754, 664, 1.0);
	draw_img(&game()->quit_p_bt[game()->frame.quit_p_tg], &temp, 754, 764, 1.0);
	game()->frame.anim_tg++;
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);	
	ft_usleep(15000);
	mlx_destroy_image(game()->mlx, temp.img);
}

void opt_g_put(void)
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

void ctrl_g_put(void)
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
