/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:54 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/23 15:26:39 by rmota-ma         ###   ########.fr       */
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

int parsing(char **av)
{
	
	if (map_exists(av[1]))
		return (printf("The map doesn't exist.\n"), 1);
	if (map_name(av[1]))
		return (printf("The map extension isn't valid. It should be a \".cub\".\n"), 1);
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
	orig_map();
	/* int var = 0;
	while(game()->map.info[var])
	{
		printf("GAME()->INFO: %s\n", game()->map.info[var]);
		var++;
	}
	var = 0;
	while(game()->map.map_F[var])
	{
		printf("GAME()->map_F: %s\n", game()->map.map_F[var]);
		var++;
	}
	var = 0;
	while(game()->map.map_C[var])
	{
		printf("GAME()->map_C: %s\n", game()->map.map_C[var]);
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

