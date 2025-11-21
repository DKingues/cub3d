/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:06:18 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/21 13:49:11 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda_door(double raydirx, double raydiry, int drawx)
{
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	hitx;
	double	posx;
	double	posy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	t_data	tex_clr;

	hit = 0;
	posx = game()->player.player_x;
	posy = game()->player.player_y;
	mapx = (int)posx;
	mapy = (int)posy;
	deltadistx = fabs(1.0 / raydirx);
	deltadisty = fabs(1.0 / raydiry);
	if (raydirx < 0)
	{
		stepx = -1;
		sidedistx = (posx - mapx) * deltadistx;
	}
	else
	{
		stepx = 1;
		sidedistx = (mapx + 1.0 - posx) * deltadistx;
	}
	if (raydiry < 0)
	{
		stepy = -1;
		sidedisty = (posy - mapy) * deltadisty;
	}
	else
	{
		stepy = 1;
		sidedisty = (mapy + 1.0 - posy) * deltadisty;
	}
	while (!hit)
	{
		if (sidedistx < sidedisty)
		{
			sidedistx += deltadistx;
			mapx += stepx;
			side = 0;
		}
		else
		{
			sidedisty += deltadisty;
			mapy += stepy;
			side = 1;
		}
		if ((game()->map.map[mapy][mapx] >= -57
			&& game()->map.map[mapy][mapx] <= 0)
				|| (game()->map.map[mapy][mapx] >= -127
					&& game()->map.map[mapy][mapx] <= -71)
					|| game()->map.map[mapy][mapx] == '1'
					|| game()->map.map[mapy][mapx] == 'G'
					|| game()->map.map[mapy][mapx] == 'L'
					|| game()->map.map[mapy][mapx] == 'C'
					|| game()->map.map[mapy][mapx] == 'O')
			hit = 1;
	}
	if (game()->map.map[mapy][mapx] != 'C'
		&& !(game()->map.map[mapy][mapx] >= -57
		&&  game()->map.map[mapy][mapx] <= 0)
		&& !(game()->map.map[mapy][mapx] >= -127
		&&  game()->map.map[mapy][mapx] <= -71)
		&& game()->map.map[mapy][mapx] != 'O')
	    return ;
	if (side == 0)
	    perpwalldist = (mapx - posx + (1 - stepx) / 2.0) / raydirx;
	else
	    perpwalldist = (mapy - posy + (1 - stepy) / 2.0) / raydiry;
	if ((game()->map.map[mapy][mapx] >= -127 &&  game()->map.map[mapy][mapx] <= -71))
	    tex_clr = game()->door[game()->map.map[mapy][mapx] + 127];
	else if (game()->map.map[mapy][mapx] < 0)
	    tex_clr = game()->door[game()->map.map[mapy][mapx] + 56];
	else if (game()->map.map[mapy][mapx] == 'O')
		tex_clr = game()->door[55];
	else
	    tex_clr = game()->door[0];
	if(side == 0)
	    hitx = posy + raydiry * perpwalldist;
	else
	     hitx = posx + raydirx * perpwalldist;
	hitx -= floor(hitx);
	int lineHeight = (int)(1080 / perpwalldist);
	int drawStart = -lineHeight / 2 + 1080 / 2;
	if(drawStart < 0)
	    drawStart = 0;
	int drawEnd = lineHeight / 2 + 1080 / 2;
	if(drawEnd >= 1080)
	    drawEnd = 1080 - 1;
	int texX = (int)(hitx * tex_clr.res_x);
	if(side == 0 && raydirx < 0) 
	    texX = tex_clr.res_x - texX - 1;
	if(side == 1 && raydiry > 0)
	    texX = tex_clr.res_x - texX - 1;
	while(drawStart <= drawEnd)
	{
	    int texY = drawStart * 256 - 1080 * 128 + lineHeight * 128;
	    int texYY =  (((texY * tex_clr.res_y) / lineHeight) / 256);
	    if(texYY >= 1080)
	        texYY = 1080 - 1;
	    my_mlx_pixel_put(&game()->canvas, drawx, drawStart, my_mlx_pixel_get(&tex_clr, texX, texYY));
	    drawStart++;
	}
}

