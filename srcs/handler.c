/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:27:55 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/20 11:57:15 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	pause_game(void)
{
	darken(game()->canvas, 0.40);
	game()->state = PAUSE;
	game()->player.moving_w = 0;
	game()->player.moving_a = 0;
	game()->player.moving_s = 0;
	game()->player.moving_d = 0;
	game()->player.rot_r = 0;
	game()->player.rot_l = 0;
	return (0);
}
