/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:42:20 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/11 16:20:44 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_game *nada)
{
	(void)nada;
	int last_x;
	if (keycode == XK_Escape)
		clean_exit(NULL);
	if(game()->state == MENU || game()->state == OPT_M || game()->state == CTRL_M)
		return (0);
	if(game()->state == GAME)
		game_press(keycode);
	else if (keycode == XK_p)
	{
		mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
		mlx_mouse_move(game()->mlx, game()->win, game()->mouse.x, 1070);
		last_x = game()->mouse.x;
		game_move(&last_x);
		game()->state = GAME;
		lighten(game()->canvas, 0.4);
	}
	return (0);
}

void	door_handle(void)
{
	int	var = 0;
	int	var2;
	while(game()->map.map[var])
	{
		var2 = 0;
		while(game()->map.map[var][var2])
		{
			if (game()->map.map[var][var2] >= -57 && game()->map.map[var][var2] < -1)
				game()->map.map[var][var2] += 1;
			else if (game()->map.map[var][var2] == -1)
				game()->map.map[var][var2] = 'O';
			else if (game()->map.map[var][var2] > -126 && game()->map.map[var][var2] <= -71)
				game()->map.map[var][var2] -= 1;
			else if (game()->map.map[var][var2] == -126)
				game()->map.map[var][var2] = 'C';
			var2++;
		}
		var++;
	}
}

void	game_press(int keycode)
{
	if (keycode == XK_p)
		pause_game();
	if (keycode == XK_Shift_L)
		game()->player.sprint = 1;
	if (keycode == XK_d)
		game()->player.moving_d = 1;
	if (keycode == XK_s)
		game()->player.moving_s = 1;
	if (keycode == XK_a)
		game()->player.moving_a = 1;
	if (keycode == XK_e)
		open_door();
	if (keycode == XK_w)
		game()->player.moving_w = 1;
	if(keycode == XK_Right)
		game()->player.rot_r = 1;
	if(keycode == XK_Left)
		game()->player.rot_l = 1;
}

int	key_release(int keycode, t_game *nada)
{
	(void)nada;
	if(game()->state != GAME)
		return (0);
	if (keycode == XK_Shift_L)
		game()->player.sprint = 0;
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
