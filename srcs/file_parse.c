/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:24:55 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/20 18:01:09 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_textures(void)
{
	int	var;
	int	fd;

	var = 0;
	while (var < 4)
	{
		fd = open(game()->map.info[var], O_RDONLY);
		if (fd < 0)
			return (printf("Error\nInvalid texture \"%s\".\n",
					game()->map.info[var]), ft_free(game()->map.info), 1);
		close(fd);
		if (texture_name(game()->map.info[var]))
			return (printf("Error\nInvalid texture extension \"%s\".\
				It should be a \".xpm\".\n", game()->map.info[var]),
				ft_free(game()->map.info), 1);
		if (texture_img(game()->map.info[var]))
			return (1);
		var++;
	}
	return (0);
}

int	assign2(int nbr, int var, char **temp23)
{
	temp23 = ft_split(game()->map.info[5], ',');
	game()->map.map_c = temp23;
	var = 0;
	while (game()->map.map_c[var])
	{
		nbr = ft_atoi_check(game()->map.map_c[var]);
		if (nbr < 0 || nbr > 255)
			return (printf("Error\nInvalid row \"C %s\", \
				every number should be between 0 and 255.\n",
					game()->map.info[5]), singleton_free(1), 1);
		var++;
	}
	if (var != 3)
		return (printf("Error\nInvalid row \"C %s\". \
			Example \"C 255,255,255\".\n", game()->map.info[5]),
			singleton_free(1), 1);
	return (0);
}

int	assign_colors(int nbr, int var, char **temp22, char **temp23)
{
	temp22 = ft_split(game()->map.info[4], ',');
	game()->map.map_f = temp22;
	var = 0;
	while (game()->map.map_f[var])
	{
		nbr = ft_atoi_check(game()->map.map_f[var]);
		if (nbr < 0 || nbr > 255)
			return (printf("Error\nInvalid row \"F %s\", \
				every number should be between 0 and 255.\n",
					game()->map.info[4]), singleton_free(1), 1);
		var++;
	}
	if (var != 3)
		return (printf("Error\nInvalid row \"F %s\". \
			Example \"F 255,255,255\".\n", game()->map.info[4]),
			singleton_free(1), 1);
	return (assign2(nbr, var, temp23));
}

int	check_clrs(int var, int check)
{
	if (check != 2 || var > 11 || var < 5)
		return (printf("Error\nInvalid row \"F %s\". \
			Example \"F 255,255,255\".\n", game()->map.info[4]),
			singleton_free(1), 1);
	var = 0;
	check = 0;
	while (game()->map.info[5][var])
	{
		if ((game()->map.info[5][var] > '9' || game()->map.info[5][var] < '0')
			&& game()->map.info[5][var] != ',')
			return (printf("Error\nInvalid row \"C %s\", it \
				should only have digits.\n", game()->map.info[5]),
				singleton_free(1), 1);
		if (game()->map.info[5][var] == ',')
			check++;
		var++;
	}
	if (check != 2 || var > 11 || var < 5)
		return (printf("Error\nInvalid row \"C %s\". \
			Example \"C 255,255,255\".\n", game()->map.info[5]),
			singleton_free(1), 1);
	return (0);
}

int	map_colors(void)
{
	int		var;
	int		check;
	int		nbr;
	char	**temp22;
	char	**temp23;

	var = 0;
	check = 0;
	nbr = 0;
	temp22 = NULL;
	temp23 = NULL;
	while (game()->map.info[4][var])
	{
		if ((game()->map.info[4][var] > '9' || game()->map.info[4][var] < '0')
			&& game()->map.info[4][var] != ',')
			return (printf("Error\nInvalid row \"F %s\", \
				it should only have digits.\n", game()->map.info[4]),
				singleton_free(1), 1);
		if (game()->map.info[4][var] == ',')
			check++;
		var++;
	}
	if (check_clrs(var, check))
		return (1);
	return (assign_colors(nbr, var, temp22, temp23));
}
