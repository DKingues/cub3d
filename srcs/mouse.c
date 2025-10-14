/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:24:59 by dicosta-          #+#    #+#             */
/*   Updated: 2025/10/14 18:02:30 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_move(int keycode, t_game *null)
{
	static int last_x;

	(void)null;
	(void)keycode;
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	if(game()->paused < 0 || game()->menued)
	{
		last_x = game()->mouse.x;
		return (0);
	}
	if(game()->mouse.y < 1010)
		mlx_mouse_move(game()->mlx, game()->win, game()->mouse.x, 1020);
	if(game()->mouse.x <= 5)
	{
		mlx_mouse_move(game()->mlx, game()->win, 1890, game()->mouse.y);
		game()->mouse.x = 1890;
		last_x = 1920;
	}
	if(game()->mouse.x >= 1915)
	{
		mlx_mouse_move(game()->mlx, game()->win, 30, game()->mouse.y);
		game()->mouse.x = 30;
		last_x = 0;
	}
	printf("last x = %d, mouse x: %d, mouse y: %d\n", last_x, game()->mouse.x, game()->mouse.y);
	if (game()->mouse.x > last_x)
		rotate_ray((1 + (game()->mouse.x - last_x)) / 12);
	if (game()->mouse.x < last_x)
		rotate_ray((-1 - (last_x - game()->mouse.x)) / 12);
	last_x = game()->mouse.x;
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