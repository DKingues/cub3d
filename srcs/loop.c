/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:37:00 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/24 15:06:18 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	main_menu(void)
{
	if (game()->state == MENU)
		menu_put(0, NULL);
	else if (game()->state == OPT_M)
		opt_m_put();
	else if (game()->state == CTRL_M)
		ctrl_m_put();
}

void	pause_menu(void)
{
	struct timeval	start;

	if (game()->state == PAUSE)
	{
		if (game()->time.pause_time_start == -1)
		{
			gettimeofday(&start, NULL);
			game()->time.pause_time_start = start.tv_sec;
		}
		pause_put();
	}
	else if (game()->state == OPT_P)
		opt_p_put();
	else if (game()->state == CTRL_P)
		ctrl_p_put();
}

void	endgame_menu(void)
{
	if (game()->state == G_OVER)
		g_over_put();
	else if (game()->state == G_WIN)
		g_win_put();
	else if (game()->state == OPT_G)
		opt_g_put();
	else if (game()->state == CTRL_G)
		ctrl_g_put();
}

void	game_menu(void)
{
	struct timeval	start;
	long			paused_for;

	if (game()->state == GAME)
	{
		if (FS == 1)
			mlx_mouse_hide(game()->mlx, game()->win);
		if (game()->time.level_start == -1)
		{
			gettimeofday(&start, NULL);
			game()->time.level_start = start.tv_sec;
		}
		if (game()->time.pause_time_start != -1)
		{
			gettimeofday(&start, NULL);
			paused_for = start.tv_sec - game()->time.pause_time_start;
			game()->time.pause_time += paused_for;
			game()->time.pause_time_start = -1;
		}
		game_loop(18);
	}
}

int	loop(void *nada)
{
	(void)nada;
	if (game()->state != GAME && FS == 1)
		mlx_mouse_show(game()->mlx, game()->win);
	main_menu();
	pause_menu();
	game_menu();
	endgame_menu();
	return (0);
}
