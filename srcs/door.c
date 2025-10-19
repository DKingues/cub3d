/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:15:29 by dicosta-          #+#    #+#             */
/*   Updated: 2025/10/18 21:35:21 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int open_door(void)
{
	int y;
	int x;
	
	y = game()->player.player_y;
	x = game()->player.player_x;
	if (game()->map.map[y][x + 1] == 'C')
		game()->map.map[y][x + 1] = 'O';
	else if (game()->map.map[y][x - 1] == 'C')
		game()->map.map[y][x - 1] = 'O';
	else if (game()->map.map[y + 1][x] == 'C')
		game()->map.map[y + 1][x] = 'O';
	else if (game()->map.map[y - 1][x] == 'C')
		game()->map.map[y - 1][x] = 'O';
	else if (game()->map.map[y][x + 1] == 'O')
		game()->map.map[y][x + 1] = 'C';
	else if (game()->map.map[y][x - 1] == 'O')
		game()->map.map[y][x - 1] = 'C';
	else if (game()->map.map[y + 1][x] == 'O')
		game()->map.map[y + 1][x] = 'C';
	else if (game()->map.map[y - 1][x] == 'O')
		game()->map.map[y - 1][x] = 'C';
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
	int seconds;
	int minute;

	current = 0;
	remaining = 0;
	gettimeofday(&curr, NULL);
	current = curr.tv_sec;
	remaining = timer - (current - start);
	minute = remaining / 60;
	seconds = remaining % 60;
	
	if (int_size(seconds) > 1)
		printf("%d:%d\n", minute, seconds);
	else
		printf("%d:0%d\n", minute, seconds);
	return (0);
}
