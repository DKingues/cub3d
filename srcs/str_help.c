/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:32:35 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/21 11:16:34 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_loop(char ***check, char *line, int *var, int var2)
{
	if (!ft_strncmp(line, check[0][*var], ft_strlen(check[0][*var])))
	{
		var2 = 0;
		set_gameinfo(line);
		if (check[0][*var + 1])
		{
			free(check[0][*var]);
			while (check[0][*var + var2])
				var2++;
			var2--;
			check[0][*var] = ft_strdup(check[0][*var + var2]);
			free(check[0][*var + var2]);
			check[0][*var + var2] = NULL;
		}
		else
		{
			free(check[0][*var]);
			check[0][*var] = NULL;
		}
		*var = -1;
		return (1);
	}
	*var += 1;
	return (0);
}

int	line_looping(int fd, int opt, char **line)
{
	if (!opt)
	{
		if (line[0] && line[0][0] == '\n')
		{
			free(line[0]);
			line[0] = get_next_line(fd);
			return (1);
		}
	}
	else
	{
		while (line[0])
		{
			free(line[0]);
			line[0] = get_next_line(fd);
		}
	}
	return (0);
}

int	line_helper(char **line, int var, int *check, int *check2)
{
	if (var == -1)
	{
		if (!*check)
			return (printf(P1), singleton_free(1), 1);
		else if (*check != 1)
			return (printf(P2), singleton_free(1), 1);
		if (!*check2)
			return (printf(E1), singleton_free(1), 1);
		else if (*check2 != 1)
			return (printf(E2), singleton_free(1), 1);
		return (0);
	}
	if (line[0][var] != '0' && line[0][var] != 'N' && line[0][var] != '1'
		&& line[0][var] != 'E' && line[0][var] != 'S' && line[0][var] != 'W'
		&& line[0][var] != ' ' && line[0][var] != 'C'
		&& line[0][var] != 'O' && line[0][var] != 'L')
		return (printf("Error\nInvalid character '%c' inside the map.\n",
				line[0][var]), singleton_free(1), free(line[0]), 1);
	if (line[0][var] == 'N' || line[0][var] == 'E' || line[0][var] == 'S'
		|| line[0][var] == 'W')
		*check += 1;
	if (line[0][var] == 'L')
		*check2 += 1;
	return (0);
}

int	line_checks(int fd, char **line, int *check, int *check2)
{
	int	var;

	var = 0;
	if (line[0][0] == '\n')
	{
		while (line[0])
		{
			if (line[0][0] != '\n')
				return (close(fd), free(line[0]),
					printf("Error\nNewline found inside the map.\n"),
					singleton_free(1), exit(1), 1);
			free(line[0]);
			line[0] = get_next_line(fd);
		}
		return (1);
	}
	while (line[0][var] && line[0][var] != '\n')
	{
		if (line_helper(line, var, check, check2))
			return (close(fd), exit(1), 1);
		var++;
	}
	free(line[0]);
	return (0);
}

int	alloc_map(int fd, int var, char *av)
{
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
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
	while (line)
	{
		if (line_looping(fd, 0, &line))
			continue ;
		var++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), var);
}
