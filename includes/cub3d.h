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

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../includes/libft/libft.h"

typedef	struct s_frame
{
	int			play_tg;
	int			option_tg;
	int			ctrl_tg;
	int			back_tg;
	int			sleft_tg;
	int			sright_tg;
	int			dleft_tg;
	int			dright_tg;
	int			quit_tg;
	int 		anim_tg;
}				t_frame;

typedef	struct s_mouse
{
	int toggle_arrow;
	int	x;
	int	y;
}				t_mouse;

typedef struct s_player
{
	float	player_x;
	float	player_y;
	int		diff;
	int		moving_w;
	int		moving_a;
	int		moving_s;
	int		moving_d;
	int		rot_r;
	int		rot_l;
}				t_player;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		img_x;
	int		img_y;
	int		w;
	int		h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		res_x;
	int		res_y;
}				t_data;

typedef struct s_ray
{
	double	plane_x;
	double	plane_y;
	double	ray_x;
	double	ray_y;
}				t_ray;

typedef struct s_map
{
	char	**map;
	char	**info;
	char	**map_F;
	char	**map_C;
	int		max_y;
}				t_map;

typedef enum s_state
{
	MENU,
	OPT_M,
	CTRL_M,
	PAUSE,
	OPT_P,
	CTRL_P,
	GAME,
}				t_state;

typedef struct s_game
{
	t_frame		frame;
	t_state		state;
	void		*mlx;
	void		*win;
	t_data		canvas;
	t_data		wall;
	t_data		floor;
	t_data		person;
	t_data		p_menu;
	t_data		pause;
	t_data		diff_bt;
	t_data		sens_bt;
	t_data		maze_nm;
	t_data		*st_anim;
	t_data		*st_anim2;
	t_data		play_bt[2];
	t_data		option_bt[2];
	t_data		quit_bt[2];
	t_data		back_bt[2];
	t_data		ctrl_bt[2];
	t_data		left_bt[2];
	t_data		right_bt[2];
	t_data		credits;
	t_ray		raycast;
	t_map		map;
	t_mouse		mouse;
	t_player	player;
}				t_game;

//temp
void	darken(t_data src, float max_factor);
void	lighten(t_data src);
int pause_menu(int keycode, void *nada);
int	pause_game(void);
int	mouse_press(int keycode, void *nada);
int	vid_put(int keycode, void *nada);
void	draw_dim_img(t_data *src, t_data *dst, int x, int y, float factor);
int	ft_usleep(int micro);
//GNL
# define BUFFER_SIZE 1
# define PI 3.141592653589793
# define MOUSE_SENS 3

char	*get_next_line(int fd);
int		ft_linelen(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_free_bfr(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);

//init.c
void	init_gameinfo(void);
void 	init(void);
void 	set_fov(double fov_deg);
void	set_rays(char dir);
t_game	*game(void);

//parsing.c
int parsing(char **av);
int map_exists(char *av);
int map_name(char *av);
void	rewrite_map(void);

//map_parse.c
int	map_validate(char *av);
int map_walls(char *av);
int	map_chars(char *av);

//file_parse.c
int	map_textures(void);
int	map_colors(void);
int texture_img(char *av);

//mem_utils.c
void	freeandcopy(int pos, char *line);
void	set_gameinfo(char *line);
int	fill(int x, int y);
int texture_name(char *av);
char	*ft_strdupnonl(const char *s);

//cleanup.c
void	singleton_free(void);
int clean_exit(void *nada);

//dda.c
void dda_test(double rayDirX, double rayDirY);
void dda_fov(void);
void	rotate_ray(int dir);

//draw.c
void	draw_img(t_data *src, t_data *dst, int x, int y);
void draw_line(float x0, float y0, float x1, float y1);
void	ins_map(void);

//draw_utils.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	my_mlx_pixel_get(t_data *data, int x, int y);
t_data	load_img(char *path);
int	my_mlx_pixel_get_dim(t_data *data, int x, int y, float factor);
//hooks.c
void gameplay(void);
int	move(void *nada);
int	key_press(int keycode, t_game *nada);
int	key_release(int keycode, t_game *nada);

//mouse.c
int	mouse_move(int keycode, t_game *null);
int	mouse_release(int keycode, t_game *null);

#endif
