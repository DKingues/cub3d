/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:26:50 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/15 16:40:36 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main_menu(int keycode, void *nada)
{
	int	mx;
	int	my;

	mx = 0;
	my = 0;
	(void)nada;
	if(!game()->menued)
	{
		if(game()->paused < 0)
			pause_menu(keycode, NULL);
		return (0);
	}
	mlx_mouse_get_pos(game()->mlx, game()->win, &mx, &my);
	if((game()->mouse.x >= 672 && game()->mouse.x <= 1248) && (game()->mouse.y >= 500 && game()->mouse.y <= 616) && keycode == 1)//trocar cordenadas de acordo com botoes
	{
		darken(game()->st_anim[game()->frame]);
		game()->play_tg = 0;
		lighten(game()->canvas);
		game()->menued = 0;
	}
	if((game()->mouse.x >= 672 && game()->mouse.x <= 1248) && (game()->mouse.y >= 832 && game()->mouse.y <= 948) && keycode == 1)//trocar cordenadas de acordo com botoes
		clean_exit(NULL);
	//printf("mouse x: %d, mouse y: %d, menued: %d, keycode: %d\n", mx, my, game()->menued, keycode);
	return (0);
}

int pause_menu(int keycode, void *nada)
{
	int	mx;
	int	my;

	mx = 0;
	my = 0;
	(void)nada;
	if(game()->paused > 0 || keycode != 1)
		return (0);
	mlx_mouse_get_pos(game()->mlx, game()->win, &mx, &my);
	if((mx >= 0 && mx <= 960) && (my >= 0 && my <= 512))//trocar cordenadas de acordo com botoes
	{
		game()->paused *= -1;
		pause_game();
	}
	else if((mx >= 960 && mx <= 1920) && (my >= 512 && my <= 1024))//trocar cordenadas de acordo com botoes
	{
		game()->paused *= -1;
		lighten(game()->st_anim[game()->frame]);
		game()->menued = 1;
	}
	else if((mx >= 960 && mx <= 1920) && (my >= 0 && my <= 512))//trocar cordenadas de acordo com botoes
	{
		game()->optioned *= -1;
		if(game()->optioned < 0)
			lighten(game()->options);
		else
			darken(game()->options);
		//option_menu();
	}
	//printf("mouse x: %d, mouse y: %d, menued: %d, keycode: %d\n", mx, my, game()->menued, keycode);
	return (0);
}