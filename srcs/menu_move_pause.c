/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_menu_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 20:29:31 by dicosta-          #+#    #+#             */
/*   Updated: 2025-11-24 20:29:31 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	pause_move2(void)
{
	if ((game()->mouse.x >= 754 && game()->mouse.x <= 1164)
		&& (game()->mouse.y >= 613 && game()->mouse.y <= 692))
		game()->frame.option_p_tg = 1;
	else
		game()->frame.option_p_tg = 0;
	if ((game()->mouse.x >= 754 && game()->mouse.x <= 1164)
		&& (game()->mouse.y >= 713 && game()->mouse.y <= 793))
		game()->frame.return_menu_tg = 1;
	else
		game()->frame.return_menu_tg = 0;
	if ((game()->mouse.x >= 754 && game()->mouse.x <= 1164)
		&& (game()->mouse.y >= 814 && game()->mouse.y <= 894))
		game()->frame.quit_p_tg = 1;
	else
		game()->frame.quit_p_tg = 0;
}

void	pause_move(void)
{
	mlx_mouse_get_pos(game()->mlx,
		game()->win, &game()->mouse.x, &game()->mouse.y);
	if ((game()->mouse.x >= 754 && game()->mouse.x <= 1164)
		&& (game()->mouse.y >= 412 && game()->mouse.y <= 491))
		game()->frame.continue_tg = 1;
	else
		game()->frame.continue_tg = 0;
	if ((game()->mouse.x >= 754 && game()->mouse.x <= 1164)
		&& (game()->mouse.y >= 513 && game()->mouse.y <= 593))
		game()->frame.restart_tg = 1;
	else
		game()->frame.restart_tg = 0;
	pause_move2();
}

static void	opt_p_move2(t_cord pos)
{
	if (find_point(pos, game()->sleft_pause_c[0],
			game()->sleft_pause_c[1], game()->sleft_pause_c[2]))
		game()->frame.sleft_tg = 1;
	else
		game()->frame.sleft_tg = 0;
	if (find_point(pos, game()->sright_pause_c[0],
			game()->sright_pause_c[1], game()->sright_pause_c[2]))
		game()->frame.sright_tg = 1;
	else
		game()->frame.sright_tg = 0;
}

void	opt_p_move(void)
{
	t_cord	pos;

	mlx_mouse_get_pos(game()->mlx, game()->win,
		&game()->mouse.x, &game()->mouse.y);
	pos.x = game()->mouse.x;
	pos.y = game()->mouse.y;
	if ((game()->mouse.x >= 531 && game()->mouse.x <= 1389)
		&& (game()->mouse.y >= 612 && game()->mouse.y <= 692))
		game()->frame.ctrl_tg = 1;
	else
		game()->frame.ctrl_tg = 0;
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1390)
		&& (game()->mouse.y >= 713 && game()->mouse.y <= 793))
		game()->frame.back_tg = 1;
	else
		game()->frame.back_tg = 0;
	opt_p_move2(pos);
}

void	ctrl_p_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win,
		&game()->mouse.x, &game()->mouse.y);
	if ((game()->mouse.x >= 362 && game()->mouse.x <= 1556)
		&& (game()->mouse.y >= 914 && game()->mouse.y <= 992))
		game()->frame.ctrlback_tg = 1;
	else
		game()->frame.ctrlback_tg = 0;
}
