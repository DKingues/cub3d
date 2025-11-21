/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:54 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/21 11:16:53 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	reset_map(void)
{
	int		var;
	char	**line;

	var = 0;
	while (game()->map.orig[var])
		var++;
	ft_free(game()->map.map);
	line = ft_calloc(sizeof(char **), var + 1);
	game()->map.map = line;
	var = 0;
	while (game()->map.orig[var])
	{
		game()->map.map[var] = ft_strdup(game()->map.orig[var]);
		var++;
	}
}

void	orig_map(void)
{
	int		var;
	char	**line;

	var = 0;
	while (game()->map.map[var])
		var++;
	line = ft_calloc(sizeof(char **), var + 1);
	game()->map.orig = line;
	var = 0;
	while (game()->map.map[var])
	{
		game()->map.orig[var] = ft_strdup(game()->map.map[var]);
		var++;
	}
}

int	parsing(char **av)
{
	int	var;
	int	var2;

	var = 0;
	var2 = 0;
	if (map_exists(av[1]))
		return (printf("Error\nThe map doesn't exist.\n"), 1);
	if (map_name(av[1]))
		return (printf("Error\nThe map extension isn't valid. \
			It should be a \".cub\".\n"), 1);
	if (map_validate(av[1], 0, 0, NULL))
		return (printf("Error\nThe map file information is missing.\n"), 1);
	if (map_textures() || map_colors() || map_chars(av[1], 0, 0, 0)
		|| map_walls(av[1]))
		return (1);
	rewrite_map(0, 0);
	find_exit(var, var2);
	check_map2();
	rewrite_map(0, 0);
	orig_map();
	return (0);
}

int	map_exists(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	map_name(char *av)
{
	int	var;

	var = 0;
	while (av[var])
		var++;
	var--;
	if (av[var] != 'b')
		return (1);
	var--;
	if (av[var] != 'u')
		return (1);
	var--;
	if (av[var] != 'c')
		return (1);
	var--;
	if (av[var] != '.')
		return (1);
	return (0);
}
