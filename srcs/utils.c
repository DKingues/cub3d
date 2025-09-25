/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:25:50 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/16 18:23:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	freeandcopy(int pos, char *line)
{
	free(game()->info[pos]);
	game()->info[pos] = ft_strdupnonl(line);
}

void	set_gameinfo(char *line)
{
	if(!ft_strncmp(line, "NO ", 3))
		freeandcopy(0, line + 3);
	else if(!ft_strncmp(line, "SO ", 3))
		freeandcopy(1, line + 3);
	else if(!ft_strncmp(line, "WE ", 3))
		freeandcopy(2, line + 3);
	else if(!ft_strncmp(line, "EA ", 3))
		freeandcopy(3, line + 3);
	else if(!ft_strncmp(line, "F ", 2))
		freeandcopy(4, line + 2);
	else if(!ft_strncmp(line, "C ", 2))
		freeandcopy(5, line + 2);
}

int	fill(int x, int y)
{
	if (x < 0 || y < 0 || y > game()->max_y || !game()->map[y][x] || game()->map[y][x] == '\n'|| game()->map[y][x] == ' ')
		return (printf("The map isn't closed.\n"),ft_free(game()->map), exit(1), 1);
	if ((game()->map[y][x] == 'o') || (game()->map[y][x] == '1') || (game()->map[y][x] == 'e') || (game()->map[y][x] == 'w') || (game()->map[y][x] == 'n') || (game()->map[y][x] == 's'))
		return (0);
	if (game()->map[y][x] == '0')
		game()->map[y][x] = 'o';
	else if (game()->map[y][x] == 'N')
		game()->map[y][x] = 'n';
	else if (game()->map[y][x] == 'E')
		game()->map[y][x] = 'e';
	else if (game()->map[y][x] == 'W')
		game()->map[y][x] = 'w';
	else if (game()->map[y][x] == 'S')
		game()->map[y][x] = 's';
	fill((x - 1), y);
	fill((x + 1), y);
	fill(x, (y - 1));
	fill(x, (y + 1));
	return (0);
}

int texture_name(char *av)
{
    int var;

    var = 0;
    while(av[var])
        var++;
    var--;
    if(av[var] != 'm')
        return (1);
    var--;
    if(av[var] != 'p')
        return (1);
    var--;
    if(av[var] != 'x')
        return (1);
    var--;
    if(av[var] != '.')
        return (1);
    return (0);
}

char	*ft_strdupnonl(const char *s)
{
	char	*mal;
	int		a;

	a = 0;
	mal = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!mal)
		return (NULL);
	while (s[a] != '\0' && s[a] != '\n')
	{
		mal[a] = s[a];
		a++;
	}
	mal[a] = '\0';
	return (mal);
}
