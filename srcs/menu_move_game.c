/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_move_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 20:33:20 by dicosta-          #+#    #+#             */
/*   Updated: 2025-11-24 20:33:20 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	gwin_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win,
		&game()->mouse.x, &game()->mouse.y);
	if ((game()->mouse.y >= 666 && game()->mouse.x >= 754)
		&& (game()->mouse.y <= 744 && game()->mouse.x <= 1165))
		game()->frame.return_menu_tg = 1;
	else
		game()->frame.return_menu_tg = 0;
	if ((game()->mouse.y >= 767 && game()->mouse.x >= 754)
		&& (game()->mouse.y <= 844 && game()->mouse.x <= 1165))
		game()->frame.quit_p_tg = 1;
	else
		game()->frame.quit_p_tg = 0;
}

void	gover_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win,
		&game()->mouse.x, &game()->mouse.y);
	if ((game()->mouse.y >= 463 && game()->mouse.x >= 764)
		&& (game()->mouse.y <= 542 && game()->mouse.x <= 1165))
		game()->frame.restart_tg = 1;
	else
		game()->frame.restart_tg = 0;
	if ((game()->mouse.y >= 564 && game()->mouse.x >= 764)
		&& (game()->mouse.y <= 642 && game()->mouse.x <= 1165))
		game()->frame.option_p_tg = 1;
	else
		game()->frame.option_p_tg = 0;
	if ((game()->mouse.y >= 664 && game()->mouse.x >= 764)
		&& (game()->mouse.y <= 742 && game()->mouse.x <= 1165))
		game()->frame.return_menu_tg = 1;
	else
		game()->frame.return_menu_tg = 0;
	if ((game()->mouse.y >= 764 && game()->mouse.x >= 764)
		&& (game()->mouse.y <= 842 && game()->mouse.x <= 1165))
		game()->frame.quit_p_tg = 1;
	else
		game()->frame.quit_p_tg = 0;
}

static void	opt_g_move_2(t_cord pos)
{
	if (find_point(pos, game()->sright_c[0],
			game()->sright_c[1], game()->sright_c[2]))
		game()->frame.sright_tg = 1;
	else
		game()->frame.sright_tg = 0;
	if (find_point(pos, game()->dleft_c[0],
			game()->dleft_c[1], game()->dleft_c[2]))
		game()->frame.dleft_tg = 1;
	else
		game()->frame.dleft_tg = 0;
	if (find_point(pos, game()->dright_c[0],
			game()->dright_c[1], game()->dright_c[2]))
		game()->frame.dright_tg = 1;
	else
		game()->frame.dright_tg = 0;
}

void	opt_g_move(void)
{
	t_cord	pos;

	mlx_mouse_get_pos(game()->mlx, game()->win,
		&game()->mouse.x, &game()->mouse.y);
	pos.x = game()->mouse.x;
	pos.y = game()->mouse.y;
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1390)
		&& (game()->mouse.y >= 663 && game()->mouse.y <= 743))
		game()->frame.ctrl_tg = 1;
	else
		game()->frame.ctrl_tg = 0;
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1390)
		&& (game()->mouse.y >= 764 && game()->mouse.y <= 844))
		game()->frame.back_tg = 1;
	else
		game()->frame.back_tg = 0;
	if (find_point(pos, game()->sleft_c[0],
			game()->sleft_c[1], game()->sleft_c[2]))
		game()->frame.sleft_tg = 1;
	else
		game()->frame.sleft_tg = 0;
	opt_g_move_2(pos);
}

void	ctrl_g_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
		&game()->mouse.y);
	if ((game()->mouse.x >= 362 && game()->mouse.x <= 1556)
		&& (game()->mouse.y >= 914 && game()->mouse.y <= 992))
		game()->frame.ctrlback_tg = 1;
	else
		game()->frame.ctrlback_tg = 0;
}