void dda_test(double rayDirX, double rayDirY, int drawX)
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
        if (game()->map.map[mapY][mapX] == '1' || game()->map.map[mapY][mapX] == 'G' || game()->map.map[mapY][mapX] == 'L')
            hit = 1;
    }
    double perpWallDist;
    if (side == 0)
        perpWallDist = (mapX - posX + (1 - stepX) / 2.0) / rayDirX;
    else
        perpWallDist = (mapY - posY + (1 - stepY) / 2.0) / rayDirY;
    double hitX;
    t_data tex_clr;
    if (side == 0)
	{
		if (rayDirX > 0)
			tex_clr = game()->map.east;
		else
			tex_clr = game()->map.west;
	}
	else
	{
		if (rayDirY > 0)
			tex_clr = game()->map.north;
		else
			tex_clr = game()->map.south;
	}
	if(game()->map.map[mapY][mapX] == 'G')
		tex_clr = game()->glitch.glitch[game()->frame.glitch_tg];
	if(game()->map.map[mapY][mapX] == 'L')
		tex_clr = game()->exit;
    if(side == 0)
        hitX = posY + rayDirY * perpWallDist;
    else
         hitX = posX + rayDirX * perpWallDist;
    //draw_line(rayDirX, rayDirY);
    hitX -= floor(hitX);
    int lineHeight = (int)(1080 / perpWallDist);
    int drawStart = -lineHeight / 2 + 1080 / 2;
    if(drawStart < 0)
        drawStart = 0;
    int drawEnd = lineHeight / 2 + 1080 / 2;
    if(drawEnd >= 1080)
        drawEnd = 1080 - 1;
    int texX = (int)(hitX * tex_clr.res_x);
    if(side == 0 && rayDirX < 0) 
        texX = tex_clr.res_x - texX - 1;
    if(side == 1 && rayDirY > 0)
        texX = tex_clr.res_x - texX - 1;
    while(drawStart <= drawEnd)
    {
        int texY = drawStart * 256 - 1080 * 128 + lineHeight * 128;
	    int texYY =  (((texY * tex_clr.res_y) / lineHeight) / 256);
        if(texYY >= 1080)
            texYY = 1080 - 1;
        my_mlx_pixel_put2(&game()->canvas, drawX, drawStart, my_mlx_pixel_get(&tex_clr, texX, texYY));
        drawStart++;
    }
    //draw_line(posX * 64, posY * 64, hitX * 64, hitY * 64);
}

void dda_fov(void)
{
    double dirX = game()->raycast.ray_x;
    double dirY = game()->raycast.ray_y;
    double planeX = game()->raycast.plane_x;
    double planeY = game()->raycast.plane_y;
    int i = 0;
    while (i < 1920)
    {
        double cameraX = 2 * i / (double)(1920 - 1) - 1;
        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;
        dda_test(rayDirX, rayDirY, i);
        dda_door(rayDirX, rayDirY, i);
        i++;
    }
}


void	rotate_ray(int dir)
{
	double oldrayX = game()->raycast.ray_x;
    double oldPlaneX = game()->raycast.plane_x;
    double rot = dir * 0.04;

    game()->raycast.ray_x = game()->raycast.ray_x * cos(rot) - game()->raycast.ray_y * sin(rot);
    game()->raycast.ray_y = oldrayX * sin(rot) + game()->raycast.ray_y * cos(rot);

    game()->raycast.plane_x = game()->raycast.plane_x * cos(rot) - game()->raycast.plane_y * sin(rot);
    game()->raycast.plane_y = oldPlaneX * sin(rot) + game()->raycast.plane_y * cos(rot);
}
