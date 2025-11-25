/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:47:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/20 18:15:38 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	print_singleton(void)
// {
// 	int	var;

// 	var = 0;
// 	while (game()->map.map[var])
// 	{
// 		printf("MAP: %s\n", game()->map.map[var]);
// 		var++;
// 	}
// 	printf("\n\n");
// 	var = 0;
// 	while (game()->map.info[var])
// 	{
// 		printf("INFO: %s\n", game()->map.info[var]);
// 		var++;
// 	}
// 	printf("\n\n");
// 	var = 0;
// 	while (game()->map.orig[var])
// 	{
// 		printf("ORIG: %s\n", game()->map.orig[var]);
// 		var++;
// 	}
// }

int	main(int ac, char **av)
{
	if (ac < 2)
		return (printf("Error\nInsert a map name.\n"), 1);
	if (ac > 2)
		return (printf("Error\nToo many arguments.\n"), 1);
	if (parsing(av))
		return (1);
	init();
	gameplay();
	return (0);
}
