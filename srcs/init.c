/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:42 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/08 17:58:04 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_gameinfo(void)
{
	int	var;

	var = 0;
	game()->info = ft_calloc(7, sizeof(char *));
	while(var < 6)
	{
		game()->info[var] = ft_strdup("init");
		var++;
	}
}

void init(void)
{
	game()->mlx = mlx_init();
	game()->win = mlx_new_window(game()->mlx, 1920, 1024, "cub3d");
	game()->canvas.img = mlx_new_image(game()->mlx, (1920), (1024));
	game()->wall = load_img("textures/1.xpm");
	game()->floor = load_img("textures/2.xpm");
	game()->person = load_img("textures/3.xpm");
	game()->canvas.addr = mlx_get_data_addr(game()->canvas.img,
			&game()->canvas.bits_per_pixel, &game()->canvas.line_length,
			&game()->canvas.endian);
	game()->diff = 0;
	game()->moving_w = 0;
	game()->moving_a = 0;
	game()->moving_s = 0;
	game()->moving_d = 0;
	game()->rot_l = 0;
	game()->rot_r = 0;
	set_rays(game()->map[(int)game()->player.player_y][(int)game()->player.player_x]);
	set_fov(66.0);
}

void	set_rays(char dir)
{
	if (dir == 'N')
	{
		game()->ray_x = 0;
		game()->ray_y = -1;
	}
	else if (dir == 'W')
	{
		game()->ray_x = -1;
		game()->ray_y = 0;
	}
	else if (dir == 'E')
	{
		game()->ray_x = 1;
		game()->ray_y = 0;
	}
	else if (dir == 'S')
	{
		game()->ray_x = 0;
		game()->ray_y = 1;
	}
}

void set_fov(double fov_deg)
{
    double fov_rad = fov_deg * 3.141592653589793 / 180.0;
    double plane_len = tan(fov_rad / 2.0);

    game()->plane_x = -game()->ray_y * plane_len;
    game()->plane_y = game()->ray_x * plane_len;
}

t_game *game(void)
{
	static t_game g;
	
	return (&g);
}

