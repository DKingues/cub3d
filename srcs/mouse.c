/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:24:59 by dicosta-          #+#    #+#             */
/*   Updated: 2025/10/17 17:47:48 by rmota-ma         ###   ########.fr       */
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

float sign (t_cord p1, t_cord p2, t_cord p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

int find_point(t_cord pt, t_cord v1, t_cord v2, t_cord v3)
{
    float d1, d2, d3;
    int has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
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
	if((game()->mouse.x >= 413 && game()->mouse.x <= 1508) && (game()->mouse.y >= 823 && game()->mouse.y <= 901))
		game()->frame.ctrlback_tg = 1;
	else
		game()->frame.ctrlback_tg = 0;
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
		ctrl_m_move();
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