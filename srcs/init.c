/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:42 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/15 17:54:25 by rmota-ma         ###   ########.fr       */
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

void	init_vid(void)
{
	int	var;
	char *str;
	char *temp;

	game()->st_anim = ft_calloc(sizeof(t_data), 168);
	var = 0;
	while(var < 167)
	{
		temp = ft_itoa(var + 1);
		str = ft_strjoin(ft_strdup("textures/screen_start/"), temp);
		str = ft_strjoin(str, ".xpm");
		game()->st_anim[var] = load_img(str);
		game()->st_anim[var].res_x = 1920;
		game()->st_anim[var].res_y = 1080;
		var++;
		free(str);
		free(temp);
	}
}

void init(void)
{
	game()->mlx = mlx_init();
	game()->win = mlx_new_window(game()->mlx, 1920, 1080, "cub3D");
	game()->p_menu.img = mlx_new_image(game()->mlx, (1920), (1024));
	game()->p_menu.addr = mlx_get_data_addr(game()->p_menu.img,
			&game()->p_menu.bits_per_pixel, &game()->p_menu.line_length,
			&game()->p_menu.endian);
	game()->credits = load_img("textures/screen_start/1.xpm");
	lighten(game()->credits);
	game()->canvas.img = mlx_new_image(game()->mlx, (1920), (1024));
	game()->wall = load_img("textures/1.xpm");
	game()->wall.res_x = 64;
	game()->wall.res_y = 64;
	game()->floor = load_img("textures/2.xpm");
	game()->floor.res_x = 64;
	game()->floor.res_y = 64;
	game()->person = load_img("textures/3.xpm");
	game()->person.res_x = 64;
	game()->person.res_y = 64;
	game()->pause = load_img("textures/pause.xpm");
	game()->maze_nm = load_img("textures/maze_nm.xpm");
	game()->maze_nm.res_x = 1110;
	game()->maze_nm.res_y = 135;
	game()->play_bt[0] = load_img("textures/play_bt.xpm");
	game()->play_bt[0].res_x = 576;
	game()->play_bt[0].res_y = 116;
	game()->play_bt[1] = load_img("textures/play_bt2.xpm");
	game()->play_bt[1].res_x = 576;
	game()->play_bt[1].res_y = 116;
	game()->option_bt[0] = load_img("textures/option_bt.xpm");
	game()->option_bt[0].res_x = 576;
	game()->option_bt[0].res_y = 116;
	game()->option_bt[1] = load_img("textures/option_bt2.xpm");
	game()->option_bt[1].res_x = 576;
	game()->option_bt[1].res_y = 116;
	game()->quit_bt[0] = load_img("textures/quit_bt.xpm");
	game()->quit_bt[0].res_x = 576;
	game()->quit_bt[0].res_y = 116;
	game()->quit_bt[1] = load_img("textures/quit_bt2.xpm");
	game()->quit_bt[1].res_x = 576;
	game()->quit_bt[1].res_y = 116;
	game()->options = load_img("textures/options.xpm");
	game()->canvas.addr = mlx_get_data_addr(game()->canvas.img,
			&game()->canvas.bits_per_pixel, &game()->canvas.line_length,
			&game()->canvas.endian);
	game()->player.diff = 0;
	game()->player.moving_w = 0;
	game()->player.moving_a = 0;
	game()->player.moving_s = 0;
	game()->player.moving_d = 0;
	game()->player.rot_l = 0;
	game()->player.rot_r = 0;
	game()->mouse.x = 0;
	game()->frame = 0;
	game()->mouse.y = 0;
	game()->paused = 1;
	game()->menued = 1;
	game()->optioned = 1;
	game()->play_tg = 0;
	game()->option_tg = 0;
	game()->quit_tg = 0;
	init_vid();
	game()->mouse.toggle_arrow = mlx_mouse_show(game()->mlx, game()->win); 
	//mlx_mouse_move(game()->mlx, game()->win, 960, 512);
	set_rays(game()->map.map[(int)game()->player.player_y][(int)game()->player.player_x]);
	set_fov(66.0);
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

