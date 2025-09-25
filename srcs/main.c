/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:47:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/16 18:23:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	if (ac < 2)
		return (printf("Insert a map name.\n"), 1);
	if (ac > 2)
		return (printf("Too many arguments.\n"), 1);
	if(parsing(av))
		return (1);
    return (0);
}
