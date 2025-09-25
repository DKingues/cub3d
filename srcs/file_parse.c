/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:24:55 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/16 18:27:55 by rmota-ma         ###   ########.fr       */
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
		fd = open(game()->info[var], O_RDONLY);
		if (fd < 0)
			return (printf("Invalid texture \"%s\".\n", game()->info[var]), ft_free(game()->info), 1);
		close(fd);
		if (texture_name(game()->info[var]))
			return (printf("Invalid texture extension \"%s\". It should be a \".xpm\".\n", game()->info[var]), ft_free(game()->info), 1);
		if (texture_img(game()->info[var]))
			return (1);
		var++;
	}
	return (0);
}

int texture_img(char *av)
{
	void	*init;
	void	*img;
	init = mlx_init();
	if(!init)
		return (printf("Parsing init failed, try again.\n"), ft_free(game()->info), exit(1), 1);
	img = mlx_xpm_file_to_image(init, av, &game()->img.img_x, &game()->img.img_y);
	if(!img)
		return (mlx_destroy_display(init), free(init), ft_free(game()->info), printf("Invalid texture content.\n"), exit(1), 1);
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
	while (game()->info[4][var])
	{
		if ((game()->info[4][var] > '9' || game()->info[4][var] < '0') && game()->info[4][var] != ',')
			return(printf("Invalid row \"F %s\", it should only have digits.\n", game()->info[4]), singleton_free(), 1);
		if (game()->info[4][var] == ',')
			check++;
		var++;
	}
	if (check != 2 || var > 11 || var < 5)
		return(printf("Invalid row \"F %s\". Example \"F 255,255,255\".\n", game()->info[5]), singleton_free(), 1);
	var = 0;
	check = 0;
	while (game()->info[5][var])
	{
		if ((game()->info[5][var] > '9' || game()->info[5][var] < '0') && game()->info[5][var] != ',')
			return(printf("Invalid row \"C %s\", it should only have digits.\n", game()->info[5]), singleton_free(), 1);
		if (game()->info[5][var] == ',')
			check++;
		var++;
	}
	if (check != 2 || var > 11 || var < 5)
		return(printf("Invalid row \"C %s\". Example \"C 255,255,255\".\n", game()->info[5]), singleton_free(), 1);
	int nbr;
	game()->map_F = ft_split(game()->info[4], ',');
	var = 0;
	while(game()->map_F[var])
	{
		nbr = ft_atoi_check(game()->map_F[var]);
		if(nbr < 0 || nbr > 255)
			return (printf("Invalid row \"F %s\", every number should be between 0 and 255.\n", game()->info[4]), singleton_free(), 1);
		var++;
	}
	if (var != 3)
		return(printf("Invalid row \"F %s\". Example \"F 255,255,255\".\n", game()->info[4]), singleton_free(), 1);
	game()->map_C = ft_split(game()->info[5], ',');
	var = 0;
	while(game()->map_C[var])
	{
		nbr = ft_atoi_check(game()->map_C[var]);
		if(nbr < 0 || nbr > 255)
			return (printf("Invalid row \"C %s\", every number should be between 0 and 255.\n", game()->info[5]), singleton_free(), 1);
		var++;
	}
	if (var != 3)
		return(printf("Invalid row \"C %s\". Example \"C 255,255,255\".\n", game()->info[5]), singleton_free(), 1);
	return (0);
}

