/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:24:40 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/20 16:33:33 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_validate(char *av, int fd, int var, char *line)
{
	char	**check;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	check = init_gameinfo();
	line = get_next_line(fd);
	while (line && check[0])
	{
		var = 0;
		if (line_looping(fd, 0, &line))
			continue ;
		while (check[var])
			if (check_loop(&check, line, &var, 0))
				break ;
		if (var != -1)
			break ;
		free(line);
		line = get_next_line(fd);
		var++;
	}
	if (check[0])
		return (close(fd), free(line), ft_free(game()->map.info),
			ft_free(check), 1);
	return (close(fd), line_looping(fd, 1, &line), free(check), 0);
}

void	map_filling(void)
{
	int	var;
	int	var2;

	var = 0;
	var2 = 0;
	while (game()->map.map[var2])
	{
		var = 0;
		while (game()->map.map[var2][var])
		{
			if ((game()->map.map[var2][var] == '0')
				|| (game()->map.map[var2][var] == 'E')
					|| (game()->map.map[var2][var] == 'W')
						|| (game()->map.map[var2][var] == 'N')
							|| (game()->map.map[var2][var] == 'S'))
				fill(var, var2);
			var++;
		}
		var2++;
	}
}

void	copy_1st_map(int fd, char **line)
{
	int	var;

	var = 0;
	while (line[0])
	{
		if (line_looping(fd, 0, line))
			continue ;
		game()->map.map[var] = ft_strdupnonl(line[0]);
		var++;
		free(line[0]);
		line[0] = get_next_line(fd);
	}
	game()->map.max_y = var - 1;
	close(fd);
}

int	map_walls(char *av)
{
	int		fd;
	int		var;
	char	*line;
	char	**temp;

	var = alloc_map(0, 0, av);
	temp = ft_calloc(sizeof(char *), var + 1);
	game()->map.map = temp;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	var = 0;
	line = get_next_line(fd);
	while (var < 6)
	{
		if (line_looping(fd, 0, &line))
			continue ;
		free(line);
		line = get_next_line(fd);
		var++;
	}
	while (line_looping(fd, 0, &line))
		continue ;
	copy_1st_map(fd, &line);
	return (map_filling(), 0);
}

int	map_chars(char *av, int var, int check, int check2)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), printf("Error\nThe map is missing.\n"),
			singleton_free(1), 1);
	while (var < 6)
	{
		if (line_looping(fd, 0, &line))
			continue ;
		var++;
		free(line);
		line = get_next_line(fd);
	}
	while (line_looping(fd, 0, &line))
		continue ;
	while (line && !line_checks(fd, &line, &check, &check2))
	{
		line = get_next_line(fd);
	}
	return (close(fd), line_helper(&line, -1, &check, &check2));
}
