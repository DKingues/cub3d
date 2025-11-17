/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:20:48 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/17 18:10:41 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	mlx_destroy_image_arr(void *mlx, t_data *texture, int quantity)
{
	int	i;

	i = 0;
	while (i < quantity)
	{
		mlx_destroy_image(mlx, texture[i].img);
		i++;
	}
}
void	singleton_free(void)
{
	if(game()->map.map)
		ft_free(game()->map.map);
	if(game()->map.info)
		ft_free(game()->map.info);
	if (game()->map.orig)
		ft_free(game()->map.orig);
}

int clean_exit(void *nada)
{
	(void)nada;
	mlx_destroy_image(game()->mlx, game()->canvas.img);
	mlx_destroy_image(game()->mlx, game()->minimap.img);
	mlx_destroy_image(game()->mlx, game()->map.north.img);
	mlx_destroy_image(game()->mlx, game()->map.south.img);
	mlx_destroy_image(game()->mlx, game()->map.east.img);
	mlx_destroy_image(game()->mlx, game()->map.west.img);
	mlx_destroy_image(game()->mlx, game()->wall.img);
	mlx_destroy_image(game()->mlx, game()->floor.img);
	mlx_destroy_image(game()->mlx, game()->person.img);
	mlx_destroy_image(game()->mlx, game()->loading_screen.img);
	mlx_destroy_image(game()->mlx, game()->rays.img);
	mlx_destroy_image(game()->mlx, game()->maze_nm.img);
	mlx_destroy_image(game()->mlx, game()->ctrl_menu.img);
	mlx_destroy_image(game()->mlx, game()->diff_bt.img);
	mlx_destroy_image(game()->mlx, game()->sens_bt.img);
	mlx_destroy_image(game()->mlx, game()->g_over.img);
	mlx_destroy_image(game()->mlx, game()->g_win_bg.img);
	mlx_destroy_image(game()->mlx, game()->pause_bt.img);
	mlx_destroy_image(game()->mlx, game()->exit.img);
	mlx_destroy_image(game()->mlx, game()->closed_door.img);
	mlx_destroy_image(game()->mlx, game()->open_door.img);
	mlx_destroy_image(game()->mlx, game()->timer.img);
	mlx_destroy_image_arr(game()->mlx, game()->g_win, 4);
	mlx_destroy_image_arr(game()->mlx, game()->star, 4);
	mlx_destroy_image_arr(game()->mlx, game()->return_menu_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->door, 56);
	mlx_destroy_image_arr(game()->mlx, game()->restart_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->play_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->option_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->quit_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->back_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->ctrl_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->ctrlback_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->left_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->right_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->sens_nb, 5);
	mlx_destroy_image_arr(game()->mlx, game()->diff_nb, 3);
	mlx_destroy_image_arr(game()->mlx, game()->continue_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->option_p_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->quit_p_bt, 2);
	mlx_destroy_image_arr(game()->mlx, game()->glitch.glitch, 20);
	mlx_destroy_image_arr(game()->mlx, game()->timer_nbr, 10);
	mlx_destroy_image_arr(game()->mlx, game()->loading_bar, 20);
	mlx_destroy_image_arr(game()->mlx, game()->st_anim, 167);
	mlx_destroy_window(game()->mlx, game()->win);
	mlx_destroy_display(game()->mlx);
	free(game()->st_anim);
	free(game()->mlx);
	singleton_free();
	exit(0);
	return (0);
}
