/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:07:44 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/14 18:41:44 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
#include "../includes/cub3d.h"

void gameplay(void)
{
	game()->var = 0;
	//mlx_put_image_to_window(game()->mlx, game()->win, game()->st_anim[0].img, 0, 0);
	//mlx_put_image_to_window(game()->mlx, game()->win, game()->menu.img, 0, 0);
	mlx_loop_hook(game()->mlx, vid_put, NULL);
	mlx_loop(game()->mlx);
	/* ins_map();
	mlx_mouse_hook(game()->win, main_menu, NULL);
	mlx_hook(game()->win, 2, 1L<<0, press, NULL);
	mlx_hook(game()->win, 6, 1L<<6, mouse_move, NULL);
	mlx_hook(game()->win, 3, 1L<<1, release, NULL);
	mlx_hook(game()->win, 17, 0, clean_exit, NULL);
	mlx_loop_hook(game()->mlx, move, NULL);
	mlx_loop(game()->mlx); */
}

int	vid_put(int keycode, void *nada)
{
	(void)keycode;
	(void)nada;
	printf("VAR:%d\n", game()->var);
	if(game()->var == 167)
		game()->var = 0;
	mlx_put_image_to_window(game()->mlx, game()->win, game()->st_anim[game()->var].img, 0, 0);
	game()->var++;
	usleep(15000);
	return 0;
}

int	move(void *nada)
{
	float change;

	(void)nada;
	change = 0.05;
	/* if(game()->menued)
		vid_put(0, NULL); */
	if(game()->paused < 0 || game()->menued)
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
	game()->canvas.img = mlx_new_image(game()->mlx, (1920), (1024));
	game()->canvas.addr = mlx_get_data_addr(game()->canvas.img,
			&game()->canvas.bits_per_pixel, &game()->canvas.line_length,
			&game()->canvas.endian);
	ins_map();
	if(game()->paused > 0)
		mlx_put_image_to_window(game()->mlx, game()->win, game()->canvas.img, 0, 0);
	return (0);
}

int	press(int keycode, t_game *nada)
{
	(void)nada;

	if (keycode == XK_Escape)
		clean_exit(NULL);
	if(game()->menued)
		return (0);
	if (keycode == XK_p)
	{
		game()->paused *= -1;
		pause_game();
		mlx_mouse_move(game()->mlx, game()->win, 960, 512);
	}
	if(game()->paused < 0)
		return (0);
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
	return 0;
}

int	release(int keycode, t_game *nada)
{
	(void)nada;
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
