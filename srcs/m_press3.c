/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_press3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:54:22 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/20 18:55:06 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	win_press(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
		&game()->mouse.y);
	if ((game()->mouse.y >= 666 && game()->mouse.x >= 754)
		&& (game()->mouse.y <= 744 && game()->mouse.x <= 1165))
	{
		reset_map();
		game()->state = MENU;
	}
	if ((game()->mouse.y >= 767 && game()->mouse.x >= 754)
		&& (game()->mouse.y <= 844 && game()->mouse.x <= 1165))
		clean_exit(NULL);
}

void	*gover_press(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
		&game()->mouse.y);
	if ((game()->mouse.y >= 463 && game()->mouse.x >= 764)
		&& (game()->mouse.y <= 542 && game()->mouse.x <= 1165))
	{
		darken(game()->canvas, 0.4, -0.05);
		mlx_clear_window(game()->mlx, game()->win);
		return (reset_map(), reinit(), lighten(game()->canvas, 0.0),
			game()->state = GAME, NULL);
	}
	if ((game()->mouse.y >= 564 && game()->mouse.x >= 764)
		&& (game()->mouse.y <= 642 && game()->mouse.x <= 1165))
		game()->state = OPT_G;
	if ((game()->mouse.y >= 664 && game()->mouse.x >= 764)
		&& (game()->mouse.y <= 742 && game()->mouse.x <= 1165))
	{
		darken(game()->canvas, 0.4, -0.05);
		mlx_clear_window(game()->mlx, game()->win);
		lighten(game()->st_anim[game()->frame.anim_tg], 0.0);
		return (main_move(), reset_map(), reinit(), game()->state = MENU, NULL);
	}
	if ((game()->mouse.y >= 764 && game()->mouse.x >= 764)
		&& (game()->mouse.y <= 842 && game()->mouse.x <= 1165))
		clean_exit(NULL);
	return (NULL);
}

void	ctrl_g_press(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
		&game()->mouse.y);
	if ((game()->mouse.x >= 362 && game()->mouse.x <= 1556)
		&& (game()->mouse.y >= 914 && game()->mouse.y <= 992))
	{
		opt_m_move();
		game()->state = OPT_G;
	}
}

void	*opt_g_press(void)
{
	t_cord	pos;

	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x,
		&game()->mouse.y);
	pos.x = game()->mouse.x;
	pos.y = game()->mouse.y;
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1387)
		&& (game()->mouse.y >= 663 && game()->mouse.y <= 743))
		return (ctrl_m_move(), game()->state = CTRL_G, NULL);
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1387)
		&& (game()->mouse.y >= 764 && game()->mouse.y <= 843))
		return (gover_move(), game()->state = G_OVER, NULL);
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
