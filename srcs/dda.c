/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:06:18 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/21 19:33:40 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_dda	change_dvalue(t_dda s_dda)
{
	s_dda.hitcheck = 0;
	s_dda.doorside = s_dda.side;
	s_dda.sidedoorx = s_dda.sidedistx;
	s_dda.sidedoory = s_dda.sidedisty;
	s_dda.doorx = s_dda.mapx;
	s_dda.doory = s_dda.mapy;
	return (s_dda);
}

void	rotate_ray(int dir)
{
	double	oldrayx;
	double	oldplanex;
	double	rot;

	oldrayx = game()->raycast.ray_x;
	oldplanex = game()->raycast.plane_x;
	rot = dir * 0.04;
	game()->raycast.ray_x = game()->raycast.ray_x * cos(rot)
	- game()->raycast.ray_y * sin(rot);
	game()->raycast.ray_y = oldrayx * sin(rot) + game()->raycast.ray_y
	* cos(rot);
	game()->raycast.plane_x = game()->raycast.plane_x * cos(rot)
	- game()->raycast.plane_y * sin(rot);
	game()->raycast.plane_y = oldplanex * sin(rot) + game()->raycast.plane_y
	* cos(rot);
}
