/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:24:40 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/19 15:42:14 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_validate(char *av)
{
	char	*line;
	int		var;
	int		fd;
	char **check;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	check = ft_calloc(7, sizeof(char *));
	init_gameinfo();
	check[0] = ft_strdup("NO ");
	check[1] = ft_strdup("SO ");
	check[2] = ft_strdup("WE ");
	check[3] = ft_strdup("EA ");
	check[4] = ft_strdup("F ");
	check[5] = ft_strdup("C ");
	line = get_next_line(fd);
	int var2;
	while(line && check[0])
	{
		var = 0;
		if(line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		while(check[var])
		{
			if(!ft_strncmp(line, check[var], ft_strlen(check[var])))
			{
				var2 = 0;
				set_gameinfo(line);
				if (check[var + 1])
				{
					free(check[var]);
					while (check[var + var2])
						var2++;
					var2--;
					check[var] = ft_strdup(check[var + var2]);
					free(check[var + var2]);
					check[var + var2] = NULL;
				}
				else
				{
					free(check[var]);
					check[var] = NULL;
				}
				var = -1;
				break ;
			}
			var++;
		}
		if (var != -1)
			break ;
		free(line);
		line = get_next_line(fd);
		var++;
	}
	close(fd);
	if (check[0])
		return (free(line), ft_free(game()->map.info), ft_free(check), printf("Error\nThe map file information is missing.\n"), 1);
	while(line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(check);
	return (0);
}

int map_walls(char *av)
{
    int     fd;
    char    *line;
    int     var;
	int		var2;
    var = 0;
    fd = open(av, O_RDONLY);
    if (fd < 0)
        return (1);
    line = get_next_line(fd);
	while(var < 6)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		free(line);
		line = get_next_line(fd);
		var++;
	}
	while(line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
    while(line)
    {
		if(line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		var++;
        free(line);
        line = get_next_line(fd);
    }
	game()->map.map = ft_calloc(var + 1, sizeof(char *));
	close(fd);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	var = 0;
	line = get_next_line(fd);
	while(var < 6)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		free(line);
		line = get_next_line(fd);
		var++;
	}
	while(line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	var = 0;
    while(line)
    {
		if(line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		game()->map.map[var] = ft_strdupnonl(line);
		var++;
        free(line);
        line = get_next_line(fd);
    }
	game()->map.max_y = var - 1;
	close(fd);
	var = 0;
	var2 = 0;
	while(game()->map.map[var2])
	{
		var = 0;
		while(game()->map.map[var2][var])
		{
			if ((game()->map.map[var2][var] == '0') || (game()->map.map[var2][var] == 'E') || (game()->map.map[var2][var] == 'W') || (game()->map.map[var2][var] == 'N') || (game()->map.map[var2][var] == 'S'))
				fill(var, var2);
			var++;
		}
		var2++;
	}
	return (0);
}

int	map_chars(char *av)
{
	int	var;
	int	fd;
	char *line;

	var = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if(!line)
		return (close(fd), printf("Error\nThe map is missing.\n"), singleton_free(1), 1);
	int check = 0;
	int check2 = 0;
	while(var < 6)
	{
		if(line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		var++;
		free(line);
		line = get_next_line(fd);
	}
	while(line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while(line)
	{
		var = 0;
		if(line[0] == '\n')
		{
			while(line)
			{
				if(line[0] != '\n')
					return (close(fd), free(line), printf("Error\nNewline found inside the map.\n"), singleton_free(1), 1);
				free(line);
				line = get_next_line(fd);
			}
			break ;
		}
		while(line[var] && line[var] != '\n')
		{
			if(line[var] != '0' && line[var] != 'N' && line[var] != '1' && line[var] != 'E' && line[var] != 'S' && line[var] != 'W' && line[var] != ' ' && line[var] != 'C' &&  line[var] != 'O' && line[var] != 'L')
				return (close(fd), printf("Error\nInvalid character '%c' inside the map.\n", line[var]), singleton_free(1), free(line),  1);
			if (line[var] == 'N' || line[var] == 'E' || line[var] == 'S' || line[var] == 'W')
				check++;
			if (line[var] == 'L')
				check2++;
			var++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!check)
		return (printf("Error\nPlayer not found in the map.\n"), singleton_free(1), 1);
	else if (check != 1)
		return (printf("Error\nToo many players found in the map.\n"), singleton_free(1), 1);
	if (!check2)
		return (printf("Error\nExit not found in the map.\n"), singleton_free(1), 1);
	else if (check2 != 1)
		return (printf("Error\nToo many exits found in the map.\n"), singleton_free(1), 1);
	return (0);
}
