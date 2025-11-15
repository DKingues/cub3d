#include "../includes/cub3d.h"

static void spawn_glitch(int spawn_delay)
{
	long now;

	now = get_elapsed_sec();
	if (now == spawn_delay)
	{
		game()->map.map[(int)game()->player.start_y][(int)game()->player.start_x] = 'G';
		game()->glitch.last_glitch_time = get_time();
		game()->glitch.glitch_spawned = 1;
	}
}

char	**copy_map(char **new_map, char **map_to_copy)
{
	int	y;
	int rows;

	y = 0;
	rows = 0;
	if (!map_to_copy && new_map)
		return (new_map);
	else if(!map_to_copy && !new_map)
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

void glitch_consume(int spawn_delay)
{
	int			x;
	int			y;
	char 		**temp_map;
	long		current_ms;

	x = 0;
	y = 0;
	temp_map = NULL;
	current_ms = get_time();
	if (game()->glitch.glitch_spawned == 0)
		spawn_glitch(spawn_delay);
	else if (current_ms - (game()->glitch.spread_delay * 1000) >= game()->glitch.last_glitch_time)
	{
		temp_map = copy_map(temp_map, game()->map.map);
		while (game()->map.map[y])
		{
			x = 0;
			while (game()->map.map[y][x])
			{
				if (game()->map.map[y][x] == 'G')
				{
					if (game()->map.map[y][x - 1] != '1' && game()->map.map[y][x - 1] != 'G')
						temp_map[y][x - 1] = 'G';
					if (game()->map.map[y - 1][x] != '1' && game()->map.map[y - 1][x] != 'G')
						temp_map[y - 1][x] = 'G';
					if (game()->map.map[y + 1][x] != '1' && game()->map.map[y + 1][x] != 'G')
						temp_map[y + 1][x] = 'G';
					if (game()->map.map[y][x + 1] != '1' && game()->map.map[y][x + 1] != 'G')
						temp_map[y][x + 1] = 'G';
					game()->glitch.last_glitch_time = get_time();
				}
				x++;
			}
			y++;
		}
		game()->map.map = copy_map(game()->map.map, temp_map);
		ft_free(temp_map);
	}
}

