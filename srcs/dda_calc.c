/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:00:45 by dicosta-          #+#    #+#             */
/*   Updated: 2025/11/25 14:46:01 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda_calc(double raydirx, double raydiry, int drawx)
{
	t_dda	s_dda;

	s_dda.hitcheck = -1;
	s_dda.hit = 0;
	s_dda.doorx = -1;
	s_dda.doory = -1;
	s_dda.deltadistx = fabs(1.0 / raydirx);
	s_dda.deltadisty = fabs(1.0 / raydiry);
	s_dda = dda_calc2(raydirx, raydiry, s_dda);
	while (!s_dda.hit)
		s_dda = dda_calc3(s_dda);
	s_dda = dda_calc4(raydirx, raydiry, s_dda);
	dda_calc5(raydirx, raydiry, s_dda, drawx);
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

t_dda	dda_calc2(double raydirx, double raydiry, t_dda s_dda)
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

t_dda	dda_calc3(t_dda s_dda)
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

t_dda	dda_calc4(double raydirx, double raydiry, t_dda s_dda)
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
	s_dda.line_height = (int)(1080 / s_dda.perpwalldist);
	return (s_dda);
}

t_dda	dda_calc5(double raydirx, double raydiry, t_dda s_dda, int drawx)
{
	s_dda.draw_start = -s_dda.line_height / 2 + 1080 / 2;
	if (s_dda.draw_start < 0)
		s_dda.draw_start = 0;
	s_dda.draw_end = s_dda.line_height / 2 + 1080 / 2;
	if (s_dda.draw_end >= 1080)
		s_dda.draw_end = 1080 - 1;
	s_dda.tex_x = (int)(s_dda.hitx * s_dda.tex_clr.res_x);
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
