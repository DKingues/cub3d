/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:29:52 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/21 13:30:21 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_multiple_images(t_data *texture, char *path, int quantity)
{
	int		i;
	char	*str;
	char	*nbr;

	i = 0;
	while (i < quantity)
	{
		nbr = ft_itoa(i);
		str = ft_strjoin(ft_strdup(path), nbr);
		str = ft_strjoin(str, ".xpm");
		load_full_img(&texture[i], str);
		free(str);
		free(nbr);
		i++;
	}
}

void	set_difficulty(void)
{
	if (game()->frame.diff_tg == 0)
		game()->glitch.spread_delay = 4;
	else if (game()->frame.diff_tg == 1)
		game()->glitch.spread_delay = 2;
	else if (game()->frame.diff_tg == 2)
		game()->glitch.spread_delay = 1;
	game()->time.level_time = tt_glitch_map();
}

void	reinit3(void)
{
	game()->player.rot_l = 0;
	game()->player.rot_r = 0;
	game()->frame.door_tg = 0;
	game()->mouse.x = 0;
	game()->mouse.y = 0;
	game()->glitch.to_glitch = 0;
	game()->time.pause_time_start = -1;
	game()->time.pause_time = 0;
}

void	reinit2(void)
{
	game()->time.level_start = -1;
	game()->frame.return_menu_tg = 0;
	game()->frame.restart_tg = 0;
	game()->frame.glitch_tg = 0;
	game()->frame.continue_tg = 0;
	game()->frame.anim_tg = 0;
	game()->frame.play_tg = 0;
	game()->frame.option_tg = 0;
	game()->frame.ctrl_tg = 0;
	game()->frame.quit_tg = 0;
	game()->frame.sleft_tg = 0;
	game()->frame.sright_tg = 0;
	game()->frame.dleft_tg = 0;
	game()->frame.dright_tg = 0;
	game()->frame.back_tg = 0;
	game()->frame.ctrlback_tg = 0;
	game()->frame.quit_p_tg = 0;
	game()->frame.option_p_tg = 0;
	game()->frame.star_tg = 0;
	game()->player.sprint = 0;
	game()->player.sprint_count = 100;
	game()->player.moving_w = 0;
	game()->player.moving_a = 0;
	game()->player.moving_s = 0;
	game()->player.moving_d = 0;
}

t_game	*game(void)
{
	static t_game	g;

	return (&g);
}
