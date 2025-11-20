/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_press2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:49:34 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/20 18:54:06 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	main_press(int mx)
{
	int my;

	my = 0;
	mx = 0;
	mlx_mouse_get_pos(game()->mlx, game()->win, &mx, &my);
	if ((game()->mouse.x >= 672 && game()->mouse.x <= 1248)
		&& (game()->mouse.y >= 500 && game()->mouse.y <= 616))
	{
		mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
			&game()->mouse.y);
		mlx_mouse_move(game()->mlx, game()->win, game()->mouse.x, 1070);
		mx = game()->mouse.x;
		game_move(&mx);
		darken(game()->st_anim[game()->frame.anim_tg], 1.0, -0.05);
		game()->frame.play_tg = 0;
		reinit();
		lighten(game()->canvas, 0.0);
		game()->state = GAME;
	}
	else if ((game()->mouse.x >= 672 && game()->mouse.x <= 1248)
		&& (game()->mouse.y >= 666 && game()->mouse.y <= 782))
	{
		opt_m_move();
		game()->state = OPT_M;
	}
	else if ((game()->mouse.x >= 672 && game()->mouse.x <= 1248)
		&& (game()->mouse.y >= 832 && game()->mouse.y <= 948))
		clean_exit(NULL);
}

void	*opt_m_press(void)
{
	t_cord	pos;

	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
		&game()->mouse.y);
	pos.x = game()->mouse.x;
	pos.y = game()->mouse.y;
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1387)
		&& (game()->mouse.y >= 663 && game()->mouse.y <= 743))
		return (ctrl_m_move(), game()->state = CTRL_M, NULL);
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1387)
		&& (game()->mouse.y >= 764 && game()->mouse.y <= 843))
		return (main_move(), game()->state = MENU, NULL);
	if (find_point(pos, game()->sleft_c[0], game()->sleft_c[1],
			game()->sleft_c[2]) && game()->frame.sens_tg != 0)
		game()->frame.sens_tg--;
	if (find_point(pos, game()->sright_c[0], game()->sright_c[1],
			game()->sright_c[2]) && game()->frame.sens_tg != 4)
		game()->frame.sens_tg++;
	if (find_point(pos, game()->dleft_c[0], game()->dleft_c[1],
			game()->dleft_c[2]) && game()->frame.diff_tg != 0)
		game()->frame.diff_tg--;
	if (find_point(pos, game()->dright_c[0], game()->dright_c[1],
			game()->dright_c[2]) && game()->frame.diff_tg != 2)
		game()->frame.diff_tg++;
	return (NULL);
}

void	ctrl_m_press(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
		&game()->mouse.y);
	if ((game()->mouse.x >= 362 && game()->mouse.x <= 1556)
		&& (game()->mouse.y >= 914 && game()->mouse.y <= 992))
	{
		opt_m_move();
		game()->state = OPT_M;
	}
}

void	opt_p_press(void)
{
	t_cord	pos;

	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
		&game()->mouse.y);
	pos.x = game()->mouse.x;
	pos.y = game()->mouse.y;
	if ((game()->mouse.x >= 531 && game()->mouse.x <= 1389)
		&& (game()->mouse.y >= 612 && game()->mouse.y <= 692))
	{
		ctrl_p_move();
		game()->state = CTRL_P;
	}
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1390)
		&& (game()->mouse.y >= 713 && game()->mouse.y <= 793))
	{
		pause_move();
		game()->state = PAUSE;
	}
	if (find_point(pos, game()->sleft_pause_c[0], game()->sleft_pause_c[1],
			game()->sleft_pause_c[2]) && game()->frame.sens_tg != 0)
		game()->frame.sens_tg--;
	if (find_point(pos, game()->sright_pause_c[0], game()->sright_pause_c[1],
			game()->sright_pause_c[2]) && game()->frame.sens_tg != 4)
		game()->frame.sens_tg++;
}

void	ctrl_p_press(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
		&game()->mouse.y);
	if ((game()->mouse.x >= 362 && game()->mouse.x <= 1556)
		&& (game()->mouse.y >= 914 && game()->mouse.y <= 992))
	{
		opt_p_move();
		game()->state = OPT_P;
	}
}
