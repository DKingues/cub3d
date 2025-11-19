/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:54 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/19 16:27:43 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	reset_map(void)
{
	int	var;

	var = 0;
	while(game()->map.orig[var])
		var++;
	ft_free(game()->map.map);
	game()->map.map = ft_calloc(sizeof(char **), var + 1);
	var = 0;
	while(game()->map.orig[var])
	{
		game()->map.map[var] = ft_strdup(game()->map.orig[var]);
		var++;
	}
}

void	orig_map(void)
{
	int	var;

	var = 0;
	while(game()->map.map[var])
		var++;
	game()->map.orig = ft_calloc(sizeof(char **), var + 1);
	var = 0;
	while(game()->map.map[var])
	{
		game()->map.orig[var] = ft_strdup(game()->map.map[var]);
		var++;
	}
}

void	rewrite_map(void)
{
	int	var;
	int	var2;

	var2 = 0;
	while(game()->map.map[var2])
	{
		var = 0;
		while(game()->map.map[var2][var])
		{
			if (game()->map.map[var2][var] == 'o')
				game()->map.map[var2][var] = '0';
			if (game()->map.map[var2][var] == 'c')
				game()->map.map[var2][var] -= 32;
			if (game()->map.map[var2][var] == 'l')
				game()->map.map[var2][var] -= 32;
			if (game()->map.map[var2][var] == 'n' || game()->map.map[var2][var] == 's' || game()->map.map[var2][var] == 'e' || game()->map.map[var2][var] == 'w')
			{
				game()->map.map[var2][var] -= 32;
				game()->player.start_x = var + 0.5;
				game()->player.start_y = var2 + 0.5;
			}
			var++;
		}
		var2++;
	}
}

int	fill2(int x, int y)
{
	if (x < 0 || y < 0 || y > game()->map.max_y || !game()->map.map[y][x] || game()->map.map[y][x] == '\n'|| game()->map.map[y][x] == ' ')
		return (1);
	if ((game()->map.map[y][x] == 'l') || (game()->map.map[y][x] == 'c') || (game()->map.map[y][x] == 'o') || (game()->map.map[y][x] == '1') || (game()->map.map[y][x] == 'e') || (game()->map.map[y][x] == 'w') || (game()->map.map[y][x] == 'n') || (game()->map.map[y][x] == 's'))
		return (0);
	if (game()->map.map[y][x] == 'C')
		game()->map.map[y][x] = 'c';
	else if (game()->map.map[y][x] == '0')
		game()->map.map[y][x] = 'o';
	else if (game()->map.map[y][x] == 'N')
		game()->map.map[y][x] = 'n';
	else if (game()->map.map[y][x] == 'E')
		game()->map.map[y][x] = 'e';
	else if (game()->map.map[y][x] == 'W')
		game()->map.map[y][x] = 'w';
	else if (game()->map.map[y][x] == 'S')
		game()->map.map[y][x] = 's';
	else if (game()->map.map[y][x] == 'L')
		game()->map.map[y][x] = 'l';
	fill2((x - 1), y);
	fill2((x + 1), y);
	fill2(x, (y - 1));
	fill2(x, (y + 1));
	return (0);
}

int check_map2(void)
{
	int var = 0, var2 = 0;
	while(game()->map.map[var])
	{
		var2 = 0;
		while(game()->map.map[var][var2])
		{
			if (game()->map.map[var][var2] == 'N' || game()->map.map[var][var2] == 'W' || game()->map.map[var][var2] == 'E' || game()->map.map[var][var2] == 'S')
				return (printf("Error\nThe exit is unaccessible\n"), singleton_free(1), exit(1), 1);
			var2++;
		}
		var++;
	}
	return (0);
}

int parsing(char **av)
{
	if (map_exists(av[1]))
		return (printf("Error\nThe map doesn't exist.\n"), 1);
	if (map_name(av[1]))
		return (printf("Error\nThe map extension isn't valid. It should be a \".cub\".\n"), 1);
	if (map_validate(av[1]))
		return (1);
	if (map_textures())
		return(1);
	if (map_colors())
		return (1);
	if (map_chars(av[1]))
		return (1);
	if (map_walls(av[1]))
        return(1);
	rewrite_map();
	int var = 0, var2 = 0;
	while(game()->map.map[var])
	{
		var2 = 0;
		while(game()->map.map[var][var2])
		{
			if (game()->map.map[var][var2] == 'L')
			{
				fill2(var2, var);
				break ;
			}
			var2++;
		}
		var++;
	}
	check_map2();
	rewrite_map();
	orig_map();
	/* int var = 0;
	while(game()->map.info[var])
	{
		printf("Error\nGAME()->INFO: %s\n", game()->map.info[var]);
		var++;
	}
	var = 0;
	while(game()->map.map_F[var])
	{
		printf("Error\nGAME()->map_F: %s\n", game()->map.map_F[var]);
		var++;
	}
	var = 0;
	while(game()->map.map_C[var])
	{
		printf("Error\nGAME()->map_C: %s\n", game()->map.map_C[var]);
		var++;
	} */
    return(0);
}

int map_exists(char *av)
{
    int fd;

    fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
    return (0);
}

int map_name(char *av)
{
    int var;

    var = 0;
    while(av[var])
        var++;
    var--;
    if(av[var] != 'b')
        return (1);
    var--;
    if(av[var] != 'u')
        return (1);
    var--;
    if(av[var] != 'c')
        return (1);
    var--;
    if(av[var] != '.')
        return (1);
    return (0);
}

