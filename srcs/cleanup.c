/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:20:48 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/16 18:23:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	singleton_free(void)
{
	if(game()->map)
		ft_free(game()->map);
	if(game()->info)
		ft_free(game()->info);
	if(game()->map_F)
		ft_free(game()->map_F);
	if(game()->map_C)
		ft_free(game()->map_C);
}