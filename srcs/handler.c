/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:36:08 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/22 13:16:26 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void gameplay(void)
{
	mlx_mouse_hook(game()->win, mouse_press, NULL);
	mlx_hook(game()->win, 5, 1L<<3, mouse_press, NULL);
	mlx_hook(game()->win, 6, 1L<<6, mouse_move, NULL);
	mlx_hook(game()->win, 2, 1L<<0, key_press, NULL);
	mlx_hook(game()->win, 3, 1L<<1, key_release, NULL);
	mlx_hook(game()->win, 17, 0, clean_exit, NULL);
	mlx_loop_hook(game()->mlx, loop, NULL);
	mlx_loop(game()->mlx);
}
