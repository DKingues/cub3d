/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:42 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/16 18:23:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_gameinfo(void)
{
	int	var;

	var = 0;
	game()->info = ft_calloc(7, sizeof(char *));
	while(var < 6)
	{
		game()->info[var] = ft_strdup("init");
		var++;
	}
}

t_game *game(void)
{
	static t_game g;
	
	return (&g);
}

