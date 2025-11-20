/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glitch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-20 22:27:58 by dicosta-          #+#    #+#             */
/*   Updated: 2025-11-20 22:27:58 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	spawn_glitch(int spawn_delay)
{
	long	now;
	int		start_y;
	int		start_x;

	now = get_elapsed_sec();
	start_y = game()->player.start_y;
	start_x = game()->player.start_x;
	if (now == spawn_delay)
	{
		game()->map.map[start_y][start_x] = 'G';
		game()->glitch.last_glitch_time = get_elapsed_sec();
		game()->glitch.glitch_spawned = 1;
	}
}

char	**copy_map(char **new_map, char **map_to_copy)
{
	int	y;
	int	rows;

	y = 0;
	rows = 0;
	if (!map_to_copy && new_map)
		return (new_map);
	else if (!map_to_copy && !new_map)
		return (NULL);
	if (new_map)
		ft_free(new_map);
	while (map_to_copy[rows])
		rows++;
	new_map = ft_calloc(sizeof(char *), rows + 1);
	while (map_to_copy[y])
	{
		new_map[y] = ft_strdup(map_to_copy[y]);
		y++;
	}
	return (new_map);
}

static void	glitch_consume_block(char **temp_map, int y, int x)
{
	if (game()->map.map[y][x - 1] != '1' &&
		game()->map.map[y][x - 1] != 'G' &&
		game()->map.map[y][x - 1] != 'L')
		temp_map[y][x - 1] = 'G';
	if (game()->map.map[y - 1][x] != '1' &&
		game()->map.map[y - 1][x] != 'G' &&
		game()->map.map[y - 1][x] != 'L')
		temp_map[y - 1][x] = 'G';
	if (game()->map.map[y + 1][x] != '1' &&
		game()->map.map[y + 1][x] != 'G' &&
		game()->map.map[y + 1][x] != 'L')
		temp_map[y + 1][x] = 'G';
	if (game()->map.map[y][x + 1] != '1' &&
		game()->map.map[y][x + 1] != 'G' &&
		game()->map.map[y][x + 1] != 'L')
		temp_map[y][x + 1] = 'G';
	game()->glitch.last_glitch_time = get_elapsed_sec()
	- game()->time.pause_time;
}

static void	glitch_consume_loop(char **temp_map)
{
	int	y;
	int	x;

	y = 0;
	while (game()->map.map[y])
	{
		x = 0;
		while (game()->map.map[y][x])
		{
			if (game()->map.map[y][x] == 'G')
				glitch_consume_block(temp_map, y, x);
			x++;
		}
		y++;
	}
}

void	glitch_consume(int spawn_delay)
{
	char	**temp_map;

	temp_map = NULL;
	if (game()->glitch.glitch_spawned == 0)
		spawn_glitch(spawn_delay);
	else if ((get_elapsed_sec() - game()->glitch.spread_delay)
		- game()->time.pause_time >= game()->glitch.last_glitch_time)
	{
		temp_map = copy_map(temp_map, game()->map.map);
		glitch_consume_loop(temp_map);
		game()->map.map = copy_map(game()->map.map, temp_map);
		ft_free(temp_map);
	}
}
