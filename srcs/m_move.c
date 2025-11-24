/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:40:39 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/19 15:42:14 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	mouse_move_menus(void)
{
	if (game()->state == MENU)
		main_move();
	else if (game()->state == OPT_M)
		opt_m_move();
	else if (game()->state == CTRL_M)
		ctrl_m_move();
	else if (game()->state == PAUSE)
		pause_move();
	else if (game()->state == OPT_P)
		opt_p_move();
	else if (game()->state == CTRL_P)
		ctrl_p_move();
	else if (game()->state == OPT_G)
		opt_g_move();
	else if (game()->state == CTRL_G)
		ctrl_g_move();
}

int	mouse_move(int keycode, t_game *null)
{
	static int	last_x;

	(void)keycode;
	(void)null;
	mouse_move_menus();
	if (game()->state == GAME)
		game_move(&last_x);
	else if (game()->state == G_WIN)
		gwin_move();
	else if (game()->state == G_OVER)
		gover_move();
	last_x = game()->mouse.x;
	return (0);
}

void	game_move(int *last_x)
{
	int	sens;

	mlx_mouse_get_pos(game()->mlx, game()->win,
		&game()->mouse.x, &game()->mouse.y);
	sens = (80 / (game()->frame.sens_tg + 1));
	if (game()->mouse.y >= 1000)
		mlx_mouse_move(game()->mlx, game()->win, game()->mouse.x, 90);
	if (game()->mouse.y <= 80)
		mlx_mouse_move(game()->mlx, game()->win, game()->mouse.x, 990);
	if (game()->mouse.x <= 80)
	{
		mlx_mouse_move(game()->mlx, game()->win, 1830, game()->mouse.y);
		game()->mouse.x = 1830;
		*last_x = 1860;
	}
	if (game()->mouse.x >= 1840)
	{
		mlx_mouse_move(game()->mlx, game()->win, 90, game()->mouse.y);
		game()->mouse.x = 90;
		*last_x = 60;
	}
	if (game()->mouse.x > *last_x)
		rotate_ray((1 + (game()->mouse.x - *last_x)) / sens);
	if (game()->mouse.x < *last_x)
		rotate_ray((-1 - (*last_x - game()->mouse.x)) / sens);
}
