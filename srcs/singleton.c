/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 20:09:12 by dicosta-          #+#    #+#             */
/*   Updated: 2025-11-24 20:09:12 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	singleton_free(int parse)
{
	if (game()->map.map)
		ft_free(game()->map.map);
	if (game()->map.info)
		ft_free(game()->map.info);
	if (game()->map.orig)
		ft_free(game()->map.orig);
	if (parse == 1)
	{
		if (game()->map.map_c)
			ft_free(game()->map.map_c);
		if (game()->map.map_f)
			ft_free(game()->map.map_f);
	}
}
