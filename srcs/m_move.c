/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:40:39 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/22 16:49:55 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_move(int keycode, t_game *null)
{
	static int last_x;

	(void)null;
	(void)keycode;

	if(game()->state == MENU)
		main_move();
	else if(game()->state == OPT_M)
		opt_m_move();
	else if(game()->state == CTRL_M)
		ctrl_m_move();
	else if(game()->state == PAUSE)
		pause_move();
	else if(game()->state == OPT_P)
		opt_p_move();
	else if(game()->state == CTRL_P)
		ctrl_p_move();
	else if(game()->state == GAME)
		game_move(&last_x);
	last_x = game()->mouse.x;
	//printf("last x = %d, mouse x: %d, mouse y: %d\n", last_x, game()->mouse.x, game()->mouse.y);
	return (0);
}

void	main_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if((game()->mouse.x >= 672 && game()->mouse.x <= 1248) && (game()->mouse.y >= 500 && game()->mouse.y <= 616))
		game()->frame.play_tg = 1;
	else
		game()->frame.play_tg = 0;
	if((game()->mouse.x >= 672 && game()->mouse.x <= 1248) && (game()->mouse.y >= 666 && game()->mouse.y <= 782))
		game()->frame.option_tg = 1;
	else
		game()->frame.option_tg = 0;
	if((game()->mouse.x >= 672 && game()->mouse.x <= 1248) && (game()->mouse.y >= 832 && game()->mouse.y <= 948))
		game()->frame.quit_tg = 1;
	else
		game()->frame.quit_tg = 0;
}

void	opt_m_move(void)
{
	t_cord	pos;
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	pos.x = game()->mouse.x;
	pos.y = game()->mouse.y;
	if((game()->mouse.x >= 532 && game()->mouse.x <= 1390) && (game()->mouse.y >= 663 && game()->mouse.y <= 743))
		game()->frame.ctrl_tg = 1;
	else
		game()->frame.ctrl_tg = 0;
	if((game()->mouse.x >= 532 && game()->mouse.x <= 1390) && (game()->mouse.y >= 764 && game()->mouse.y <= 844))
		game()->frame.back_tg = 1;
	else
		game()->frame.back_tg = 0;
	if(find_point(pos, game()->sleft_c[0], game()->sleft_c[1], game()->sleft_c[2]))
		game()->frame.sleft_tg = 1;
	else
		game()->frame.sleft_tg = 0;

	if(find_point(pos, game()->sright_c[0], game()->sright_c[1], game()->sright_c[2]))
		game()->frame.sright_tg = 1;
	else
		game()->frame.sright_tg = 0;

	if(find_point(pos, game()->dleft_c[0], game()->dleft_c[1], game()->dleft_c[2]))
		game()->frame.dleft_tg = 1;
	else
		game()->frame.dleft_tg = 0;

	if(find_point(pos, game()->dright_c[0], game()->dright_c[1], game()->dright_c[2]))
		game()->frame.dright_tg = 1;
	else
		game()->frame.dright_tg = 0;
		
}

void	ctrl_m_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if((game()->mouse.x >= 362 && game()->mouse.x <= 1556) && (game()->mouse.y >= 914 && game()->mouse.y <= 992))
		game()->frame.ctrlback_tg = 1;
	else
		game()->frame.ctrlback_tg = 0;
}

void	pause_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 463 && game()->mouse.y <= 542))
		game()->frame.continue_tg = 1;
	else
		game()->frame.continue_tg = 0;
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 563 && game()->mouse.y <= 641))
		game()->frame.option_p_tg = 1;
	else
		game()->frame.option_p_tg = 0;
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 664 && game()->mouse.y <= 743))
		game()->frame.return_menu_tg = 1;
	else
		game()->frame.return_menu_tg = 0;
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 764 && game()->mouse.y <= 843))
		game()->frame.quit_p_tg = 1;
	else
		game()->frame.quit_p_tg = 0;
}

void	opt_p_move(void)
{
	t_cord	pos;
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	pos.x = game()->mouse.x;
	pos.y = game()->mouse.y;
	if((game()->mouse.x >= 531 && game()->mouse.x <= 1389) && (game()->mouse.y >= 612 && game()->mouse.y <= 692))
		game()->frame.ctrl_tg = 1;
	else
		game()->frame.ctrl_tg = 0;
	if((game()->mouse.x >= 532 && game()->mouse.x <= 1390) && (game()->mouse.y >= 713 && game()->mouse.y <= 793))
		game()->frame.back_tg = 1;
	else
		game()->frame.back_tg = 0;
	if(find_point(pos, game()->sleft_pause_c[0], game()->sleft_pause_c[1], game()->sleft_pause_c[2]))
		game()->frame.sleft_tg = 1;
	else
		game()->frame.sleft_tg = 0;

	if(find_point(pos, game()->sright_pause_c[0], game()->sright_pause_c[1], game()->sright_pause_c[2]))
		game()->frame.sright_tg = 1;
	else
		game()->frame.sright_tg = 0;

}

void	ctrl_p_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if((game()->mouse.x >= 362 && game()->mouse.x <= 1556) && (game()->mouse.y >= 914 && game()->mouse.y <= 992))
		game()->frame.ctrlback_tg = 1;
	else
		game()->frame.ctrlback_tg = 0;
}

void	game_move(int *last_x)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if(game()->mouse.y < 1010)
		mlx_mouse_move(game()->mlx, game()->win, game()->mouse.x, 1020);
	if(game()->mouse.x <= 5)
	{
		mlx_mouse_move(game()->mlx, game()->win, 1890, game()->mouse.y);
		game()->mouse.x = 1890;
		*last_x = 1920;
	}
	if(game()->mouse.x >= 1915)
	{
		mlx_mouse_move(game()->mlx, game()->win, 30, game()->mouse.y);
		game()->mouse.x = 30;
		*last_x = 0;
	}
	if (game()->mouse.x > *last_x)
		rotate_ray((1 + (game()->mouse.x - *last_x)) / 12);
	if (game()->mouse.x < *last_x)
		rotate_ray((-1 - (*last_x - game()->mouse.x)) / 12);
}
