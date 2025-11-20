/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:01:23 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/20 18:01:52 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	texture_img(char *av)
{
	void	*init;
	void	*img;
	int		img_x;
	int		img_y;

	init = mlx_init();
	if (!init)
		return (printf("Error\nParsing init failed, try again.\n"),
			ft_free(game()->map.info), exit(1), 1);
	img = mlx_xpm_file_to_image(init, av, &img_x, &img_y);
	if (!img)
		return (mlx_destroy_display(init), free(init),
			ft_free(game()->map.info),
			printf("Error\nInvalid texture content.\n"), exit(1), 1);
	mlx_destroy_image(init, img);
	mlx_destroy_display(init);
	free(init);
	return (0);
}
