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

t_dda	dda_test2(double raydirx, double raydiry, t_dda s_dda)
{
	s_dda.posx = game()->player.player_x;
	s_dda.posy = game()->player.player_y;
	s_dda.mapx = (int)s_dda.posx;
	s_dda.mapy = (int)s_dda.posy;
	if (raydirx < 0)
	{
		s_dda.stepx = -1;
		s_dda.sidedistx = (s_dda.posx - s_dda.mapx) * s_dda.deltadistx;
	}
	else
	{
		s_dda.stepx = 1;
		s_dda.sidedistx = (s_dda.mapx + 1.0 - s_dda.posx) * s_dda.deltadistx;
	}
	if (raydiry < 0)
	{
		s_dda.stepy = -1;
		s_dda.sidedisty = (s_dda.posy - s_dda.mapy) * s_dda.deltadisty;
	}
	else
	{
		s_dda.stepy = 1;
		s_dda.sidedisty = (s_dda.mapy + 1.0 - s_dda.posy) * s_dda.deltadisty;
	}
	return (s_dda);
}

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

t_dda	dda_test3(t_dda s_dda)
{
	if (s_dda.sidedistx < s_dda.sidedisty)
	{
		s_dda.sidedistx += s_dda.deltadistx;
		s_dda.mapx += s_dda.stepx;
		s_dda.side = 0;
	}
	else
	{
		s_dda.sidedisty += s_dda.deltadisty;
		s_dda.mapy += s_dda.stepy;
		s_dda.side = 1;
	}
	if (s_dda.hitcheck == -1 && ((game()->map.map[s_dda.mapy][s_dda.mapx] >= -57
			&& game()->map.map[s_dda.mapy][s_dda.mapx] <= 0)
				|| (game()->map.map[s_dda.mapy][s_dda.mapx] >= -127
					&& game()->map.map[s_dda.mapy][s_dda.mapx] <= -71)))
		s_dda = change_dvalue(s_dda);
	if (game()->map.map[s_dda.mapy][s_dda.mapx] == '1'
	|| game()->map.map[s_dda.mapy][s_dda.mapx] == 'L'
	|| game()->map.map[s_dda.mapy][s_dda.mapx] == 'G'
	|| game()->map.map[s_dda.mapy][s_dda.mapx] == 'C')
		s_dda.hit = 1;
	return (s_dda);
}

t_dda	dda_test4(double raydirx, double raydiry, t_dda s_dda)
{
	if (s_dda.side == 0)
		s_dda.perpwalldist = (s_dda.mapx - s_dda.posx + (1 - s_dda.stepx) / 2.0)
			/ raydirx;
	else
		s_dda.perpwalldist = (s_dda.mapy - s_dda.posy + (1 - s_dda.stepy) / 2.0)
			/ raydiry;
	s_dda.tex_clr = choose_text(s_dda.side, raydirx, raydiry);
	if (game()->map.map[s_dda.mapy][s_dda.mapx] == 'L')
		s_dda.tex_clr = game()->exit;
	else if (game()->map.map[s_dda.mapy][s_dda.mapx] == 'G')
		s_dda.tex_clr = game()->glitch.glitch[game()->frame.glitch_tg];
	else if (game()->map.map[s_dda.mapy][s_dda.mapx] == 'C')
		s_dda.tex_clr = game()->door[0];
	if (s_dda.side == 0)
		s_dda.hitx = s_dda.posy + raydiry * s_dda.perpwalldist;
	else
		s_dda.hitx = s_dda.posx + raydirx * s_dda.perpwalldist;
	s_dda.hitx -= floor(s_dda.hitx);
	s_dda.lineHeight = (int)(1080 / s_dda.perpwalldist);
	return (s_dda);
}

t_dda	dda_test5(double raydirx, double raydiry, t_dda s_dda, int drawx)
{
	s_dda.drawStart = -s_dda.lineHeight / 2 + 1080 / 2;
	if (s_dda.drawStart < 0)
		s_dda.drawStart = 0;
	s_dda.drawEnd = s_dda.lineHeight / 2 + 1080 / 2;
	if (s_dda.drawEnd >= 1080)
		s_dda.drawEnd = 1080 - 1;
	s_dda.texX = (int)(s_dda.hitx * s_dda.tex_clr.res_x);
	if (s_dda.side == 0 && raydirx < 0)
		s_dda.texX = s_dda.tex_clr.res_x - s_dda.texX - 1;
	if (s_dda.side == 1 && raydiry > 0)
		s_dda.texX = s_dda.tex_clr.res_x - s_dda.texX - 1;
	while (s_dda.drawStart <= s_dda.drawEnd)
	{
		s_dda.texY = s_dda.drawStart * 256 - 1080 * 128 + s_dda.lineHeight
			* 128;
		s_dda.texYY = (((s_dda.texY * s_dda.tex_clr.res_y) / s_dda.lineHeight)
				/ 256);
		if (s_dda.texYY >= 1080)
			s_dda.texYY = 1080 - 1;
		my_mlx_pixel_put(&game()->canvas, drawx, s_dda.drawStart,
			my_mlx_pixel_get(&s_dda.tex_clr, s_dda.texX, s_dda.texYY));
		s_dda.drawStart++;
	}
	return (s_dda);
}

void	dda_test(double raydirx, double raydiry, int drawx)
{
	t_dda	s_dda;

	s_dda.hitcheck = -1;
	s_dda.hit = 0;
	s_dda.doorx = -1;
	s_dda.doory = -1;
	s_dda.deltadistx = fabs(1.0 / raydirx);
	s_dda.deltadisty = fabs(1.0 / raydiry);
	s_dda = dda_test2(raydirx, raydiry, s_dda);
	while (!s_dda.hit)
		s_dda = dda_test3(s_dda);
	s_dda = dda_test4(raydirx, raydiry, s_dda);
	dda_test5(raydirx, raydiry, s_dda, drawx);
	if (s_dda.hitcheck != -1)
	{
		s_dda.side = s_dda.doorside;
		s_dda.sidedistx = s_dda.sidedoorx;
		s_dda.sidedisty = s_dda.sidedoory;
		s_dda.mapx = s_dda.doorx;
		s_dda.mapy = s_dda.doory;
		dda_door(raydirx, raydiry, drawx, s_dda);
	}
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
