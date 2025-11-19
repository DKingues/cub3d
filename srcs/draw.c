/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:05:06 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/19 12:32:01 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_img(t_data *src, t_data *dst, int x, int y, float factor)
{
	int	sx;
	int	sy;

	sy = 0;
	while (sy < src->res_y)
	{
		sx = 0;
		while (sx < src->res_x)
		{
			my_mlx_pixel_put(dst, sx + x, sy + y,
				my_mlx_pixel_get_dim(src, sx, sy, factor));
			sx++;
		}
		sy++;
	}
}

void draw_line(double rayDirX, double rayDirY)
{
	double posX = game()->player.player_x, posY = game()->player.player_y;

    int mapX = (int)posX;
    int mapY = (int)posY;

    double deltaDistX = fabs(1.0 / rayDirX);
    double deltaDistY = fabs(1.0 / rayDirY);

    int stepX, stepY;
    double sideDistX, sideDistY;

    if (rayDirX < 0) {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
    } else {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
    }
    if (rayDirY < 0) {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
    } else {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
    }
    int hit = 0;
    int side;
    while (!hit) {
        if (sideDistX < sideDistY) {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        } else {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }
        if (game()->map.map[mapY][mapX] == '1' || game()->map.map[mapY][mapX] == 'C' || game()->map.map[mapY][mapX] == 'G')
            hit = 1;
    }
    double perpWallDist;
    if (side == 0)
        perpWallDist = (mapX - posX + (1 - stepX) / 2.0) / rayDirX;
    else
	{
        perpWallDist = (mapY - posY + (1 - stepY) / 2.0) / rayDirY;
	}
	double x1;
    x1 = posX + rayDirX * perpWallDist;
    double y1;
    y1 = posY + rayDirY * perpWallDist;
	float x0 = 96;
	float y0 = 96;
    float dx = fabs(x1 - x0);
    float dy = fabs(y1 - y0);
    float sx = x0 < x1 ? 1 : -1;
    float sy = y0 < y1 ? 1 : -1;
    float err = dx - dy;
    float e2;
	if(x1 < 0)
		x1 = 0;
	if (y1 < 0)
		y1 = 0;
	if(x1 > 191)
		x1 = 192;
	if (y1 > 192)
		y1 = 192;
    while (1)    
	{
        my_mlx_pixel_put(&game()->minimap, (x0), (y0), 0x0096FF);
		if (!game()->map.map[(int)(y0 / 64)] || !game()->map.map[(int)(y0 / 64)][(int)(x0 / 64)])
			break ;
        if (game()->map.map[(int)(y0 / 64)][(int)(x0 / 64)] == '1' || game()->map.map[(int)(y0 / 64)][(int)(x0 / 64)] == 'C' || game()->map.map[(int)(y0 / 64)][(int)(x0 / 64)] == 'G')
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

long	ft_strtol(const char *str)
{
	int	a, b = 0;
	long dec = 0;
	long	res;

	a = ft_strlen(str) - 1;
	res = 0;
	while(a >= 2)
	{
		if (str[a] >= '0' && str[a] <= '9')
			res = str[a] - '0';
		else
			res = str[a] - 'A' + 10;
		dec = dec + res * pow(16, b);
		b++;
		a--;
	}
	return (dec);
}

void	draw_fc(void)
{
	int	sx;
	int	sy;
	float factor = 0.7;

	sy = 0;
	while (sy < 540)
	{
		sx = 0;
		while (sx < 1920)
		{
			my_mlx_pixel_put2(&game()->canvas, sx, sy,
				(dim_clr(game()->map.C, factor)));
			sx++;
		}
		if(factor > 0)
			factor -= 0.00148;
		sy++;
	}
	while (sy < 1080)
	{
		sx = 0;
		while (sx < 1920)
		{
			my_mlx_pixel_put2(&game()->canvas, sx, sy,
				(dim_clr(game()->map.F, 1.0)));
			sx++;
		}
		if(factor < 0.7)
			factor += 0.00148;
		sy++;
	}
}

void	assign_c(void)
{
	char *temp;
	char *c_color;

	temp = nbr_hx_clr(ft_atoi(game()->map.map_C[0]));
	c_color = ft_strdup("0x");
	c_color = ft_strjoin(c_color, temp);
	free(temp);
	temp = nbr_hx_clr(ft_atoi(game()->map.map_C[1]));
	c_color = ft_strjoin(c_color, temp);
	free(temp);
	temp = nbr_hx_clr(ft_atoi(game()->map.map_C[2]));
	c_color = ft_strjoin(c_color, temp);
	free(temp);
	ft_free(game()->map.map_C);
	game()->map.C = ft_strtol(c_color);
	free(c_color);
}

void	assign_f(void)
{
	char *temp;
	char *f_color;

	temp = nbr_hx_clr(ft_atoi(game()->map.map_F[0]));
	f_color = ft_strdup("0x");
	f_color = ft_strjoin(f_color, temp);
	free(temp);
	temp = nbr_hx_clr(ft_atoi(game()->map.map_F[1]));
	f_color = ft_strjoin(f_color, temp);
	free(temp);
	temp = nbr_hx_clr(ft_atoi(game()->map.map_F[2]));
	f_color = ft_strjoin(f_color, temp);
	free(temp);
	ft_free(game()->map.map_F);
	game()->map.F = ft_strtol(f_color);
	free(f_color);
}

void	draw_sprint(void)
{
	int	var;
	int var2 = 768;
	float var3 = 3.84 * (int)game()->player.sprint_count;
	while(var2 < (int)var3 + 768)
	{
		var = 1030;
		while(var < 1043)
		{
			my_mlx_pixel_put(&game()->canvas, var2, var, 0x00FFFF);
			var++;
		}
		var2++;
	}
}

int check_point(float fx, float fy)
{
   float x0 = game()->player.player_x;
    float y0 = game()->player.player_y;

    int map_x = (int)floor(x0);
    int map_y = (int)floor(y0);

    int end_x = (int)floor(fx);
    int end_y = (int)floor(fy);

    float dx = fx - x0;
    float dy = fy - y0;

    int step_x = (dx > 0) ? 1 : -1;
    int step_y = (dy > 0) ? 1 : -1;

    float t_max_x = (dx == 0) ? INFINITY :
        ((step_x > 0 ? (map_x + 1.0 - x0) : (x0 - map_x)) / fabs(dx));
    float t_max_y = (dy == 0) ? INFINITY :
        ((step_y > 0 ? (map_y + 1.0 - y0) : (y0 - map_y)) / fabs(dy));

    float t_delta_x = (dx == 0) ? INFINITY : 1.0 / fabs(dx);
    float t_delta_y = (dy == 0) ? INFINITY : 1.0 / fabs(dy);

    while (1) {
        if (!game()->map.map[map_y] || game()->map.map[map_y][map_x] == '\0') 
			break;
        if (game()->map.map[map_y][map_x] == '1' || game()->map.map[(int)map_y][(int)map_x] == 'L' || game()->map.map[(int)map_y][(int)map_x] == 'C' || game()->map.map[(int)map_y][(int)map_x] == 'G' || game()->map.map[(int)fy][(int)fx] < 0 ) 
			return 1;
        if (map_x == end_x && map_y == end_y) 
			break;

        if (t_max_x < t_max_y) {
            t_max_x += t_delta_x;
            map_x += step_x;
        } else {
            t_max_y += t_delta_y;
            map_y += step_y;
        }
    }
    return 0;
}
    

void	draw_rays(t_data *src, t_data *dst, int x, int y, float factor)
{
	int	sx;
	int	sy;

	float player_x = game()->player.player_x;
    float player_y = game()->player.player_y;
    float dir_x = -game()->raycast.ray_x;
    float dir_y = -game()->raycast.ray_y;
    float plane_x = game()->raycast.plane_x;
    float plane_y = game()->raycast.plane_y;

	sx = 0;
	while (sx < 64)
	{
		sy = 0;
		while (sy < 64)
		{
			float dx = (sx + x - 96) / 64.0f;
            float dy = (sy + y - 96) / 64.0f;
            float fx = player_x + dx * plane_x + dy * dir_x;
            float fy = player_y + dx * plane_y + dy * dir_y;

            if (game()->map.map[(int)fy] && game()->map.map[(int)fy][(int)fx] && game()->map.map[(int)fy][(int)fx] != '1' && game()->map.map[(int)fy][(int)fx] != 'C' && game()->map.map[(int)fy][(int)fx] != 'G' && game()->map.map[(int)fy][(int)fx] > 0 && !check_point(fx, fy))
				my_mlx_pixel_put(dst, sx + x, sy + y,
					my_mlx_pixel_get_dim(src, sx, sy, factor));
			sy++;
		}
		sx++;
	}
}

void draw_minimap(void)
{
    int y, x;
    float player_x = game()->player.player_x;
    float player_y = game()->player.player_y;
    float dir_x = game()->raycast.ray_x;
    float dir_y = game()->raycast.ray_y;
    float plane_x = game()->raycast.plane_x;
    float plane_y = game()->raycast.plane_y;
	t_data *tex_clr;
    y = 0;
	while(y < 192)
	{
		x = 0;
		while(x < 192)
		{
			my_mlx_pixel_put(&game()->minimap, x, y, 0x2B242E);
			x++;
		}
		y++;
	}
	y = 0;
    while (y < 192)
    {
        x = 0;
        while (x < 192)
        {
            float dx = (x - 96) / 64.0f;
            float dy = (y - 96) / 64.0f;
            float fx = player_x + dx * plane_x + dy * dir_x;
            float fy = player_y + dx * plane_y + dy * dir_y;
            
            char map_char = '\0';
            if(fx < 0 || fy < 0)
				map_char = '\0';
			else if (game()->map.map[(int)fy] && game()->map.map[(int)fy][(int)fx])
				map_char = game()->map.map[(int)fy][(int)fx];
            unsigned int color = 0x2B242E;
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
			else if ((map_char >= -127 &&  map_char <= -71))
        		tex_clr = &game()->door[map_char + 127];
    		else if (map_char < 0)
			{
        		tex_clr = &game()->door[map_char + 56];
			}
			if(tex_clr)
			{
				int tex_x = ((int)(fx * tex_clr->res_x)) % tex_clr->res_x;
            	int tex_y = ((int)(fy * tex_clr->res_y)) % tex_clr->res_y;
            	if (tex_x < 0)
					tex_x += tex_clr->res_x;
            	if (tex_y < 0)
					tex_y += tex_clr->res_y;
				color = my_mlx_pixel_get(tex_clr, tex_x, tex_y);
			}
			y = 192 - y;
            my_mlx_pixel_put(&game()->minimap, x, y, color);
			tex_clr = NULL;

            x++;
        }
        y++;
    }
	draw_rays(&game()->rays, &game()->minimap, 64, 34, 1.0);
    draw_img(&game()->person, &game()->minimap, 64, 64, 1.0);
}

// void	draw_minimap(void)
// {
// 	int y = 0;
// 	int x = 0;
// 	int				tex_x;
// 	int				tex_y;
// 	while(y < 192)
// 	{
// 		x = 0;
// 		while(x < 192)
// 		{
// 			my_mlx_pixel_put(&game()->minimap, x, y, 0xFFFFFF);
// 			x++;
// 		}
// 		y++;
// 	}
// 	y = 0;
// 	draw_img(&game()->rays, &game()->minimap, 63, 34, 1.0);
// 	while(y < 192)
// 	{
// 		x = 0;
// 		while(x < 192)
// 		{
// 			float fx = (x / 64.0f) + (game()->player.player_x - 1.5f);
// 			float fy = (y / 64.0f) + (game()->player.player_y - 1.5f);
// 			float world_pixel_x = (game()->player.player_x - 1.5f) * 64.0f + x;
// 			float world_pixel_y = (game()->player.player_y - 1.5f) * 64.0f + y;
// 			tex_x = (int)floor(world_pixel_x) % 64;
// 			tex_y = (int)floor(world_pixel_y) % 64;
// 			char map_char = '\0';
// 			if(fx < 0 || fy < 0)
// 				map_char = '\0';
// 			else if (game()->map.map[(int)fy] && game()->map.map[(int)fy][(int)fx])
// 				map_char = game()->map.map[(int)fy][(int)fx];
// 			unsigned int color = 0x000000;
// 			if (map_char == '1')
// 				color = my_mlx_pixel_get(&game()->wall, tex_x, tex_y); 
// 			else if (map_char == '0' || map_char == 'N' || map_char == 'W' || 
// 			         map_char == 'S' || map_char == 'E' || map_char == 'O')
// 				color = 0x66FF00;
// 			else if (map_char == 'C')
// 				color = 0x00FF00;
// 			my_mlx_pixel_put(&game()->minimap, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// 	draw_img(&game()->person, &game()->minimap, 64, 64, 1.0);
// }

void draw_glitch(int var, int var2)
{
	static int i;

	if (i == 10)
		i = 0;
	draw_img(&game()->glitch.glitch[i], &game()->canvas, var * 64, var2 * 64, 1.0);
	i++;
}

void	my_mlx_pixel_put3(t_data *data, int x, int y, int color)
{
	char	*dst;

	if(color == 0x00FF00)
		color = my_mlx_pixel_get(&game()->canvas, x, y);
	if(color == 0xFF0000)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_circle(t_data *src, t_data* dst, int x, int y)
{
	int	sx;
	int	sy;

	sy = 0;
	while (sy < src->res_y)
	{
		sx = 0;
		while (sx < src->res_x)
		{
			my_mlx_pixel_put3(dst, sx + x, sy + y, my_mlx_pixel_get(src, sx + x, sy + y));
			sx++;
		}
		sy++;
	}
}

void	ins_map(void)
{
	static int offset = 0;
	offset++;
	if(offset % 5 == 0)
	{
		game()->frame.glitch_tg++;
    	if(game()->frame.glitch_tg == 10)
			game()->frame.glitch_tg = 0;
		offset = 0;
	}
	draw_fc();
	draw_minimap();
	dda_fov();
	draw_img(&game()->timer, &game()->canvas, 0, 0, 1.0);
	//draw_circle(&game()->circle, &game()->minimap, 0, 0);
	//draw_img(&game()->hud, &game()->canvas, 0, 0, 1.0);
	draw_time();
	draw_sprint();
	draw_img(&game()->minimap, &game()->canvas, 47, 96, 1.0);
}
