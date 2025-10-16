/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:42 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/16 17:46:07 by rmota-ma         ###   ########.fr       */
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

void	init_vid2(void)
{
	int	var;
	int var2 = 0, var3 = 0;

	game()->st_anim_dim = ft_calloc(sizeof(t_data), 168);
	var = 0;
	while(var < 167)
	{
		var2 = 0;
		game()->st_anim_dim[var].img = mlx_new_image(game()->mlx, (1920), (1080));
		game()->st_anim_dim[var].addr = mlx_get_data_addr(game()->st_anim_dim[var].img,
			&game()->st_anim_dim[var].bits_per_pixel, &game()->st_anim_dim[var].line_length,
			&game()->st_anim_dim[var].endian);
		game()->st_anim_dim[var].res_x = 1920;
		game()->st_anim_dim[var].res_y = 1080;
		while(game()->map.map[var2])
		{
			var3 = 0;
			while(game()->map.map[var2][var3])
			{
				draw_dim_img(&game()->st_anim[var], &game()->st_anim_dim[var], (var3 * 64), (var2 * 64), 0.65);
				var3++;
			}
			var2++;
		}
		var++;
	}
}

void init(void)
{
	t_data temp;
	game()->mlx = mlx_init();
	game()->win = mlx_new_window(game()->mlx, 1920, 1080, "cub3D222222222");
	game()->p_menu.img = mlx_new_image(game()->mlx, (1920), (1024));
	game()->p_menu.addr = mlx_get_data_addr(game()->p_menu.img,
			&game()->p_menu.bits_per_pixel, &game()->p_menu.line_length,
			&game()->p_menu.endian);
	game()->credits = load_img("textures/menu_vid/1.xpm");
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
	game()->pause = load_img("textures/menu_vid/1.xpm");
	game()->maze_nm = load_img("textures/buttons/maze_nm.xpm");
	game()->maze_nm.res_x = 1110;
	game()->maze_nm.res_y = 135;
	game()->play_bt[0] = load_img("textures/buttons/play_bt.xpm");
	game()->play_bt[0].res_x = 576;
	game()->play_bt[0].res_y = 116;
	game()->play_bt[1] = load_img("textures/buttons/play_bt2.xpm");
	game()->play_bt[1].res_x = 576;
	game()->play_bt[1].res_y = 116;
	game()->option_bt[0] = load_img("textures/buttons/option_bt.xpm");
	game()->option_bt[0].res_x = 576;
	game()->option_bt[0].res_y = 116;
	game()->option_bt[1] = load_img("textures/buttons/option_bt2.xpm");
	game()->option_bt[1].res_x = 576;
	game()->option_bt[1].res_y = 116;
	game()->quit_bt[0] = load_img("textures/buttons/quit_bt.xpm");
	game()->quit_bt[0].res_x = 576;
	game()->quit_bt[0].res_y = 116;
	game()->quit_bt[1] = load_img("textures/buttons/quit_bt2.xpm");
	game()->quit_bt[1].res_x = 576;
	game()->quit_bt[1].res_y = 116;
	game()->back_bt[0] = load_img("textures/buttons/back_bt.xpm");
	game()->back_bt[0].res_x = 855;
	game()->back_bt[0].res_y = 79;
	game()->back_bt[1] = load_img("textures/buttons/back_bt2.xpm");
	game()->back_bt[1].res_x = 855;
	game()->back_bt[1].res_y = 79;
	game()->ctrl_bt[0] = load_img("textures/buttons/ctrl_bt.xpm");
	game()->ctrl_bt[0].res_x = 855;
	game()->ctrl_bt[0].res_y = 80;
	game()->ctrl_bt[1] = load_img("textures/buttons/ctrl_bt2.xpm");
	game()->ctrl_bt[1].res_x = 855;
	game()->ctrl_bt[1].res_y = 80;
	game()->left_bt[0] = load_img("textures/buttons/left_bt.xpm");
	game()->left_bt[0].res_x = 30;
	game()->left_bt[0].res_y = 34;
	game()->left_bt[1] = load_img("textures/buttons/left_bt2.xpm");
	game()->left_bt[1].res_x = 30;
	game()->left_bt[1].res_y = 34;	
	game()->right_bt[0] = load_img("textures/buttons/right_bt.xpm");
	game()->right_bt[0].res_x = 30;
	game()->right_bt[0].res_y = 34;
	game()->right_bt[1] = load_img("textures/buttons/right_bt2.xpm");
	game()->right_bt[1].res_x = 30;
	game()->right_bt[1].res_y = 34;	
	game()->diff_bt = load_img("textures/buttons/diff_bt.xpm");
	game()->diff_bt.res_x = 411;
	game()->diff_bt.res_y = 78;
	game()->sens_bt = load_img("textures/buttons/sens_bt.xpm");
	game()->sens_bt.res_x = 411;
	game()->sens_bt.res_y = 78;
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
	game()->mouse.y = 0;
	game()->state = MENU;
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
	init_vid();
	init_vid2();
	game()->mouse.toggle_arrow = mlx_mouse_show(game()->mlx, game()->win); 
	//mlx_mouse_move(game()->mlx, game()->win, 960, 512);
	set_rays(game()->map.map[(int)game()->player.player_y][(int)game()->player.player_x]);
	set_fov(66.0);
	ins_map();
	darken(game()->credits, -0.05);
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
	&temp.bits_per_pixel, &temp.line_length,
	&temp.endian);
	draw_img(&game()->st_anim[0], &temp, 0, 0);
	draw_img(&game()->maze_nm, &temp, 404, 166);
	draw_img(&game()->play_bt[game()->frame.play_tg], &temp, 672, 500);
	draw_img(&game()->option_bt[game()->frame.option_tg], &temp, 672, 666);
	draw_img(&game()->quit_bt[game()->frame.quit_tg], &temp, 672, 831);
	lighten(temp);
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

