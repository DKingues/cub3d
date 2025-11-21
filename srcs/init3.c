/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:29:07 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/21 13:29:20 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	reinit(void)
{
	char	**temp_map;
	int		st_x;	
	int		st_y;
	int		glitch;

	temp_map = NULL;
	st_y = (int)game()->player.start_y;
	st_x = (int)game()->player.start_x;
	reinit2();
	reinit3();
	temp_map = copy_map(temp_map, game()->map.map);
	glitch = count_zero_r(temp_map, st_y, st_x);
	game()->glitch.to_glitch = glitch;
	ft_free(temp_map);
	set_difficulty();
	game()->glitch.glitch_spawned = 0;
	game()->glitch.glitch_i = 0;
	game()->offset = 0;
	game()->player.player_x = game()->player.start_x;
	game()->player.player_y = game()->player.start_y;
	set_rays(game()->map.map[(int)game()->player.player_y]
	[(int)game()->player.player_x]);
	set_fov(66.0);
	timer(game()->time.level_start, game()->time.level_time);
	ins_map();
}

void	load_images2(void)
{
	load_multiple_images(game()->door, "textures/door/Porta", 56);
	load_multiple_images(game()->restart_bt, "textures/buttons/restart_bt", 2);
	load_multiple_images(game()->play_bt, "textures/buttons/play_bt", 2);
	load_multiple_images(game()->option_bt, "textures/buttons/option_bt", 2);
	load_multiple_images(game()->quit_bt, "textures/buttons/quit_bt", 2);
	load_multiple_images(game()->back_bt, "textures/buttons/back_bt", 2);
	load_multiple_images(game()->ctrl_bt, "textures/buttons/ctrl_bt", 2);
	load_multiple_images(game()->ctrlback_bt,
		"textures/buttons/ctrlback_bt", 2);
	load_multiple_images(game()->left_bt, "textures/buttons/left_bt", 2);
	load_multiple_images(game()->right_bt, "textures/buttons/right_bt", 2);
	load_multiple_images(game()->sens_nb, "textures/buttons/sens_nb", 5);
	load_multiple_images(game()->diff_nb, "textures/buttons/diff_nb", 3);
	load_multiple_images(game()->continue_bt,
		"textures/buttons/continue_bt", 2);
	load_multiple_images(game()->option_p_bt,
		"textures/buttons/option_p_bt", 2);
	load_multiple_images(game()->quit_p_bt, "textures/buttons/quit_p_bt", 2);
	load_multiple_images(game()->glitch.glitch, "textures/glitch/Glitch", 20);
	load_multiple_images(game()->timer_nbr, "textures/numbers/", 10);
}

void	init(void)
{
	assign_f();
	assign_c();
	game()->mlx = mlx_init();
	if (FS == 1)
		game()->win = my_mlx_new_window(game()->mlx, 1920, 1080, "cub3D");
	else
		game()->win = mlx_new_window(game()->mlx, 1920, 1080, "cub3D");
	load_full_img(&game()->loading_screen,
		"textures/loading/LoadingScreen.xpm");
	load_multiple_images(game()->loading_bar,
		"textures/loading/LoadingScreenBar", 20);
	lighten(game()->loading_screen, 0.0);
	new_img(&game()->canvas, 1920, 1080);
	load_full_img(&game()->rays, "textures/fov.xpm");
	new_img(&game()->minimap, 192, 192);
	game()->frame.sens_tg = 0;
	game()->frame.diff_tg = 0;
	load_images();
	game()->release = 0;
	init_cords();
	init_vid();
	game()->state = MENU;
	first_ins();
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

void	set_fov(double fov_deg)
{
	double	fov_rad;
	double	plane_len;

	fov_rad = fov_deg * PI / 180.0;
	plane_len = tan(fov_rad / 2.0);
	game()->raycast.plane_x = -game()->raycast.ray_y * plane_len;
	game()->raycast.plane_y = game()->raycast.ray_x * plane_len;
}
