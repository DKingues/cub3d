/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_press.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:43:00 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/21 11:03:15 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_checks(void *nada, int keycode)
{
	(void) nada;
	if (keycode != 1)
		return (0);
	game()->release++;
	if (game()->release > 1)
		game()->release = 0;
	return (1);
}

int	mouse_press(int keycode, void *nada)
{
	if (!mouse_checks(nada, keycode))
		return (0);
	if (game()->release)
		return (0);
	else if (game()->state == MENU)
		main_press(0, 0);
	else if (game()->state == OPT_M)
		opt_m_press();
	else if (game()->state == CTRL_M)
		ctrl_m_press();
	else if (game()->state == PAUSE)
		pause_press();
	else if (game()->state == OPT_P)
		opt_p_press();
	else if (game()->state == CTRL_P)
		ctrl_p_press();
	else if (game()->state == G_WIN)
		win_press();
	else if (game()->state == G_OVER)
		gover_press();
	else if (game()->state == OPT_G)
		opt_g_press();
	else if (game()->state == CTRL_G)
		ctrl_g_press();
	return (0);
}

void	pause_press2(void)
{
	if ((game()->mouse.x >= 754 && game()->mouse.x <= 1164)
		&& (game()->mouse.y >= 613 && game()->mouse.y <= 692))
	{
		opt_p_move();
		game()->state = OPT_P;
	}
	if ((game()->mouse.x >= 754 && game()->mouse.x <= 1164)
		&& (game()->mouse.y >= 713 && game()->mouse.y <= 793))
	{
		darken(game()->canvas, 0.4, -0.05);
		mlx_clear_window(game()->mlx, game()->win);
		lighten(game()->st_anim[game()->frame.anim_tg], 0.0);
		main_move();
		reset_map();
		reinit();
		game()->state = MENU;
	}
	if ((game()->mouse.x >= 754 && game()->mouse.x <= 1164)
		&& (game()->mouse.y >= 814 && game()->mouse.y <= 894))
		clean_exit(NULL);
}

void	*pause_press(void)
{
	int	last_x;

	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
		&game()->mouse.y);
	if ((game()->mouse.x >= 754 && game()->mouse.x <= 1164)
		&& (game()->mouse.y >= 412 && game()->mouse.y <= 491))
	{
		mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
			&game()->mouse.y);
		mlx_mouse_move(game()->mlx, game()->win, game()->mouse.x, 1070);
		last_x = game()->mouse.x;
		game_move(&last_x);
		return (game()->state = GAME, lighten(game()->canvas, 0.4), NULL);
	}
	if ((game()->mouse.x >= 754 && game()->mouse.x <= 1164)
		&& (game()->mouse.y >= 513 && game()->mouse.y <= 593))
	{
		darken(game()->canvas, 0.4, -0.05);
		mlx_clear_window(game()->mlx, game()->win);
		game_move(&last_x);
		reset_map();
		return (reinit(), ft_usleep(15000), lighten(game()->canvas, 0),
			game()->state = GAME, NULL);
	}
	return (pause_press2(), NULL);
}

int	pause_game(void)
{
	pause_move();
	darken(game()->canvas, 1.0, 0.40);
	game()->state = PAUSE;
	game()->player.moving_w = 0;
	game()->player.moving_a = 0;
	game()->player.moving_s = 0;
	game()->player.moving_d = 0;
	game()->player.rot_r = 0;
	game()->player.rot_l = 0;
	return (0);
}
