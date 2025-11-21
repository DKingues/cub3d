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

long	get_elapsed_sec(void)
{
	struct timeval	current;

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

int	count_zero_r(char **temp_map, int y, int x)
{
	int	count;

	count = 1;
	if (temp_map[y][x] == '0' || temp_map[y][x] == 'C' ||
		temp_map[y][x] == 'O' || temp_map[y][x] == 'N' ||
		temp_map[y][x] == 'S' || temp_map[y][x] == 'E' || temp_map[y][x] == 'W')
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

int	glitched_tiles(char **temp_map)
{
	int	y;
	int	x;
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

static void	tt_glitch_map_block(char **temp_map, char **temp_map2, int y, int x)
{
	if (temp_map2[y][x - 1] != 'L' &&
		temp_map2[y][x - 1] != '1' && temp_map2[y][x - 1] != 'G')
		temp_map[y][x - 1] = 'G';
	if (temp_map2[y - 1][x] != 'L' &&
		temp_map2[y - 1][x] != '1' && temp_map2[y - 1][x] != 'G')
		temp_map[y - 1][x] = 'G';
	if (temp_map2[y + 1][x] != 'L' &&
		temp_map2[y + 1][x] != '1' && temp_map2[y + 1][x] != 'G')
		temp_map[y + 1][x] = 'G';
	if (temp_map2[y][x + 1] != 'L' &&
		temp_map2[y][x + 1] != '1' && temp_map2[y][x + 1] != 'G')
		temp_map[y][x + 1] = 'G';
}

static void	tt_glitch_map_loop(char **temp_map, char**temp_map2)
{
	int	y;
	int	x;

	y = 0;
	while (temp_map2[y])
	{
		x = 0;
		while (temp_map2[y][x])
		{
			if (temp_map2[y][x] == 'G')
				tt_glitch_map_block(temp_map, temp_map2, y, x);
			x++;
		}
		y++;
	}
}

int	tt_glitch_map(void)
{
	char	**temp_map;
	char	**temp_map2;
	int		x;
	int		y;

	temp_map = NULL;
	x = 0;
	y = 0;
	temp_map2 = copy_map(game()->map.map);
	temp_map2[(int)game()->player.start_y][(int)game()->player.start_x] = 'G';
	game()->glitch.glitch_i = 0;
	while (game()->glitch.to_glitch - glitched_tiles(temp_map2) > 0)
	{
		ft_free(temp_map);
		temp_map = copy_map(temp_map2);
		tt_glitch_map_loop(temp_map, temp_map2);
		game()->glitch.glitch_i++;
		ft_free(temp_map2);
		temp_map2 = copy_map(temp_map);
	}
	if (temp_map)
		ft_free(temp_map);
	if (temp_map2)
		ft_free(temp_map2);
	return ((game()->glitch.glitch_i * game()->glitch.spread_delay) + 4);
}
