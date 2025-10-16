/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:26:50 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/16 15:49:34 by rmota-ma         ###   ########.fr       */
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
		lighten(game()->canvas);
		game()->state = GAME;
	}
	else if((game()->mouse.x >= 672 && game()->mouse.x <= 1248) && (game()->mouse.y >= 666 && game()->mouse.y <= 782))
	{
		game()->st_anim = game()->st_anim2;
		darken(game()->st_anim[game()->frame.anim_tg], 0.5);
		game()->frame.option_tg = 1;
		game()->state = OPT_M;
	}
	else if((game()->mouse.x >= 672 && game()->mouse.x <= 1248) && (game()->mouse.y >= 832 && game()->mouse.y <= 948))//trocar cordenadas de acordo com botoes
		clean_exit(NULL);
}

void	main_options(void)
{
	// draw_img(&game()->option_bt[game()->frame.option_tg], &game()->st_anim[game()->frame.anim_tg], 672, 234);
	// draw_img(&game()->diff_bt, &game()->st_anim[game()->frame.anim_tg], 531, 562);
	// //draw_img(&game()->play_bt[game()->frame.play_tg], &game()->st_anim[game()->frame.anim_tg], 672, 500);
	// //draw_img(&game()->quit_bt[game()->frame.quit_tg], &game()->st_anim[game()->frame.anim_tg], 672, 831);
	// mlx_put_image_to_window(game()->mlx, game()->win, game()->st_anim[game()->frame.anim_tg].img, 0, 0);
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
		return (0);
	else if(game()->state == PAUSE)
		return (0);
	else if(game()->state == OPT_P)
		return (0);
	else if(game()->state == CTRL_P)
		return (0);
	else if(game()->state == GAME)
		return (0);
	//printf("mouse x: %d, mouse y: %d, menued: %d, keycode: %d\n", mx, my, game()->state == MENU, keycode);
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
		lighten(game()->st_anim[game()->frame.anim_tg]);
		game()->state = MENU;
	}
	else if((mx >= 960 && mx <= 1920) && (my >= 0 && my <= 512))//trocar cordenadas de acordo com botoes
	{
		//option_menu();
	}
	//printf("mouse x: %d, mouse y: %d, menued: %d, keycode: %d\n", mx, my, game()->state == MENU, keycode);
	return (0);
}