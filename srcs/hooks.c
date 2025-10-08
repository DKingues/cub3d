/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:07:44 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/08 17:51:57 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void run(void)
{
	t_game *nada;

	nada = NULL;
	ins_map();
	mlx_loop_hook(game()->mlx, move, nada);
	mlx_hook(game()->win, 2, 1L<<0, press, NULL);
	mlx_hook(game()->win, 3, 1L<<1, release, NULL);
	mlx_loop(game()->mlx);
}

int	move(t_game *nada)
{
	(void)nada;
	float change = 0.05;
	if(game()->diff == 1)
		change = 0.1;
	if (game()->moving_d == 1 && game()->map[(int)(game()->player.player_y)][(int)(game()->player.player_x + 0.1)] != '1')
		game()->player.player_x += change;
	if (game()->moving_s == 1 && game()->map[(int)(game()->player.player_y + 0.1)][(int)game()->player.player_x] != '1')
		game()->player.player_y += change;
	if (game()->moving_a == 1 && game()->map[(int)(game()->player.player_y)][(int)(game()->player.player_x - 0.1)] != '1')
		game()->player.player_x -= change;
	if (game()->moving_w == 1 && game()->map[(int)(game()->player.player_y - 0.1)][(int)game()->player.player_x] != '1')
		game()->player.player_y -= change;
	if(game()->rot_l == 1)
		rotate_ray(-1);
	if(game()->rot_r == 1)
		rotate_ray(1);
	mlx_destroy_image(game()->mlx, game()->canvas.img);
	game()->canvas.img = mlx_new_image(game()->mlx, (1920), (1024));
	game()->canvas.addr = mlx_get_data_addr(game()->canvas.img,
			&game()->canvas.bits_per_pixel, &game()->canvas.line_length,
			&game()->canvas.endian);	
	ins_map();
	mlx_put_image_to_window(game()->mlx, game()->win, game()->canvas.img, 0, 0);
	return 0;
}

int	press(int keycode, t_game *nada)
{
	(void)nada;
	if (keycode == XK_Shift_L)
		game()->diff = 1;
	if (keycode == XK_Escape)
		exit(0);
	if (keycode == XK_d)
	{
		game()->moving_d = 1;
	}
	if (keycode == XK_s)
	{
		game()->moving_s = 1;
	}
	if (keycode == XK_a)
	{
		game()->moving_a = 1;
	}
	if (keycode == XK_w)
	{
		game()->moving_w = 1;
	}
	if(keycode == XK_Right)
	{
		game()->rot_r = 1;
	}
	if(keycode == XK_Left)
	{
		game()->rot_l = 1;
	}
	return 0;
}

int	release(int keycode, t_game *nada)
{
	(void)nada;
	if (keycode == XK_Shift_L)
		game()->diff = 0;
	if (keycode == XK_d)
	{
		game()->moving_d = 0;
	}
	if (keycode == XK_s)
	{
		game()->moving_s = 0;
	}
	if (keycode == XK_a)
	{
		game()->moving_a = 0;
	}
	if (keycode == XK_w)
	{
		game()->moving_w = 0;
	}
	if(keycode == XK_Right)
	{
		game()->rot_r = 0;
	}
	if(keycode == XK_Left)
	{
		game()->rot_l = 0;
	}
	return 0;
}
