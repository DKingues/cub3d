/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:01:23 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/21 11:17:00 by rmota-ma         ###   ########.fr       */
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

void	rewrite_map(int var, int var2)
{
	var2 = 0;
	while (game()->map.map[var2])
	{
		var = 0;
		while (game()->map.map[var2][var])
		{
			if (game()->map.map[var2][var] == 'o')
				game()->map.map[var2][var] = '0';
			if (game()->map.map[var2][var] == 'c')
				game()->map.map[var2][var] -= 32;
			if (game()->map.map[var2][var] == 'l')
				game()->map.map[var2][var] -= 32;
			if (game()->map.map[var2][var] == 'n'
				|| game()->map.map[var2][var] == 's'
					|| game()->map.map[var2][var] == 'e'
						|| game()->map.map[var2][var] == 'w')
			{
				game()->map.map[var2][var] -= 32;
				game()->player.start_x = var + 0.5;
				game()->player.start_y = var2 + 0.5;
			}
			var++;
		}
		var2++;
	}
}

int	fill2(int x, int y)
{
	if (x < 0 || y < 0 || y > game()->map.max_y
		|| !game()->map.map[y][x] || game()->map.map[y][x] == '\n'
			|| game()->map.map[y][x] == ' ')
		return (1);
	if ((game()->map.map[y][x] == 'l') || (game()->map.map[y][x] == 'c')
		|| (game()->map.map[y][x] == 'o') || (game()->map.map[y][x] == '1')
			|| (game()->map.map[y][x] == 'e') || (game()->map.map[y][x] == 'w')
				|| (game()->map.map[y][x] == 'n')
					|| (game()->map.map[y][x] == 's'))
		return (0);
	if (game()->map.map[y][x] == 'C' || game()->map.map[y][x] == 'N'
		|| game()->map.map[y][x] == 'E' || game()->map.map[y][x] == 'W'
			|| game()->map.map[y][x] == 'S' || game()->map.map[y][x] == 'L')
		game()->map.map[y][x] += 32;
	else if (game()->map.map[y][x] == '0')
		game()->map.map[y][x] = 'o';
	return (fill2((x - 1), y), fill2((x + 1), y),
		fill2(x, (y - 1)), fill2(x, (y + 1)), 0);
}

int	check_map2(void)
{
	int	var;
	int	var2;

	var = 0;
	var2 = 0;
	while (game()->map.map[var])
	{
		var2 = 0;
		while (game()->map.map[var][var2])
		{
			if (game()->map.map[var][var2] == 'N'
				|| game()->map.map[var][var2] == 'W'
					|| game()->map.map[var][var2] == 'E'
						|| game()->map.map[var][var2] == 'S')
				return (printf("Error\nThe exit is unaccessible\n"),
					singleton_free(1), exit(1), 1);
			var2++;
		}
		var++;
	}
	return (0);
}

void	find_exit(int var, int var2)
{
	while (game()->map.map[var])
	{
		var2 = 0;
		while (game()->map.map[var][var2])
		{
			if (game()->map.map[var][var2] == 'L')
			{
				fill2(var2, var);
				break ;
			}
			var2++;
		}
		var++;
	}
}
