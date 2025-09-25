/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:54 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/16 18:23:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	int var = 0;
	while(game()->map[var])
	{
		printf("map %s", game()->map[var]);
		var++;
	}
	var = 0;
	while(game()->info[var])
	{
		printf("info %s&\n", game()->info[var]);
		var++;
	}
	var = 0;
	while(game()->map_F[var])
	{
		printf("map_F %s&\n", game()->map_F[var]);
		var++;
	}
	var = 0;
	while(game()->map_C[var])
	{
		printf("map_C %s&\n", game()->map_C[var]);
		var++;
	}
	singleton_free();
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

