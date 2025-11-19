/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:47:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/19 12:56:39 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	if (ac < 2)
		return (printf("Insert a map name.\n"), 1);
	if (ac > 2)
		return (printf("Too many arguments.\n"), 1);
	if (parsing(av))
		return (1);
	singleton_free(1);
	// init();
	// gameplay();
    return (0);
}
/* 
	#escrever Error\n antes dos erros e dar update em msgs
	#espacos despois do F C NO etc e nas virgulas e que (sque)
	#mais testing, claro
	#textura do nmr 6
	#leaks??
	#norm
*/