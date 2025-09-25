/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:05:05 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/09/16 18:21:54 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include "../minilibx-linux/mlx.h"
# include "../includes/libft/libft.h"

typedef struct s_img
{
	int	img_x;
	int	img_y;
}				t_img;

typedef struct s_game
{
	char **map;
	char **info;
	char **map_F;
	char **map_C;
	int		max_y;
	t_img	img;
}				t_game;

//GNL

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_linelen(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_free_bfr(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);

//init.c
void	init_gameinfo(void);
t_game *game(void);

//parsing.c

int parsing(char **av);
int map_exists(char *av);
int map_name(char *av);

//map_parse.c
int	map_validate(char *av);
int map_walls(char *av);
int	map_chars(char *av);

//file_parse.c
int	map_textures(void);
int	map_colors(void);
int texture_img(char *av);

//utils.c
void	freeandcopy(int pos, char *line);
void	set_gameinfo(char *line);
int	fill(int x, int y);
int texture_name(char *av);
char	*ft_strdupnonl(const char *s);

//cleanup.c
void	singleton_free(void);

#endif