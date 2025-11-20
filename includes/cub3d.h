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
	int			door_tg;
	int			glitch_tg;
	int			restart_tg;
	int			return_menu_tg;
	int			continue_tg;
	int			sens_tg;
	int			diff_tg;
	int			play_tg;
	int			option_tg;
	int			quit_tg;
	int			option_p_tg;
	int			quit_p_tg;
	int			ctrl_tg;
	int			ctrlback_tg;
	int			back_tg;
	int			sleft_tg;
	int			sright_tg;
	int			dleft_tg;
	int			dright_tg;
	int 		anim_tg;
	int			star_tg;
}				t_frame;

typedef	struct s_cord
{
	float	x;
	float	y;
}				t_cord;

typedef	struct s_mouse
{
	int toggle_arrow;
	int	x;
	int	y;
}				t_mouse;

typedef struct s_player
{
	float	start_x;
	float	start_y;
	float	player_x;
	float	player_y;
	int		sprint;
	int		moving_w;
	int		moving_a;
	int		moving_s;
	int		moving_d;
	int		rot_r;
	int		rot_l;
	float 	sprint_count;
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
	int		loaded;
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
	char	**orig;
	char	**map;
	char	**info;
	char	**map_F;
	char	**map_C;
	long F;
	long C;
	int		max_y;
	t_data	north;
	t_data	south;
	t_data	west;
	t_data	east;
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
	G_OVER,
	G_WIN,
	OPT_G,
	CTRL_G,
}				t_state;

typedef	struct	s_glitch
{
	t_data 	glitch[20];
	int		glitch_spawned;
	long	last_glitch_time;
	int		glitch_i;
	int		spread_delay;
	int		to_glitch;
}				t_glitch;

typedef struct s_time
{
	long		level_start;
	long		elapsed_time;
	long		pause_time;
	long		pause_time_start;
	int			minutes;
	int			seconds;
	int			level_time;
}				t_time;

typedef struct s_game
{
	t_data		door[57];
	long		anim;
	t_data	minimap;
	t_data	circle;
	t_data	rays;
	int offset;
	t_time		time;
	int 		release;
	void		*mlx;
	void		*win;
	t_data		g_over;
	t_data		g_win[4];
	t_data		star[4];
	t_data		g_win_bg;
	t_data 		frcg;
	t_frame		frame;
	t_state		state;
	t_data		canvas;
	t_data		wall;
	t_data		floor;
	t_data		closed_door;
	t_data		open_door;
	t_data		timer;
	t_data		timer_nbr[10];
	t_glitch 	glitch;
	t_data		exit;
	t_data		person;
	t_data		pause_bt;
	t_data		return_menu_bt[2];
	t_data		diff_bt;
	t_data		sens_bt;
	t_data		maze_nm;
	t_data		ctrl_menu;
	t_data		*st_anim;
	t_data		play_bt[2];
	t_data		option_bt[2];
	t_data		option_p_bt[2];
	t_data		quit_bt[2];
	t_data		quit_p_bt[2];
	t_data		back_bt[2];
	t_data		ctrlback_bt[2];
	t_data		ctrl_bt[2];
	t_data		left_bt[2];
	t_data		right_bt[2];
	t_data		continue_bt[2];
	t_data		restart_bt[2];
	t_data		sens_nb[5];
	t_data		diff_nb[3];
	t_data		loading_screen;
	t_data		loading_bar[20];
	t_ray		raycast;
	t_map		map;
	t_mouse		mouse;
	t_cord		sleft_c[3];
	t_cord		sright_c[3];
	t_cord		sleft_pause_c[3];
	t_cord		sright_pause_c[3];
	t_cord		dleft_c[3];
	t_cord		dright_c[3];
	t_player	player;
}				t_game;

//fullscreen.c
void	*my_mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title);
void	draw_fc(void);
void	my_mlx_pixel_put2(t_data *data, int x, int y, int color);
void	door_handle(void);
//GNL
# define BUFFER_SIZE 1
# define PI 3.141592653589793
# define P1 "Error\nPlayer not found in the map.\n"
# define P2 "Error\nToo many players found in the map.\n"
# define E1 "Error\nExit not found in the map.\n"
# define E2 "Error\nToo many exits found in the map.\n"

