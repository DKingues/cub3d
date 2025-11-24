/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:30:58 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/24 16:31:06 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_sprint(void)
{
	int		var;
	int		var2;
	float	var3;

	var2 = 768;
	var3 = 3.84 * (int)game()->player.sprint_count;
	while (var2 < (int)var3 + 768)
	{
		var = 1030;
		while (var < 1043)
		{
			my_mlx_pixel_put(&game()->canvas, var2, var, 0x00FFFF);
			var++;
		}
		var2++;
	}
}

t_point	check_point4(t_point pt)
{
	if (pt.t_max_x < pt.t_max_y)
	{
		pt.t_max_x += pt.t_delta_x;
		pt.map_x += pt.step_x;
	}
	else
	{
		pt.t_max_y += pt.t_delta_y;
		pt.map_y += pt.step_y;
	}
	return (pt);
}

t_point	check_point3(t_point pt)
{
	if (pt.dy == 0)
		pt.t_max_y = INFINITY;
	else
	{
		if (pt.step_y > 0)
			pt.t_max_y = (pt.map_y + 1.0 - pt.y0) / fabs(pt.dy);
		else
			pt.t_max_y = (pt.y0 - pt.map_y) / fabs(pt.dy);
	}
	if (pt.dx == 0)
		pt.t_delta_x = INFINITY;
	else
		pt.t_delta_x = 1.0 / fabs(pt.dx);
	if (pt.dy == 0)
		pt.t_delta_y = INFINITY;
	else
		pt.t_delta_y = 1.0 / fabs(pt.dy);
	return (pt);
}

t_point	check_point2(t_point pt, float fx, float fy)
{
	pt.y0 = game()->player.player_y;
	pt.map_x = (int)floor(pt.x0);
	pt.map_y = (int)floor(pt.y0);
	pt.end_x = (int)floor(fx);
	pt.end_y = (int)floor(fy);
	pt.dx = fx - pt.x0;
	pt.dy = fy - pt.y0;
	if (pt.dx > 0)
		pt.step_x = 1;
	else
		pt.step_x = -1;
	if (pt.dy > 0)
		pt.step_y = 1;
	else
		pt.step_y = -1;
	if (pt.dx == 0)
		pt.t_max_x = INFINITY;
	else
	{
		if (pt.step_x > 0)
			pt.t_max_x = (pt.map_x + 1.0 - pt.x0) / fabs(pt.dx);
		else
			pt.t_max_x = ((pt.x0 - pt.map_x) / fabs(pt.dx));
	}
	return (pt);
}

int	check_point(float fx, float fy)
{
	t_point	pt;

	pt.x0 = game()->player.player_x;
	pt = check_point2(pt, fx, fy);
	pt = check_point3(pt);
	while (1)
	{
		if (!game()->map.map[pt.map_y]
			|| game()->map.map[pt.map_y][pt.map_x] == '\0')
			break ;
		if (game()->map.map[pt.map_y][pt.map_x] == '1'
			|| game()->map.map[(int)pt.map_y][(int)pt.map_x] == 'L'
			|| game()->map.map[(int)pt.map_y][(int)pt.map_x] == 'C'
			|| game()->map.map[(int)pt.map_y][(int)pt.map_x] == 'G'
			|| game()->map.map[(int)fy][(int)fx] < 0)
			return (1);
		if (pt.map_x == pt.end_x && pt.map_y == pt.end_y)
			break ;
		pt = check_point4(pt);
	}
	return (0);
}
