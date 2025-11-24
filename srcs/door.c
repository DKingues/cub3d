/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:15:29 by dicosta-          #+#    #+#             */
/*   Updated: 2025/11/24 15:16:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	open_l(int y, int x)
{
	if (game()->map.map[y][x + 1] == 'L')
	{
		darken(game()->canvas, 1.0, -0.05);
		game()->state = G_WIN;
	}
	else if (game()->map.map[y][x - 1] == 'L')
	{
		darken(game()->canvas, 1.0, -0.05);
		game()->state = G_WIN;
	}
	else if (game()->map.map[y + 1][x] == 'L')
	{
		darken(game()->canvas, 1.0, -0.05);
		game()->state = G_WIN;
	}
	else if (game()->map.map[y - 1][x] == 'L')
	{
		darken(game()->canvas, 1.0, -0.05);
		game()->state = G_WIN;
	}
}

int	open_door(void)
{
	int	y;
	int	x;

	y = game()->player.player_y;
	x = game()->player.player_x;
	open_l(y, x);
	if (game()->map.map[y][x + 1] == 'C')
		game()->map.map[y][x + 1] = -57;
	else if (game()->map.map[y][x - 1] == 'C')
		game()->map.map[y][x - 1] = -57;
	else if (game()->map.map[y + 1][x] == 'C')
		game()->map.map[y + 1][x] = -57;
	else if (game()->map.map[y - 1][x] == 'C')
		game()->map.map[y - 1][x] = -57;
	else if (game()->map.map[y][x + 1] == 'O')
		game()->map.map[y][x + 1] = -71;
	else if (game()->map.map[y][x - 1] == 'O')
		game()->map.map[y][x - 1] = -71;
	else if (game()->map.map[y + 1][x] == 'O')
		game()->map.map[y + 1][x] = -71;
	else if (game()->map.map[y - 1][x] == 'O')
		game()->map.map[y - 1][x] = -71;
	return (1);
}

void	draw_minutes(void)
{
	if (int_size(game()->time.minutes) == 1 && game()->time.minutes != 0)
	{
		draw_img(&game()->timer_nbr[0], &game()->canvas, 875, 23);
		draw_img(&game()->timer_nbr[game()->time.minutes],
			&game()->canvas, 909, 23);
	}
	else if (int_size(game()->time.minutes) == 2)
	{
		draw_img(&game()->timer_nbr[game()->time.minutes / 10],
			&game()->canvas, 875, 23);
		draw_img(&game()->timer_nbr[game()->time.minutes % 10],
			&game()->canvas, 909, 23);
	}
	else if (game()->time.minutes == 0)
	{
		draw_img(&game()->timer_nbr[0], &game()->canvas, 875, 23);
		draw_img(&game()->timer_nbr[0], &game()->canvas, 909, 23);
	}
	else
	{
		draw_img(&game()->timer_nbr[0], &game()->canvas, 875, 23);
		draw_img(&game()->timer_nbr[0], &game()->canvas, 909, 23);
	}
}

void	draw_seconds(void)
{
	if (int_size(game()->time.seconds) == 1 && game()->time.seconds != 0)
	{
		draw_img(&game()->timer_nbr[0], &game()->canvas, 980, 23);
		draw_img(&game()->timer_nbr[game()->time.seconds],
			&game()->canvas, 1017, 23);
	}
	else if (int_size(game()->time.seconds) == 2 && game()->time.seconds != 0)
	{
		draw_img(&game()->timer_nbr[game()->time.seconds / 10],
			&game()->canvas, 980, 23);
		draw_img(&game()->timer_nbr[game()->time.seconds % 10],
			&game()->canvas, 1017, 23);
	}
	else if (game()->time.seconds == 0)
	{
		draw_img(&game()->timer_nbr[0], &game()->canvas, 980, 23);
		draw_img(&game()->timer_nbr[0], &game()->canvas, 1017, 23);
	}
	else
	{
		draw_img(&game()->timer_nbr[0], &game()->canvas, 980, 23);
		draw_img(&game()->timer_nbr[0], &game()->canvas, 1017, 23);
	}
}

void	draw_time(void)
{
	draw_minutes();
	draw_seconds();
}
