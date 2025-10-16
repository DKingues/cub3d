/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:24:59 by dicosta-          #+#    #+#             */
/*   Updated: 2025/10/16 16:07:27 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	opt_m_move(void)
{
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if((game()->mouse.x >= 532 && game()->mouse.x <= 1390) && (game()->mouse.y >= 663 && game()->mouse.y <= 743))
		game()->frame.ctrl_tg = 1;
	else
		game()->frame.ctrl_tg = 0;
	if((game()->mouse.x >= 532 && game()->mouse.x <= 1390) && (game()->mouse.y >= 764 && game()->mouse.y <= 844))
		game()->frame.back_tg = 1;
	else
		game()->frame.back_tg = 0;
}

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
		return (0);
	else if(game()->state == PAUSE)
		return (0);
	else if(game()->state == OPT_P)
		return (0);
	else if(game()->state == CTRL_P)
		return (0);
	else if(game()->state == GAME)
		game_move(&last_x);
	last_x = game()->mouse.x;
	//printf("last x = %d, mouse x: %d, mouse y: %d\n", last_x, game()->mouse.x, game()->mouse.y);
	return (0);
}

int	mouse_release(int keycode, t_game *null)
{
	(void)null;
	if(keycode == 3)
		game()->player.rot_r = 0;
	if(keycode == 1)
		game()->player.rot_l = 0;
	return (0);
}