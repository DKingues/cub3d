/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:27:56 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/21 13:28:54 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_images(void)
{
	load_full_img(&game()->map.north, game()->map.info[0]);
	load_full_img(&game()->map.south, game()->map.info[1]);
	load_full_img(&game()->map.east, game()->map.info[2]);
	load_full_img(&game()->map.west, game()->map.info[3]);
	load_full_img(&game()->wall, "textures/1.xpm");
	load_full_img(&game()->floor, "textures/2.xpm");
	load_full_img(&game()->person, "textures/3.xpm");
	load_full_img(&game()->maze_nm, "textures/buttons/maze_nm.xpm");
	load_full_img(&game()->ctrl_menu, "textures/buttons/ctrl_menu.xpm");
	load_full_img(&game()->diff_bt, "textures/buttons/diff_bt.xpm");
	load_full_img(&game()->sens_bt, "textures/buttons/sens_bt.xpm");
	load_full_img(&game()->g_over, "textures/lose/gover_bg.xpm");
	load_full_img(&game()->g_win_bg, "textures/win/win_victory.xpm");
	load_full_img(&game()->pause_bt, "textures/buttons/pause_bt.xpm");
	load_full_img(&game()->exit, "textures/exit/Exit1.xpm");
	load_full_img(&game()->closed_door, "textures/doorC.xpm");
	load_full_img(&game()->open_door, "textures/doorO.xpm");
	load_full_img(&game()->timer, "textures/neon_hud.xpm");
	load_multiple_images(game()->g_win, "textures/win/win", 4);
	load_multiple_images(game()->star, "textures/stars/star", 4);
	load_multiple_images(game()->return_menu_bt,
		"textures/buttons/return_menu_bt", 2);
	load_images2();
}

void	new_img(t_data *src, int x, int y)
{
	src[0].img = mlx_new_image(game()->mlx, x, y);
	src[0].addr = mlx_get_data_addr(src[0].img, &src[0].bits_per_pixel,
			&src[0].line_length, &src[0].endian);
	src[0].loaded = 1;
	src[0].res_x = x;
	src[0].res_y = y;
}

void	init_cords2(void)
{
	game()->sleft_pause_c[0].x = 989;
	game()->sleft_pause_c[0].y = 552.5;
	game()->sright_pause_c[0].x = 1367;
	game()->sright_pause_c[0].y = 552.5;
	game()->sleft_pause_c[1].x = 1019;
	game()->sleft_pause_c[1].y = 535;
	game()->sright_pause_c[1].x = 1337;
	game()->sright_pause_c[1].y = 535;
	game()->sleft_pause_c[2].x = 1019;
	game()->sleft_pause_c[2].y = 570;
	game()->sright_pause_c[2].x = 1337;
	game()->sright_pause_c[2].y = 570;
}

void	init_cords(void)
{
	game()->sleft_c[0].x = 1004;
	game()->sleft_c[0].y = 501.5;
	game()->sright_c[0].x = 1383;
	game()->sright_c[0].y = 501.5;
	game()->dleft_c[0].x = 1004;
	game()->dleft_c[0].y = 596.5;
	game()->dright_c[0].x = 1383;
	game()->dright_c[0].y = 596.5;
	game()->sleft_c[1].x = 1035;
	game()->sleft_c[1].y = 484;
	game()->sright_c[1].x = 1353;
	game()->sright_c[1].y = 484;
	game()->dleft_c[1].x = 1035;
	game()->dleft_c[1].y = 614;
	game()->dright_c[1].x = 1353;
	game()->dright_c[1].y = 614;
	game()->sleft_c[2].x = 1035;
	game()->sleft_c[2].y = 519;
	game()->sright_c[2].x = 1353;
	game()->sright_c[2].y = 519;
	game()->dleft_c[2].x = 1035;
	game()->dleft_c[2].y = 579;
	game()->dright_c[2].x = 1353;
	game()->dright_c[2].y = 579;
	init_cords2();
}

void	first_ins(void)
{
	t_data	temp;
	int		norm;

	norm = mlx_mouse_show(game()->mlx, game()->win);
	game()->mouse.tg_ar = norm;
	main_move();
	reinit();
	draw_img(&game()->loading_bar[19], &game()->loading_screen, 351, 826, 1.0);
	darken(game()->loading_screen, 1.0, -0.05);
	new_img(&temp, 1920, 1080);
	draw_img(&game()->st_anim[0], &temp, 0, 0, 1.0);
	draw_img(&game()->maze_nm, &temp, 404, 166, 1.0);
	draw_img(&game()->play_bt[game()->frame.play_tg], &temp, 672, 500, 1.0);
	draw_img(&game()->option_bt[game()->frame.option_tg], &temp, 672, 666, 1.0);
	draw_img(&game()->quit_bt[game()->frame.quit_tg], &temp, 672, 831, 1.0);
	lighten(temp, 0.0);
	mlx_destroy_image(game()->mlx, temp.img);
}