# ifndef FS
#  define FS 0
# endif
char	*get_next_line(int fd);
int		ft_linelen(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_free_bfr(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);

//init.c
char	**init_gameinfo(void);
void 	init(void);
void 	set_fov(double fov_deg);
void	set_rays(char dir);
t_game	*game(void);
void	reinit(void);

//parsing.c
int parsing(char **av);
int map_exists(char *av);
int map_name(char *av);
void	rewrite_map(void);
void	orig_map(void);
void	reset_map(void);
//map_parse.c
int	map_validate(char *av, int fd, int var, char *line);
int map_walls(char *av);
int	map_chars(char *av, int var, int check, int check2);

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
void	singleton_free(int parse);
int clean_exit(void *nada);

//dda.c
void dda_test(double rayDirX, double rayDirY, int drawX);
void dda_fov(void);
void	rotate_ray(int dir);

// door.c
int 	open_door(void);
int 	int_size(long time);
int 	timer(long start, int timer);
void	draw_time(void);

//draw.c
void	draw_img(t_data *src, t_data *dst, int x, int y, float factor);
void draw_line(double rayDirX, double rayDirY);
void	ins_map(void);
void	assign_f(void);
void	assign_c(void);

//str_help.c
int	check_loop(char ***check, char *line, int *var, int var2);
int	line_looping(int fd, int opt, char **line);
int	line_helper(char **line, int var, int *check, int *check2);
int	line_checks(int fd, char **line, int *check, int *check2);
int	alloc_map(int fd, int var, char *av);

//draw_utils.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	my_mlx_pixel_get(t_data *data, int x, int y);
t_data	load_img(char *path);
int	my_mlx_pixel_get_dim(t_data *data, int x, int y, float factor);
t_data	load_img(char *path);
float sign (t_cord p1, t_cord p2, t_cord p3);
int find_point(t_cord pt, t_cord v1, t_cord v2, t_cord v3);
int	ft_usleep(int micro);
char *nbr_hx_clr(int nbr);
int	dim_clr(unsigned int color, float factor);
//handler.c
void gameplay(void);

//m_press.c
int	mouse_press(int keycode, void *nada);
void	main_press(void);
void	opt_m_press(void);
void	ctrl_m_press(void);
void	pause_press(void);
void	opt_p_press(void);
void	ctrl_p_press(void);
void	win_press(void);
void	gover_press(void);
void	opt_g_press(void);
void	ctrl_g_press(void);
int		pause_game(void);

//m_move.c
int	mouse_move(int keycode, t_game *null);
void	main_move(void);
void	opt_m_move(void);
void	ctrl_m_move(void);
void	pause_move(void);
void	opt_p_move(void);
void	ctrl_p_move(void);
void	win_move(void);
void	gover_move(void);
void	opt_g_move(void);
void	ctrl_g_move(void);
void	game_move(int *last_x);

//keys.c
int	key_press(int keycode, t_game *nada);
void	game_press(int keycode);
int	key_release(int keycode, t_game *nada);

//loop.c
int	loop(void *nada);
void	game_loop(int change);
int	menu_put(int keycode, void *nada);
void opt_m_put(void);
void ctrl_m_put(void);
void opt_p_put(void);
void ctrl_p_put(void);
void g_win_put(void);
void g_over_put(void);
void opt_g_put(void);
void ctrl_g_put(void);
int	pause_put(void);

//anim_utils.c
void	draw_dim_img(t_data *src, t_data *dst, int x, int y, float factor);
void	darken(t_data src, float st_factor, float max_factor);
void	lighten(t_data src, float st_factor);


// time.c

long 	get_elapsed_sec(void);
long	get_time(void);
int		tt_glitch_map(void);
int		count_zero(char **map);

// glitch.c

void	glitch_consume(int spawn_delay);
char	**copy_map(char **new_map, char **map_to_copy);
void	set_difficulty(void);

int	count_zero_r(char **map, int y, int x);

//movements.c

void	w_move(int change);
void	a_move(int change);
void	s_move(int change);
void	d_move(int change);
int		check_radius(char keycode, int change);

# endif
