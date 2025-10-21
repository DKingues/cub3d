/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_press.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:43:00 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/21 17:44:01 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	main_menu(void)
{
	int	mx;
	int	my;

	mx = 0;
	my = 0;
	mlx_mouse_get_pos(game()->mlx, game()->win, &mx, &my);
	if((game()->mouse.x >= 672 && game()->mouse.x <= 1248) && (game()->mouse.y >= 500 && game()->mouse.y <= 616))//trocar cordenadas de acordo com botoes
	{
		darken(game()->st_anim[game()->frame.anim_tg], -0.05);
		game()->frame.play_tg = 0;
		lighten(game()->canvas, 0.0);
		game()->state = GAME;
	}
	else if((game()->mouse.x >= 672 && game()->mouse.x <= 1248) && (game()->mouse.y >= 666 && game()->mouse.y <= 782))
	{
		opt_m_move();
		game()->state = OPT_M;
	}
	else if((game()->mouse.x >= 672 && game()->mouse.x <= 1248) && (game()->mouse.y >= 832 && game()->mouse.y <= 948))//trocar cordenadas de acordo com botoes
		clean_exit(NULL);
}

void	main_options(void)
{
	t_cord	pos;
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	pos.x = game()->mouse.x;
	pos.y = game()->mouse.y;
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1387) && (game()->mouse.y >= 764 && game()->mouse.y <= 843))
	{
		main_move();
		game()->state = MENU;
	}
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1387) && (game()->mouse.y >= 663 && game()->mouse.y <= 743))
	{
		ctrl_m_move();
		game()->state = CTRL_M;
	}
	if(find_point(pos, game()->sleft_c[0], game()->sleft_c[1], game()->sleft_c[2]))
		if(game()->frame.sens_tg != 0)
			game()->frame.sens_tg--;
	if(find_point(pos, game()->sright_c[0], game()->sright_c[1], game()->sright_c[2]))
		if(game()->frame.sens_tg != 4)
			game()->frame.sens_tg++;
	if(find_point(pos, game()->dleft_c[0], game()->dleft_c[1], game()->dleft_c[2]))
		if(game()->frame.diff_tg != 0)
			game()->frame.diff_tg--;
	if(find_point(pos, game()->dright_c[0], game()->dright_c[1], game()->dright_c[2]))
		if(game()->frame.diff_tg != 2)
			game()->frame.diff_tg++;
}

void	ctrl_m_opt(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	
	if ((game()->mouse.x >= 413 && game()->mouse.x <= 1508) && (game()->mouse.y >= 823 && game()->mouse.y <= 901))
	{
		opt_m_move();
		game()->state = OPT_M;
	}
}

void	pause_options(void)
{
	t_cord	pos;
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	pos.x = game()->mouse.x;
	pos.y = game()->mouse.y;
	/* if ((game()->mouse.x >= 532 && game()->mouse.x <= 1387) && (game()->mouse.y >= 764 && game()->mouse.y <= 843))
	{
		main_move();
		game()->state = MENU;
	}
	if ((game()->mouse.x >= 532 && game()->mouse.x <= 1387) && (game()->mouse.y >= 663 && game()->mouse.y <= 743))
	{
		ctrl_m_move();
		game()->state = CTRL_M;
	} */
	if(find_point(pos, game()->sleft_pause_c[0], game()->sleft_pause_c[1], game()->sleft_pause_c[2]))
		if(game()->frame.sens_tg != 0)
			game()->frame.sens_tg--;
	if(find_point(pos, game()->sright_pause_c[0], game()->sright_pause_c[1], game()->sright_pause_c[2]))
		if(game()->frame.sens_tg != 4)
			game()->frame.sens_tg++;
}

void	pause_menu_g(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 512 && game()->mouse.y <= 590))
		game()->state = GAME;
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 612 && game()->mouse.y <= 690))
		game()->state = OPT_P;
	if((game()->mouse.x >= 754 && game()->mouse.x <= 1164) && (game()->mouse.y >= 712 && game()->mouse.y <= 790))
		clean_exit(NULL);
}

int	mouse_press(int keycode, void *nada)
{
	(void)nada;

	if(keycode != 1)
		return (0);
	else if(game()->state == MENU)
		main_menu();
	else if(game()->state == OPT_M)
		main_options();
	else if(game()->state == CTRL_M)
		ctrl_m_opt();
	else if(game()->state == PAUSE)
		pause_menu_g();
	else if(game()->state == OPT_P)
		pause_options();
	else if(game()->state == CTRL_P)
		return (0);
	else if(game()->state == GAME)
		return (0);
	//printf("mouse x: %d, mouse y: %d, menued: %d, keycode: %d\n", mx, my, game()->state == MENU, keycode);
	return (0);
}

int	pause_game(void)
{
	darken(game()->canvas, 0.40);
	game()->state = PAUSE;
	game()->player.moving_w = 0;
	game()->player.moving_a = 0;
	game()->player.moving_s = 0;
	game()->player.moving_d = 0;
	game()->player.rot_r = 0;
	game()->player.rot_l = 0;
	return (0);
}

int pause_menu(int keycode, void *nada)
{
	int	mx;
	int	my;

	mx = 0;
	my = 0;
	(void)nada;
	if(keycode != 1)
		return (0);
	mlx_mouse_get_pos(game()->mlx, game()->win, &mx, &my);
	if((mx >= 0 && mx <= 960) && (my >= 0 && my <= 512))//trocar cordenadas de acordo com botoes
	{
		pause_game();
	}
	else if((mx >= 960 && mx <= 1920) && (my >= 512 && my <= 1024))//trocar cordenadas de acordo com botoes
	{
		lighten(game()->st_anim[game()->frame.anim_tg], 0.0);
		game()->state = MENU;
	}
	else if((mx >= 960 && mx <= 1920) && (my >= 0 && my <= 512))//trocar cordenadas de acordo com botoes
	{
		//option_menu();
	}
	//printf("mouse x: %d, mouse y: %d, menued: %d, keycode: %d\n", mx, my, game()->state == MENU, keycode);
	return (0);
}