/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:05:39 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/24 15:17:28 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	game_over_check(void)
{
	int	player_y;
	int	player_x;

	player_y = game()->player.player_y;
	player_x = game()->player.player_x;
	if (game()->map.map[player_y][player_x] == 'G'
		|| (game()->time.minutes == 0 && game()->time.seconds == 0))
	{
		darken(game()->canvas, 1.0, -0.05);
		lighten(game()->st_anim[game()->frame.anim_tg], 0.0);
		game()->state = G_OVER;
		return (1);
	}
	return (0);
}

void	movement(int change)
{
	if (game()->player.sprint == 1
		&& game()->player.sprint_count > game()->offset
		&& (game()->player.moving_w == 1 || game()->player.moving_s == 1
			|| game()->player.moving_a == 1 || game()->player.moving_d == 1))
	{
		game()->player.sprint_count -= 1;
		change = 9;
	}
	else
		if (game()->player.sprint_count < 100)
			game()->player.sprint_count += 0.25;
	if (game()->player.moving_d == 1)
		d_move(change);
	if (game()->player.moving_s == 1)
		s_move(change);
	if (game()->player.moving_a == 1)
		a_move(change);
	if (game()->player.moving_w == 1)
		w_move(change);
	if (game()->player.rot_l == 1)
		rotate_ray(-1);
	if (game()->player.rot_r == 1)
		rotate_ray(1);
}

void	game_loop(int change)
{
	timer(game()->time.level_start, game()->time.level_time);
	glitch_consume(6);
	if (game()->player.sprint_count == 0)
		game()->offset = 5;
	else if (game()->player.sprint_count == 5)
		game()->offset = 0;
	movement(change);
	door_handle();
	ins_map();
	if (!game_over_check())
		mlx_put_image_to_window(game()->mlx,
			game()->win, game()->canvas.img, 0, 0);
}

int	menu_put(int keycode, void *nada)
{
	t_data	temp;

	(void)keycode;
	(void)nada;
	if (game()->frame.anim_tg == 167)
		game()->frame.anim_tg = 0;
	temp.img = mlx_new_image(game()->mlx, 1920, 1080);
	temp.addr = mlx_get_data_addr(temp.img,
			&temp.bits_per_pixel, &temp.line_length,
			&temp.endian);
	draw_img(&game()->st_anim[game()->frame.anim_tg], &temp, 0, 0);
	draw_img(&game()->maze_nm, &temp, 404, 166);
	draw_img(&game()->play_bt[game()->frame.play_tg], &temp, 672, 500);
	draw_img(&game()->option_bt[game()->frame.option_tg], &temp, 672, 666);
	draw_img(&game()->quit_bt[game()->frame.quit_tg], &temp, 672, 831);
	mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 0, 0);
	game()->frame.anim_tg++;
	ft_usleep(15000);
	mlx_destroy_image(game()->mlx, temp.img);
	return (0);
}

void	opt_m_put_aux(t_data temp)
{
	if (game()->frame.diff_tg == 0)
		draw_img(&game()->diff_nb[0], &temp, 1128, 579);
	else if (game()->frame.diff_tg == 1)
		draw_img(&game()->diff_nb[1], &temp, 1095, 579);
	else if (game()->frame.diff_tg == 2)
		draw_img(&game()->diff_nb[2], &temp, 1128, 579);
}
