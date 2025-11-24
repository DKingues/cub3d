/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 20:12:41 by dicosta-          #+#    #+#             */
/*   Updated: 2025-11-24 20:12:41 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_wall(double x, double y)
{
	return (game()->map.map[(int)y][(int)x] == '1'
		|| game()->map.map[(int)y][(int)x] == 'C'
		|| game()->map.map[(int)y][(int)x] == 'L'
		|| (game()->map.map[(int)y][(int)x] < -28
		&& game()->map.map[(int)y][(int)x] > -57)
		|| game()->map.map[(int)y][(int)x] < -70);
}

int	is_wall_radius(double x, double y)
{
	double	r;

	r = 0.05;
	if (is_wall(x + r, y))
		return (1);
	if (is_wall(x - r, y))
		return (1);
	if (is_wall(x, y + r))
		return (1);
	if (is_wall(x, y - r))
		return (1);
	if (is_wall(x + r, y + r))
		return (1);
	if (is_wall(x - r, y + r))
		return (1);
	if (is_wall(x + r, y - r))
		return (1);
	if (is_wall(x - r, y - r))
		return (1);
	return (0);
}

void	change_pos(double x, double y)
{
	if (!is_wall_radius(x, game()->player.player_y)
		&& !is_wall_radius(game()->player.player_x, y))
	{
		game()->player.player_x = x;
		game()->player.player_y = y;
	}
	else if (!is_wall_radius(x, game()->player.player_y))
		game()->player.player_x = x;
	else if (!is_wall_radius(game()->player.player_x, y))
		game()->player.player_y = y;
}
