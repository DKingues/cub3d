/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:06:02 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/24 15:20:40 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	opt_m_put(void)
{
	t_data	temp;

	if (game()->frame.anim_tg == 167)
		game()->frame.anim_tg = 0;
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
			&temp.bits_per_pixel, &temp.line_length,
			&temp.endian);
	draw_img(&game()->st_anim[game()->frame.anim_tg], &temp, 0, 0);
	draw_img(&game()->option_bt[1], &temp, 672, 234);
	draw_img(&game()->sens_bt, &temp, 532, 462);
	draw_img(&game()->diff_bt, &temp, 532, 562);
	draw_img(&game()->ctrl_bt[game()->frame.ctrl_tg], &temp, 532, 663);
	draw_img(&game()->back_bt[game()->frame.back_tg], &temp, 532, 764);
	draw_img(&game()->left_bt[game()->frame.sleft_tg], &temp, 1005, 484);
	draw_img(&game()->right_bt[game()->frame.sright_tg], &temp, 1353, 484);
	draw_img(&game()->left_bt[game()->frame.dleft_tg], &temp, 1005, 579);
	draw_img(&game()->right_bt[game()->frame.dright_tg], &temp, 1353, 579);
	draw_img(&game()->sens_nb[game()->frame.sens_tg], &temp, 1178, 484);
	opt_m_put_aux(temp);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	game()->frame.anim_tg++;
	ft_usleep(15000);
	mlx_destroy_image(game()->mlx, temp.img);
}

void	ctrl_m_put(void)
{
	t_data	temp;

	if (game()->frame.anim_tg == 167)
		game()->frame.anim_tg = 0;
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
			&temp.bits_per_pixel, &temp.line_length,
			&temp.endian);
	draw_img(&game()->st_anim[game()->frame.anim_tg], &temp, 0, 0);
	draw_img(&game()->ctrl_menu, &temp, 0, 0);
	draw_img(&game()->ctrlback_bt[game()->frame.ctrlback_tg],
		&temp, 362, 914);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	game()->frame.anim_tg++;
	ft_usleep(15000);
	mlx_destroy_image(game()->mlx, temp.img);
}

int	pause_put(void)
{
	t_data	temp;

	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
			&temp.bits_per_pixel, &temp.line_length,
			&temp.endian);
	draw_sp_img(&game()->canvas, &temp, 0, 0.4);
	draw_img(&game()->pause_bt, &temp, 672, 236);
	draw_img(&game()->continue_bt[game()->frame.continue_tg],
		&temp, 754, 412);
	draw_img(&game()->option_p_bt[game()->frame.option_p_tg],
		&temp, 754, 613);
	draw_img(&game()->restart_bt[game()->frame.restart_tg],
		&temp, 754, 513);
	draw_img(&game()->return_menu_bt[game()->frame.return_menu_tg],
		&temp, 754, 713);
	draw_img(&game()->quit_p_bt[game()->frame.quit_p_tg],
		&temp, 754, 814);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	mlx_destroy_image(game()->mlx, temp.img);
	return (0);
}

void	opt_p_put(void)
{
	t_data	temp;

	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
			&temp.bits_per_pixel, &temp.line_length,
			&temp.endian);
	draw_sp_img(&game()->canvas, &temp, 0, 0.4);
	draw_img(&game()->option_bt[1], &temp, 672, 286);
	draw_img(&game()->sens_bt, &temp, 531, 512);
	draw_img(&game()->left_bt[game()->frame.sleft_tg], &temp, 989, 535);
	draw_img(&game()->right_bt[game()->frame.sright_tg], &temp, 1337, 535);
	draw_img(&game()->sens_nb[game()->frame.sens_tg], &temp, 1162, 536);
	draw_img(&game()->ctrl_bt[game()->frame.ctrl_tg], &temp, 532, 612);
	draw_img(&game()->back_bt[game()->frame.back_tg], &temp, 532, 713);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	mlx_destroy_image(game()->mlx, temp.img);
}

void	ctrl_p_put(void)
{
	t_data	temp;

	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
			&temp.bits_per_pixel, &temp.line_length,
			&temp.endian);
	draw_sp_img(&game()->canvas, &temp, 0, 0.4);
	draw_img(&game()->ctrl_menu, &temp, 0, 0);
	draw_img(&game()->ctrlback_bt[game()->frame.ctrlback_tg],
		&temp, 362, 914);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	mlx_destroy_image(game()->mlx, temp.img);
}
