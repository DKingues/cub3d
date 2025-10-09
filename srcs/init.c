/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:42 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/09 18:02:24 by dicosta-         ###   ########.fr       */
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

void init(void)
{
	game()->mlx = mlx_init();
	game()->win = mlx_new_window(game()->mlx, 1920, 1024, "cub3D");
	game()->canvas.img = mlx_new_image(game()->mlx, (1920), (1024));
	game()->wall = load_img("textures/1.xpm");
	game()->floor = load_img("textures/2.xpm");
	game()->person = load_img("textures/3.xpm");
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
	game()->mouse.toggle_arrow = mlx_mouse_show(game()->mlx, game()->win);
	mlx_mouse_move(game()->mlx, game()->win, game()->player.player_x, game()->player.player_y);
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

