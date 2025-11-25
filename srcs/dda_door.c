/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:53:02 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/25 14:45:49 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_dda	dda_door4(double raydirx, double raydiry, t_dda s_dda)
{
	if (s_dda.side == 0)
		s_dda.perpwalldist = (s_dda.mapx - s_dda.posx + (1 - s_dda.stepx) / 2.0)
			/ raydirx;
	else
		s_dda.perpwalldist = (s_dda.mapy - s_dda.posy + (1 - s_dda.stepy) / 2.0)
			/ raydiry;
	if ((game()->map.map[s_dda.mapy][s_dda.mapx] >= -127
		&& game()->map.map[s_dda.mapy][s_dda.mapx] <= -71))
		s_dda.tex_clr = game()->door[game()->map.map[s_dda.mapy][s_dda.mapx]
			+ 127];
	else if (game()->map.map[s_dda.mapy][s_dda.mapx] < 0)
		s_dda.tex_clr = game()->door[game()->map.map[s_dda.mapy][s_dda.mapx]
			+ 56];
	else if (game()->map.map[s_dda.mapy][s_dda.mapx] == 'O')
		s_dda.tex_clr = game()->door[55];
	else
		s_dda.tex_clr = game()->door[0];
	if (s_dda.side == 0)
		s_dda.hitx = s_dda.posy + raydiry * s_dda.perpwalldist;
	else
		s_dda.hitx = s_dda.posx + raydirx * s_dda.perpwalldist;
	s_dda.hitx -= floor(s_dda.hitx);
	s_dda.line_height = (int)(1080 / s_dda.perpwalldist);
	return (s_dda);
}

t_dda	dda_door5(double raydirx, double raydiry, t_dda s_dda, int drawx)
{
	if (s_dda.side == 0 && raydirx < 0)
		s_dda.tex_x = s_dda.tex_clr.res_x - s_dda.tex_x - 1;
	if (s_dda.side == 1 && raydiry > 0)
		s_dda.tex_x = s_dda.tex_clr.res_x - s_dda.tex_x - 1;
	while (s_dda.draw_start <= s_dda.draw_end)
	{
		s_dda.tex_y = s_dda.draw_start * 256 - 1080 * 128 + s_dda.line_height
			* 128;
		s_dda.tex_yy = (((s_dda.tex_y * s_dda.tex_clr.res_y)
					/ s_dda.line_height) / 256);
		if (s_dda.tex_yy >= 1080)
			s_dda.tex_yy = 1080 - 1;
		my_mlx_pixel_put(&game()->canvas, drawx, s_dda.draw_start,
			my_mlx_pixel_get(&s_dda.tex_clr, s_dda.tex_x, s_dda.tex_yy));
		s_dda.draw_start++;
	}
	return (s_dda);
}

void	dda_door(double raydirx, double raydiry, int drawx, t_dda s_dda)
{
	s_dda = dda_door4(raydirx, raydiry, s_dda);
	s_dda.draw_start = -s_dda.line_height / 2 + 1080 / 2;
	if (s_dda.draw_start < 0)
		s_dda.draw_start = 0;
	s_dda.draw_end = s_dda.line_height / 2 + 1080 / 2;
	if (s_dda.draw_end >= 1080)
		s_dda.draw_end = 1080 - 1;
	s_dda.tex_x = (int)(s_dda.hitx * s_dda.tex_clr.res_x);
	dda_door5(raydirx, raydiry, s_dda, drawx);
}

t_data	choose_text(int side, double raydirx, double raydiry)
{
	t_data	tex_clr;

	if (side == 0)
	{
		if (raydirx > 0)
			tex_clr = game()->map.east;
		else
			tex_clr = game()->map.west;
	}
	else
	{
		if (raydiry > 0)
			tex_clr = game()->map.north;
		else
			tex_clr = game()->map.south;
	}
	return (tex_clr);
}

void	dda_fov(void)
{
	double	dir[2];
	double	plane[2];
	int		i;
	double	camerax;
	double	raydir[2];

	dir[0] = game()->raycast.ray_x;
	dir[1] = game()->raycast.ray_y;
	plane[0] = game()->raycast.plane_x;
	plane[1] = game()->raycast.plane_y;
	i = 0;
	while (i < 1920)
	{
		camerax = 2 * i / (double)(1920 - 1) - 1;
		raydir[0] = dir[0] + plane[0] * camerax;
		raydir[1] = dir[1] + plane[1] * camerax;
		dda_calc(raydir[0], raydir[1], i);
		i++;
	}
}
