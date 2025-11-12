/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-12 20:03:34 by dicosta-          #+#    #+#             */
/*   Updated: 2025-11-12 20:03:34 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    w_move(int  change)
{
	if (game()->player.moving_w == 1)
	{
		if(!check_radius('w', change))
		{
			game()->player.player_x = game()->player.player_x + (game()->raycast.ray_x / change);
			game()->player.player_y = game()->player.player_y + (game()->raycast.ray_y / change);
		}
	}
}

void    a_move(int change)
{
    if (game()->player.moving_a == 1)
	{
		double x = (game()->player.player_x) + (((game()->raycast.ray_y + 0.05)) / ((change)));
		double y = (game()->player.player_y) + (((game()->raycast.ray_x + 0.05) * -1) / ((change)));
		if(!check_radius('a', change) && game()->map.map[(int)y][(int)x] != '1' && game()->map.map[(int)y][(int)x] != 'C' && game()->map.map[(int)y][(int)x] != 'L' && game()->map.map[(int)y][(int)x] > 0)
		{
			game()->player.player_x = x;
			game()->player.player_y = y;
		}
	}
}

void    s_move(int change)
{
    if (game()->player.moving_s == 1)
	{
		if(!check_radius('s', change))
		{
			game()->player.player_x = (game()->player.player_x) + (((game()->raycast.ray_x + 0.05) * -1) / ((change)));
			game()->player.player_y = (game()->player.player_y) + (((game()->raycast.ray_y + 0.05) * -1) / ((change)));
		}
	}
}

void    d_move(int change)
{
    if (game()->player.moving_d == 1)
	{
		double x = (game()->player.player_x) + (((game()->raycast.ray_y + 0.05) * -1) / ((change)));
		double y = (game()->player.player_y) + (((game()->raycast.ray_x + 0.05)) / ((change)));
		if(!check_radius('d', change) && game()->map.map[(int)y][(int)x] != '1' && game()->map.map[(int)y][(int)x] != 'C' && game()->map.map[(int)y][(int)x] != 'L' && game()->map.map[(int)y][(int)x] > 0)
		{
			game()->player.player_x = x;
			game()->player.player_y = y;
		}
	}
}
