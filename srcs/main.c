/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:47:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/19 16:49:48 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
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
/*
	#textura do nmr 6
	#leaks??
	#norm
*/