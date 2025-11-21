/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:20:42 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/21 13:30:16 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**init_gameinfo(void)
{
	int		var;
	char	**check;
	char	**line;

	var = 0;
	check = ft_calloc(7, sizeof(char *));
	line = ft_calloc(7, sizeof(char *));
	game()->map.info = line;
	while (var < 6)
	{
		game()->map.info[var] = ft_strdup("init");
		var++;
	}
	check[0] = ft_strdup("NO ");
	check[1] = ft_strdup("SO ");
	check[2] = ft_strdup("WE ");
	check[3] = ft_strdup("EA ");
	check[4] = ft_strdup("F ");
	check[5] = ft_strdup("C ");
	return (check);
}

void	draw_loading(int i)
{
	static int	j = 0;
	t_data		temp;

	if ((i % 8 == 0 || i == 166) && j < 20)
	{
		temp.img = mlx_new_image(game()->mlx, 1218, 32);
		temp.addr = mlx_get_data_addr(temp.img,
				&temp.bits_per_pixel, &temp.line_length,
				&temp.endian);
		draw_img(&game()->loading_bar[j++], &temp, 0, 0, 1.0);
		mlx_put_image_to_window(game()->mlx, game()->win, temp.img, 351, 826);
		mlx_destroy_image(game()->mlx, temp.img);
	}
}

void	init_vid(void)
{
	int		var;
	char	*str;
	char	*temp;

	game()->st_anim = ft_calloc(sizeof(t_data), 168);
	var = 0;
	while (var < 167)
	{
		draw_loading(var);
		temp = ft_itoa(var + 1);
		str = ft_strjoin(ft_strdup("textures/menu_vid/"), temp);
		str = ft_strjoin(str, ".xpm");
		game()->st_anim[var] = load_img(str);
		game()->st_anim[var].res_x = 1920;
		game()->st_anim[var].res_y = 1080;
		var++;
		free(str);
		free(temp);
	}
}

int	get_res(char id, char *path)
{
	int		fd;
	char	*line;
	char	**res;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	while (line[0] != '\"')
	{
		free(line);
		line = get_next_line(fd);
	}
	res = ft_split(&line[1], ' ');
	close(fd);
	free(line);
	if (id == 'x')
		fd = ft_atoi(res[0]);
	else if (id == 'y')
		fd = ft_atoi(res[1]);
	else
		clean_exit(NULL);
	ft_free(res);
	return (fd);
}

void	load_full_img(t_data *texture, char *path)
{
	(*texture) = load_img(path);
	(*texture).res_x = get_res('x', path);
	(*texture).res_y = get_res('y', path);
}
