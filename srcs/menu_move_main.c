/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 20:27:21 by dicosta-          #+#    #+#             */
/*   Updated: 2025-11-24 20:27:21 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	main_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win,
		&game()->mouse.x, &game()->mouse.y);
	if ((game()->mouse.x >= 672 && game()->mouse.x <= 1248)
		&& (game()->mouse.y >= 500 && game()->mouse.y <= 616))
		game()->frame.play_tg = 1;
	else
		game()->frame.play_tg = 0;
	if ((game()->mouse.x >= 672 && game()->mouse.x <= 1248)
		&& (game()->mouse.y >= 666 && game()->mouse.y <= 782))
		game()->frame.option_tg = 1;
	else
		game()->frame.option_tg = 0;
	if ((game()->mouse.x >= 672 && game()->mouse.x <= 1248)
		&& (game()->mouse.y >= 832 && game()->mouse.y <= 948))
		game()->frame.quit_tg = 1;
	else
		game()->frame.quit_tg = 0;
}

static void	opt_m_move2(t_cord pos)
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

void	opt_m_move(void)
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
	opt_m_move2(pos);
}

void	ctrl_m_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win,
		&game()->mouse.x, &game()->mouse.y);
	if ((game()->mouse.x >= 362 && game()->mouse.x <= 1556)
		&& (game()->mouse.y >= 914 && game()->mouse.y <= 992))
		game()->frame.ctrlback_tg = 1;
	else
		game()->frame.ctrlback_tg = 0;
}
