/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:03:34 by dicosta-          #+#    #+#             */
/*   Updated: 2025/11/19 17:17:50 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	w_move(int change)
{
	double	x;
	double	y;
	float	player_x;
	float	player_y;

	player_x = game()->player.player_x;
	player_y = game()->player.player_y;
	if (game()->player.moving_w == 1)
	{
		x = player_x + (game()->raycast.ray_x / change);
		y = player_y + (game()->raycast.ray_y / change);
		change_pos(x, y);
	}
}

void	a_move(int change)
{
	double	x;
	double	y;
	float	player_x;
	float	player_y;

	player_x = game()->player.player_x;
	player_y = game()->player.player_y;
	if (game()->player.moving_a == 1)
	{
		x = (player_x) + (((game()->raycast.ray_y)) / ((change)));
		y = (player_y) + (((game()->raycast.ray_x) * -1) / ((change)));
		change_pos(x, y);
	}
}

void	s_move(int change)
{
	double	x;
	double	y;
	float	player_x;
	float	player_y;

	player_x = game()->player.player_x;
	player_y = game()->player.player_y;
	if (game()->player.moving_s == 1)
	{
		x = (player_x) + (((game()->raycast.ray_x) * -1) / ((change)));
		y = (player_y) + (((game()->raycast.ray_y) * -1) / ((change)));
		change_pos(x, y);
	}
}

void	d_move(int change)
{
	double	x;
	double	y;
	float	player_x;
	float	player_y;

	player_x = game()->player.player_x;
	player_y = game()->player.player_y;
	if (game()->player.moving_d == 1)
	{
		x = (player_x) + (((game()->raycast.ray_y) * -1) / ((change)));
		y = (player_y) + (((game()->raycast.ray_x)) / ((change)));
		change_pos(x, y);
	}
}
