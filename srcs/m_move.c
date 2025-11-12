/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:40:39 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/30 16:57:56 by rmota-ma         ###   ########.fr       */
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
	else if (game()->state == G_WIN)
		win_move();
	else if (game()->state == G_OVER)
		gover_move();
	else if (game()->state == OPT_G)
		opt_g_move();
	else if (game()->state == CTRL_G)
		ctrl_g_move();
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
//754, 513
void	pause_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 412 && game()->mouse.y <= 491))
		game()->frame.continue_tg = 1;
	else
		game()->frame.continue_tg = 0;
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 513 && game()->mouse.y <= 593))
		game()->frame.restart_tg = 1;
	else
		game()->frame.restart_tg = 0;
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 613 && game()->mouse.y <= 692))
		game()->frame.option_p_tg = 1;
	else
		game()->frame.option_p_tg = 0;
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 713 && game()->mouse.y <= 793))
		game()->frame.return_menu_tg = 1;
	else
		game()->frame.return_menu_tg = 0;
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 814 && game()->mouse.y <= 894))
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
	int sens;

	sens = (80 / (game()->frame.sens_tg + 1));
	if(game()->mouse.y >= 1000)
		mlx_mouse_move(game()->mlx, game()->win, game()->mouse.x, 90);
	if(game()->mouse.y <= 80)
		mlx_mouse_move(game()->mlx, game()->win, game()->mouse.x, 990);
	if(game()->mouse.x <= 80)
	{
		mlx_mouse_move(game()->mlx, game()->win, 1830, game()->mouse.y);
		game()->mouse.x = 1830;
		*last_x = 1860;
	}
	if(game()->mouse.x >= 1840)
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

void	win_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if ((game()->mouse.y >= 666 && game()->mouse.x >= 754) && (game()->mouse.y <= 744 && game()->mouse.x <= 1165))
		game()->frame.return_menu_tg = 1;
	else
		game()->frame.return_menu_tg = 0;
	if ((game()->mouse.y >= 767 && game()->mouse.x >= 754) && (game()->mouse.y <= 844 && game()->mouse.x <= 1165))
		game()->frame.quit_p_tg = 1;
	else
		game()->frame.quit_p_tg = 0;
}

void	gover_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if ((game()->mouse.y >= 463 && game()->mouse.x >= 764) && (game()->mouse.y <= 542 && game()->mouse.x <= 1165))
		game()->frame.restart_tg = 1;
	else
		game()->frame.restart_tg = 0;
	if ((game()->mouse.y >= 564 && game()->mouse.x >= 764) && (game()->mouse.y <= 642 && game()->mouse.x <= 1165))
		game()->frame.option_p_tg = 1;
	else
		game()->frame.option_p_tg = 0;
	if ((game()->mouse.y >= 664 && game()->mouse.x >= 764) && (game()->mouse.y <= 742 && game()->mouse.x <= 1165))
		game()->frame.return_menu_tg = 1;
	else
		game()->frame.return_menu_tg = 0;
	if ((game()->mouse.y >= 764 && game()->mouse.x >= 764) && (game()->mouse.y <= 842 && game()->mouse.x <= 1165))
		game()->frame.quit_p_tg = 1;
	else
		game()->frame.quit_p_tg = 0;
	
}

void	opt_g_move(void)
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

void	ctrl_g_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if((game()->mouse.x >= 362 && game()->mouse.x <= 1556) && (game()->mouse.y >= 914 && game()->mouse.y <= 992))
		game()->frame.ctrlback_tg = 1;
	else
		game()->frame.ctrlback_tg = 0;
}
