/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:42 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/27 17:17:15 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_gameinfo(void)
{
	int	var;

	var = 0;
	game()->map.info = ft_calloc(7, sizeof(char *));
	while(var < 6)
	{
		game()->map.info[var] = ft_strdup("init");
		var++;
	}
}

void	draw_loading(int i)
{
	static int j = 0;
	t_data temp;

	if ((i % 8 == 0 || i == 166) && j < 20)
	{
		temp.img = mlx_new_image(game()->mlx, 1218, 32);
			temp.addr = mlx_get_data_addr(temp.img,
				&temp.bits_per_pixel, &temp.line_length,
				&temp.endian);
		draw_img(&game()->loading_bar[j++], &temp, 0, 0, 1.0);
		mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 351, 826);
		mlx_destroy_image(game()->mlx, temp.img);
	}
}

void	init_vid(void)
{
	int	var;
	char *str;
	char *temp;
	game()->st_anim = ft_calloc(sizeof(t_data), 168);
	var = 0;
	while(var < 167)
	{
		draw_loading(var);
		temp = ft_itoa(var + 1);
		str = ft_strjoin(ft_strdup("textures/menu_vid/"), temp);
		str = ft_strjoin(str, ".xpm");
		game()->st_anim[var] = load_img(str);
		game()->st_anim[var].res_x = 1920;
		game()->st_anim[var].res_y = 1080;
		var++;
		free(str);
		free(temp);
	}
}

void load_full_img(t_data *texture, char *path, int x, int y)
{
	(*texture) = load_img(path);
	(*texture).res_x = x;
	(*texture).res_y = y;
}

void	load_multiple_images(t_data *texture, char *path, int x, int y, int quantity)
{
	int i;
	char *str;

	i = 0;
	while (i < quantity)
	{
		str = ft_strjoin(ft_strdup(path), ft_itoa(i));
		str = ft_strjoin(str, ".xpm");
		load_full_img(&texture[i], str, x, y);
		free(str);
		i++;
	}
}

void	reinit(void)
{
	//mlx_mouse_move(game()->mlx, game()->win, 960, 512);
	game()->game_over = 0;
	game()->game_start = -1;
	game()->frame.return_menu_tg = 0;
	game()->frame.continue_tg = 0;
	game()->frame.sens_tg = 0;
	game()->frame.anim_tg = 0;
	game()->frame.play_tg = 0;
	game()->frame.option_tg = 0;
	game()->frame.ctrl_tg = 0;
	game()->frame.quit_tg = 0;
	game()->frame.sleft_tg = 0;
	game()->frame.sright_tg = 0;
	game()->frame.dleft_tg = 0;
	game()->frame.dright_tg = 0;
	game()->frame.back_tg = 0;
	game()->frame.ctrlback_tg = 0;
	game()->frame.quit_p_tg = 0;
	game()->frame.option_p_tg = 0;
	game()->frame.diff_tg = 0;
	game()->player.sprint = 0;
	game()->player.sprint_count = 100;
	game()->player.moving_w = 0;
	game()->player.moving_a = 0;
	game()->player.moving_s = 0;
	game()->player.moving_d = 0;
	game()->player.rot_l = 0;
	game()->player.rot_r = 0;
	game()->mouse.x = 0;
	game()->mouse.y = 0;
	game()->offset = 0;
	game()->player.player_x = game()->player.start_x;
	game()->player.player_y = game()->player.start_y;
	set_rays(game()->map.map[(int)game()->player.player_y][(int)game()->player.player_x]);
	set_fov(66.0);
	//ins_map();
}

