/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:31:16 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/24 16:31:27 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ray_check(t_raycast rt)
{
	return (game()->map.map[(int)rt.fy]
		&& game()->map.map[(int)rt.fy][(int)rt.fx]
				&& game()->map.map[(int)rt.fy][(int)rt.fx] != '1'
				&& game()->map.map[(int)rt.fy][(int)rt.fx] != 'C'
				&& game()->map.map[(int)rt.fy][(int)rt.fx] != 'G'
				&& game()->map.map[(int)rt.fy][(int)rt.fx] > 0
				&& !check_point(rt.fx, rt.fy));
}

void	draw_rays(t_data *src, t_data *dst, int x, int y)
{
	t_raycast	rt;

	rt.player_x = game()->player.player_x;
	rt.player_y = game()->player.player_y;
	rt.dir_x = -game()->raycast.ray_x;
	rt.dir_y = -game()->raycast.ray_y;
	rt.plane_x = game()->raycast.plane_x;
	rt.plane_y = game()->raycast.plane_y;
	rt.sx = 0;
	while (rt.sx < 64)
	{
		rt.sy = 0;
		while (rt.sy < 64)
		{
			rt.dx = (rt.sx + x - 96) / 64.0f;
			rt.dy = (rt.sy + y - 96) / 64.0f;
			rt.fx = rt.player_x + rt.dx * rt.plane_x + rt.dy * rt.dir_x;
			rt.fy = rt.player_y + rt.dx * rt.plane_y + rt.dy * rt.dir_y;
			if (ray_check(rt))
				my_mlx_pixel_put(dst, rt.sx + x, rt.sy + y,
					my_mlx_pixel_get_dim(src, rt.sx, rt.sy, 1.0));
			rt.sy++;
		}
		rt.sx++;
	}
}

t_data	*choose_clr(char map_char, unsigned int *color)
{
	t_data	*tex_clr;

	color[0] = 0x2B242E;
	if (map_char == '1')
		tex_clr = &game()->wall;
	else if (map_char == 'C')
		tex_clr = &game()->door[0];
	else if (map_char == 'O')
		tex_clr = &game()->door[55];
	else if (map_char == 'G')
		tex_clr = &game()->glitch.glitch[game()->frame.glitch_tg];
	else if (map_char == 'L')
		tex_clr = &game()->exit;
	else if ((map_char >= -127 && map_char <= -71))
		tex_clr = &game()->door[map_char + 127];
	else if (map_char < 0)
		tex_clr = &game()->door[map_char + 56];
	else
		tex_clr = NULL;
	return (tex_clr);
}

t_raycast	x_loop(t_raycast rt, int x, int y, t_data *tex_clr)
{
	while (++x < 192)
	{
		rt.dx = (x - 96) / 64.0f;
		rt.dy = (y - 96) / 64.0f;
		rt.fx = rt.player_x + rt.dx * rt.plane_x + rt.dy * rt.dir_x;
		rt.fy = rt.player_y + rt.dx * rt.plane_y + rt.dy * rt.dir_y;
		rt.map_char = '\0';
		if (game()->map.map[(int)rt.fy]
			&& game()->map.map[(int)rt.fy][(int)rt.fx])
			rt.map_char = game()->map.map[(int)rt.fy][(int)rt.fx];
		tex_clr = choose_clr(rt.map_char, &rt.color);
		if (tex_clr)
		{
			rt.tex_x = ((int)(rt.fx * tex_clr->res_x)) % tex_clr->res_x;
			rt.tex_y = ((int)(rt.fy * tex_clr->res_y)) % tex_clr->res_y;
			if (rt.tex_x < 0)
				rt.tex_x += tex_clr->res_x;
			if (rt.tex_y < 0)
				rt.tex_y += tex_clr->res_y;
			rt.color = my_mlx_pixel_get(tex_clr, rt.tex_x, rt.tex_y);
		}
		y = 192 - y;
		my_mlx_pixel_put(&game()->minimap, x, y, rt.color);
	}
	return (rt);
}

void	draw_minimap(int y, int x)
{
	t_raycast	rt;

	rt.player_x = game()->player.player_x;
	rt.player_y = game()->player.player_y;
	rt.dir_x = game()->raycast.ray_x;
	rt.dir_y = game()->raycast.ray_y;
	rt.plane_x = game()->raycast.plane_x;
	rt.plane_y = game()->raycast.plane_y;
	y = 0;
	while (y < 192)
	{
		x = 0;
		while (x < 192)
		{
			my_mlx_pixel_put(&game()->minimap, x, y, 0x2B242E);
			x++;
		}
		y++;
	}
	y = -1;
	while (++y < 192)
		rt = x_loop(rt, -1, y, NULL);
	draw_rays(&game()->rays, &game()->minimap, 64, 34);
	draw_img(&game()->person, &game()->minimap, 64, 64);
}
