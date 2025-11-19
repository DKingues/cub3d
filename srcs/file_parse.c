/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:24:55 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/19 15:42:14 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_textures(void)
{
	int	var;
	int fd;

	var = 0;
	while (var < 4)
	{
		fd = open(game()->map.info[var], O_RDONLY);
		if (fd < 0)
			return (printf("Error\nInvalid texture \"%s\".\n", game()->map.info[var]), ft_free(game()->map.info), 1);
		close(fd);
		if (texture_name(game()->map.info[var]))
			return (printf("Error\nInvalid texture extension \"%s\". It should be a \".xpm\".\n", game()->map.info[var]), ft_free(game()->map.info), 1);
		if (texture_img(game()->map.info[var]))
			return (1);
		var++;
	}
	return (0);
}

int texture_img(char *av)
{
	void	*init;
	void	*img;
	int img_x;
	int img_y;
	init = mlx_init();
	if(!init)
		return (printf("Error\nParsing init failed, try again.\n"), ft_free(game()->map.info), exit(1), 1);
	img = mlx_xpm_file_to_image(init, av, &img_x, &img_y);
	if(!img)
		return (mlx_destroy_display(init), free(init), ft_free(game()->map.info), printf("Error\nInvalid texture content.\n"), exit(1), 1);
	mlx_destroy_image(init, img);
	mlx_destroy_display(init);
	free(init);
	return (0);
}


int	map_colors(void)
{
	int	var;
	int	check;

	var = 0;
	check = 0;
	while (game()->map.info[4][var])
	{
		if ((game()->map.info[4][var] > '9' || game()->map.info[4][var] < '0') && game()->map.info[4][var] != ',')
			return(printf("Error\nInvalid row \"F %s\", it should only have digits.\n", game()->map.info[4]), singleton_free(1), 1);
		if (game()->map.info[4][var] == ',')
			check++;
		var++;
	}
	if (check != 2 || var > 11 || var < 5)
		return(printf("Error\nInvalid row \"F %s\". Example \"F 255,255,255\".\n", game()->map.info[4]), singleton_free(1), 1);
	var = 0;
	check = 0;
	while (game()->map.info[5][var])
	{
		if ((game()->map.info[5][var] > '9' || game()->map.info[5][var] < '0') && game()->map.info[5][var] != ',')
			return(printf("Error\nInvalid row \"C %s\", it should only have digits.\n", game()->map.info[5]), singleton_free(1), 1);
		if (game()->map.info[5][var] == ',')
			check++;
		var++;
	}
	if (check != 2 || var > 11 || var < 5)
		return(printf("Error\nInvalid row \"C %s\". Example \"C 255,255,255\".\n", game()->map.info[5]), singleton_free(1), 1);
	int nbr;
	game()->map.map_F = ft_split(game()->map.info[4], ',');
	var = 0;
	while(game()->map.map_F[var])
	{
		nbr = ft_atoi_check(game()->map.map_F[var]);
		if(nbr < 0 || nbr > 255)
			return (printf("Error\nInvalid row \"F %s\", every number should be between 0 and 255.\n", game()->map.info[4]), singleton_free(1), 1);
		var++;
	}
	if (var != 3)
		return(printf("Error\nInvalid row \"F %s\". Example \"F 255,255,255\".\n", game()->map.info[4]), singleton_free(1), 1);
	game()->map.map_C = ft_split(game()->map.info[5], ',');
	var = 0;
	while(game()->map.map_C[var])
	{
		nbr = ft_atoi_check(game()->map.map_C[var]);
		if(nbr < 0 || nbr > 255)
			return (printf("Error\nInvalid row \"C %s\", every number should be between 0 and 255.\n", game()->map.info[5]), singleton_free(1), 1);
		var++;
	}
	if (var != 3)
		return(printf("Error\nInvalid row \"C %s\". Example \"C 255,255,255\".\n", game()->map.info[5]), singleton_free(1), 1);
	return (0);
}

