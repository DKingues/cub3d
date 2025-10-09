/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:24:59 by dicosta-          #+#    #+#             */
/*   Updated: 2025/10/09 18:38:49 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_move(int keycode, t_game *null)
{
	static int last_x;

	(void)null;
	mlx_mouse_get_pos(game()->mlx, game()->win, &game()->mouse.x, &game()->mouse.y);
	printf("last x = %d, mouse x: %d, mouse y: %d\n", last_x, game()->mouse.x, game()->mouse.y);
	if (game()->mouse.x > last_x)
		rotate_ray(1);
	if (game()->mouse.x < last_x)
		rotate_ray(-1);
	keycode = keycode;
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