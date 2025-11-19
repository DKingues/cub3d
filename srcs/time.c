/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:10:20 by dicosta-          #+#    #+#             */
/*   Updated: 2025/11/19 16:52:00 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

long get_elapsed_sec(void)
{
	struct timeval current;

	if (gettimeofday(&current, NULL))
		return (0);
	return (current.tv_sec - game()->time.level_start);
}

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * (long)1e3 + (tv.tv_usec / 1e3));
}

int	count_zero(char **map)
{
	int	blocks_to_glitch;
	int y;
	int x;

	blocks_to_glitch = 0;
	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'O' || map[y][x] == 'C')
				blocks_to_glitch++;
			x++;
		}
		y++;
	}
	return (blocks_to_glitch);
}

int	count_zero_r(char **temp_map, int y, int x)
{
	int count;

	count = 1;
	if (temp_map[y][x] == '0' || temp_map[y][x] == 'C' || temp_map[y][x] == 'O' || temp_map[y][x] == 'N'
	 || temp_map[y][x] == 'S' || temp_map[y][x] == 'E' || temp_map[y][x] == 'W')
	{
		temp_map[y][x] = '-';
		if (temp_map[y][x + 1] != '1')
			count += count_zero_r(temp_map, y, x + 1);
		if (temp_map[y + 1][x] != '1')
			count += count_zero_r(temp_map, y + 1, x);
		if (temp_map[y][x - 1] != '1')
			count += count_zero_r(temp_map, y, x - 1);
		if (temp_map[y - 1][x] != '1')
			count += count_zero_r(temp_map, y - 1, x);
		return (count);
	}
	return (0);
}

int 	glitched_tiles(char **temp_map)
{
	int y;
	int x;
	int	g_counter;

	y = 0;
	x = 0;
	g_counter = 0;
	while (temp_map[y])
	{
		x = 0;
		while (temp_map[y][x])
		{
			if (temp_map[y][x] == 'G')
				g_counter++;
			x++;
		}
		y++;
	}
	return (g_counter);
}

int	tt_glitch_map(void)
{
	int	x;
	int	y;
	char	**temp_map;
	char	**temp_map2;

	x = 0;
	y = 0;
	temp_map = NULL;
	temp_map2 = NULL;
	temp_map2 = copy_map(temp_map2, game()->map.map);
	temp_map2[(int)game()->player.start_y][(int)game()->player.start_x] = 'G';
	game()->glitch.glitch_i = 0;
	while (game()->glitch.to_glitch - glitched_tiles(temp_map2) > 0)
	{
		temp_map = copy_map(temp_map, temp_map2);
		y = 0;
		while (temp_map2[y])
		{
			x = 0;
			while (temp_map2[y][x])
			{
				if (temp_map2[y][x] == 'G')
				{
					if (temp_map2[y][x - 1] != 'L' &&temp_map2[y][x - 1] != '1' && temp_map2[y][x - 1] != 'G')
						temp_map[y][x - 1] = 'G';
					if (temp_map2[y - 1][x] != 'L' && temp_map2[y - 1][x] != '1' && temp_map2[y - 1][x] != 'G')
						temp_map[y - 1][x] = 'G';
					if (temp_map2[y + 1][x] != 'L' && temp_map2[y + 1][x] != '1' && temp_map2[y + 1][x] != 'G')
						temp_map[y + 1][x] = 'G';
					if (temp_map2[y][x + 1] != 'L' && temp_map2[y][x + 1] != '1' && temp_map2[y][x + 1] != 'G')
						temp_map[y][x + 1] = 'G';
				}
				x++;
			}
			y++;
		}
		game()->glitch.glitch_i++;
		temp_map2 = copy_map(temp_map2, temp_map);
	}
	if (temp_map)
		ft_free(temp_map);
	if (temp_map2)
		ft_free(temp_map2);
	return ((game()->glitch.glitch_i * game()->glitch.spread_delay) + 4);
}
