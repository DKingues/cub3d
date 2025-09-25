/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:24:40 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/20 14:57:17 by rmota-ma         ###   ########.fr       */
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
		return (free(line), ft_free(game()->info), ft_free(check), printf("The map file information is missing.\n"), 1);
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
	game()->map = ft_calloc(var + 1, sizeof(char *));
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
		game()->map[var] = ft_strdup(line);
		var++;
        free(line);
        line = get_next_line(fd);
    }
	game()->max_y = var - 1;
	close(fd);
	var = 0;
	var2 = 0;
	while(game()->map[var2])
	{
		var = 0;
		while(game()->map[var2][var])
		{
			if ((game()->map[var2][var] == '0') || (game()->map[var2][var] == 'E') || (game()->map[var2][var] == 'W') || (game()->map[var2][var] == 'N') || (game()->map[var2][var] == 'S'))
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
		return (close(fd), printf("The map is missing.\n"), 1);
	int check = 0;
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
					return (close(fd), free(line), printf("Newline found inside the map.\n"), 1);
				free(line);
				line = get_next_line(fd);
			}
			break ;
		}
		while(line[var] && line[var] != '\n')
		{
			if(line[var] != '0' && line[var] != 'N' && line[var] != '1' && line[var] != 'E' && line[var] != 'S' && line[var] != 'W' && line[var] != ' ')
				return (close(fd), printf("Invalid character '%c' inside the map.\n", line[var]), free(line),  1);
			if (line[var] == 'N' || line[var] == 'E' || line[var] == 'S' || line[var] == 'W')
				check++;
			var++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!check)
		return (printf("Player not found in the map.\n"), 1);
	else if (check != 1)
		return (printf("Too many players found in the map.\n"), 1);
	return (0);
}
