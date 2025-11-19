/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:20:48 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/19 12:28:47 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	destroy_image_safe(void *mlx, t_data texture)
{
	if(texture.img && texture.loaded == 1)
		mlx_destroy_image(mlx, texture.img);
}

static void	mlx_destroy_image_arr(void *mlx, t_data *texture, int quantity)
{
	int	i;

	i = 0;
	while (i < quantity)
	{
		if(texture && texture[i].img && texture[i].loaded == 1)
			mlx_destroy_image(mlx, texture[i].img);
		i++;
	}
}
void	singleton_free(int parse)
{
	if(game()->map.map)
		ft_free(game()->map.map);
	if(game()->map.info)
		ft_free(game()->map.info);
	if (game()->map.orig)
		ft_free(game()->map.orig);
	if(parse == 1)
	{
		if (game()->map.map_C)
			ft_free(game()->map.map_C);
		if (game()->map.map_F)
			ft_free(game()->map.map_F);
	}
}

int clean_exit(void *nada)
{
	(void)nada;
	destroy_image_safe(game()->mlx, game()->canvas);
	destroy_image_safe(game()->mlx, game()->minimap);
	destroy_image_safe(game()->mlx, game()->map.north);
	destroy_image_safe(game()->mlx, game()->map.south);
	destroy_image_safe(game()->mlx, game()->map.east);
	destroy_image_safe(game()->mlx, game()->map.west);
	destroy_image_safe(game()->mlx, game()->wall);
	destroy_image_safe(game()->mlx, game()->floor);
	destroy_image_safe(game()->mlx, game()->person);
	destroy_image_safe(game()->mlx, game()->loading_screen);
	destroy_image_safe(game()->mlx, game()->rays);
	destroy_image_safe(game()->mlx, game()->maze_nm);
	destroy_image_safe(game()->mlx, game()->ctrl_menu);
	destroy_image_safe(game()->mlx, game()->diff_bt);
	destroy_image_safe(game()->mlx, game()->sens_bt);
	destroy_image_safe(game()->mlx, game()->g_over);
	destroy_image_safe(game()->mlx, game()->g_win_bg);
	destroy_image_safe(game()->mlx, game()->pause_bt);
	destroy_image_safe(game()->mlx, game()->exit);
	destroy_image_safe(game()->mlx, game()->closed_door);
	destroy_image_safe(game()->mlx, game()->open_door);
	destroy_image_safe(game()->mlx, game()->timer);
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
	if(game()->st_anim)
		free(game()->st_anim);
	free(game()->mlx);
	singleton_free(0);
	exit(0);
	return (0);
}
