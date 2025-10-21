/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:42:20 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/21 17:51:49 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_game *nada)
{
	(void)nada;

	if (keycode == XK_Escape)
		clean_exit(NULL);
	if(game()->state == MENU || game()->state == OPT_M || game()->state == CTRL_M)
		return (0);
	if(game()->state == GAME)
		press_game(keycode);
	else if (keycode == XK_p)
		game()->state = GAME;
	return (0);
}

void	press_game(int keycode)
{
	if (keycode == XK_p)
		pause_game();
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
}

int	key_release(int keycode, t_game *nada)
{
	(void)nada;
	if(game()->state != GAME)
		return (0);
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
