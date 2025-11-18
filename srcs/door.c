/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:15:29 by dicosta-          #+#    #+#             */
/*   Updated: 2025/11/18 18:45:40 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int open_door(void)
{
	int y;
	int x;
	
	y = game()->player.player_y;
	x = game()->player.player_x;
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
	else if (game()->map.map[y][x + 1] == 'C')
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

int int_size(long time)
{
	int i = 0;
	while (time > 0)
	{
		time /= 10;
		i++;
	}
	return (i);
}

int timer(long start, int timer)
{
	struct timeval	curr;
	long current;
	int remaining;
	
	current = 0;
	remaining = 0;
	gettimeofday(&curr, NULL);
	current = curr.tv_sec;
	remaining = timer - (current - start) + game()->time.pause_time;
	game()->time.minutes = remaining / 60;
	game()->time.seconds = remaining % 60;
	return (0);
}

void    draw_time(void)
{
    if (int_size(game()->time.minutes) == 1 && game()->time.minutes != 0)
    {
        draw_img(&game()->timer_nbr[0], &game()->canvas, 875, 23, 1.0);
        draw_img(&game()->timer_nbr[game()->time.minutes], &game()->canvas, 909, 23, 1.0);
    }
    else if (int_size(game()->time.minutes) == 2)
    {
        draw_img(&game()->timer_nbr[game()->time.minutes / 10], &game()->canvas, 875, 23, 1.0);
        draw_img(&game()->timer_nbr[game()->time.minutes % 10], &game()->canvas, 909, 23, 1.0);
    }
    else if (game()->time.minutes == 0)
    {
        draw_img(&game()->timer_nbr[0], &game()->canvas, 875, 23, 1.0);
        draw_img(&game()->timer_nbr[0], &game()->canvas, 909, 23, 1.0);
    }
    else
    {
        draw_img(&game()->timer_nbr[0], &game()->canvas, 875, 23, 1.0);
        draw_img(&game()->timer_nbr[0], &game()->canvas, 909, 23, 1.0);
    }
    if (int_size(game()->time.seconds) == 1 && game()->time.seconds != 0)
    {
        draw_img(&game()->timer_nbr[0], &game()->canvas, 980 , 23, 1.0);
        draw_img(&game()->timer_nbr[game()->time.seconds], &game()->canvas, 1017, 23, 1.0);
    }
    else if (int_size(game()->time.seconds) == 2 && game()->time.seconds != 0 )
    {
        draw_img(&game()->timer_nbr[game()->time.seconds / 10], &game()->canvas, 980, 23, 1.0);
        draw_img(&game()->timer_nbr[game()->time.seconds % 10], &game()->canvas, 1017, 23, 1.0);
    }
    else if (game()->time.seconds == 0)
    {
        draw_img(&game()->timer_nbr[0], &game()->canvas, 980, 23, 1.0);
        draw_img(&game()->timer_nbr[0], &game()->canvas, 1017, 23, 1.0);
    }
    else
    {
        draw_img(&game()->timer_nbr[0], &game()->canvas, 980, 23, 1.0);
        draw_img(&game()->timer_nbr[0], &game()->canvas, 1017, 23, 1.0);
    }
}

