/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:06:18 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/08 21:28:54 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void dda_test(double rayDirX, double rayDirY)
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
        if (game()->map.map[mapY][mapX] == '1')
            hit = 1;
    }
    double perpWallDist;
    if (side == 0)
        perpWallDist = (mapX - posX + (1 - stepX) / 2.0) / rayDirX;
    else
        perpWallDist = (mapY - posY + (1 - stepY) / 2.0) / rayDirY;
    double hitX = posX + rayDirX * perpWallDist;
    double hitY = posY + rayDirY * perpWallDist;

    draw_line(posX * 64, posY * 64, hitX * 64, hitY * 64);
}

void dda_fov(void)
{
    double dirX = game()->raycast.ray_x;
    double dirY = game()->raycast.ray_y;

    double planeX = game()->raycast.plane_x;
    double planeY = game()->raycast.plane_y;

    for (int i = 0; i < 100; i++)
    {
        double cameraX = 2 * i / (double)(100 - 1) - 1;
        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        dda_test(rayDirX, rayDirY);
    }
}


void	rotate_ray(int dir)
{
	double oldrayX = game()->raycast.ray_x;
    double oldPlaneX = game()->raycast.plane_x;
    double rot = dir * 0.035;

    game()->raycast.ray_x = game()->raycast.ray_x * cos(rot) - game()->raycast.ray_y * sin(rot);
    game()->raycast.ray_y = oldrayX * sin(rot) + game()->raycast.ray_y * cos(rot);

    game()->raycast.plane_x = game()->raycast.plane_x * cos(rot) - game()->raycast.plane_y * sin(rot);
    game()->raycast.plane_y = oldPlaneX * sin(rot) + game()->raycast.plane_y * cos(rot);
}