void init(void)
{
	t_data temp;

	game()->mlx = mlx_init();
	game()->win = my_mlx_new_window(game()->mlx, 1920, 1080, "cub3D");
	load_full_img(&game()->loading_screen, "textures/loading/LoadingScreen.xpm", 1920, 1080);
	load_multiple_images(game()->loading_bar, "textures/loading/LoadingScreenBar", 1218, 32, 20);
	lighten(game()->loading_screen, 0.0);
	game()->canvas.img = mlx_new_image(game()->mlx, (1920), (1080));
	game()->canvas.addr = mlx_get_data_addr(game()->canvas.img,
			&game()->canvas.bits_per_pixel, &game()->canvas.line_length,
			&game()->canvas.endian);
	game()->canvas.res_x = 1920;
	game()->canvas.res_y = 1080;
	load_full_img(&game()->wall, "textures/1.xpm", 64, 64);
	load_full_img(&game()->floor, "textures/2.xpm", 64, 64);
	load_full_img(&game()->person, "textures/3.xpm", 64, 64);
	load_full_img(&game()->maze_nm, "textures/buttons/maze_nm.xpm", 1110, 135);
	load_full_img(&game()->ctrl_menu, "textures/buttons/ctrl_menu.xpm", 1920, 1080);
	load_multiple_images(game()->return_menu_bt, "textures/buttons/return_menu_bt", 412, 79, 2);
	load_multiple_images(game()->play_bt, "textures/buttons/play_bt", 576, 116, 2);
	load_multiple_images(game()->option_bt, "textures/buttons/option_bt", 576, 116, 2);
	load_multiple_images(game()->quit_bt, "textures/buttons/quit_bt", 576, 116, 2);
	load_multiple_images(game()->back_bt, "textures/buttons/back_bt", 855, 79, 2);
	load_multiple_images(game()->ctrl_bt, "textures/buttons/ctrl_bt", 855, 80, 2);
	load_multiple_images(game()->ctrlback_bt, "textures/buttons/ctrlback_bt", 1195, 79, 2);
	load_multiple_images(game()->left_bt, "textures/buttons/left_bt", 30, 34, 2);
	load_multiple_images(game()->right_bt, "textures/buttons/right_bt", 30, 34, 2);
	load_full_img(&game()->diff_bt, "textures/buttons/diff_bt.xpm", 411, 78);
	load_full_img(&game()->sens_bt, "textures/buttons/sens_bt.xpm", 411, 78);
	load_multiple_images(game()->sens_nb, "textures/buttons/sens_nb", 31, 31, 5);
	load_multiple_images(game()->diff_nb, "textures/buttons/diff_nb", 131, 31, 3);
	mlx_destroy_image(game()->mlx, game()->diff_nb[1].img);
	load_full_img(&game()->diff_nb[1], "textures/buttons/diff_nb1.xpm", 198, 31);
	load_multiple_images(game()->continue_bt, "textures/buttons/continue_bt", 410, 78, 2);
	load_multiple_images(game()->option_p_bt, "textures/buttons/option_p_bt", 410, 78, 2);
	load_full_img(&game()->pause_bt, "textures/buttons/pause_bt.xpm", 576, 116);
	load_multiple_images(game()->quit_p_bt, "textures/buttons/quit_p_bt", 410, 78, 2);
	load_full_img(&game()->closed_door, "textures/doorC.xpm", 64, 64);
	load_full_img(&game()->open_door, "textures/doorO.xpm", 64, 64);
	load_full_img(&game()->timer, "textures/timer.xpm", 380, 84);
	load_multiple_images(game()->glitch, "textures/glitch/Glitch", 432, 432, 20);
	load_multiple_images(game()->timer_nbr, "textures/numbers/", 31, 31, 10);
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
	game()->release = 0;
	init_vid();
	game()->state = MENU;
	game()->mouse.toggle_arrow = mlx_mouse_show(game()->mlx, game()->win); 
	main_move();
	assign_f();
	assign_c();
	free(game()->map.map_F);
	free(game()->map.map_C);
	reinit();
	draw_img(&game()->loading_bar[19], &game()->loading_screen, 351, 826, 1.0);
	darken(game()->loading_screen, 1.0, -0.05);
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
	&temp.bits_per_pixel, &temp.line_length,
	&temp.endian);
	draw_img(&game()->st_anim[0], &temp, 0, 0, 1.0);
	draw_img(&game()->maze_nm, &temp, 404, 166, 1.0);
	draw_img(&game()->play_bt[game()->frame.play_tg], &temp, 672, 500, 1.0);
	draw_img(&game()->option_bt[game()->frame.option_tg], &temp, 672, 666, 1.0);
	draw_img(&game()->quit_bt[game()->frame.quit_tg], &temp, 672, 831, 1.0);
	lighten(temp, 0.0);
}

void	set_rays(char dir)
{
	if (dir == 'N')
	{
		game()->raycast.ray_x = 0;
		game()->raycast.ray_y = -1;
	}
	else if (dir == 'W')
	{
		game()->raycast.ray_x = -1;
		game()->raycast.ray_y = 0;
	}
	else if (dir == 'E')
	{
		game()->raycast.ray_x = 1;
		game()->raycast.ray_y = 0;
	}
	else if (dir == 'S')
	{
		game()->raycast.ray_x = 0;
		game()->raycast.ray_y = 1;
	}
}

void set_fov(double fov_deg)
{
    double fov_rad = fov_deg * PI / 180.0;
    double plane_len = tan(fov_rad / 2.0);

    game()->raycast.plane_x = -game()->raycast.ray_y * plane_len;
    game()->raycast.plane_y = game()->raycast.ray_x * plane_len;
}

t_game *game(void)
{
	static t_game g;
	
	return (&g);
}

