/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:06:02 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/22 19:17:27 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define KEY_L 123
# define KEY_R 124
# define KEY_ESC 53
# define DIRLEFT 123
# define DIRRIGHT 124
# define HEIGHT 480
# define WIDTH 640
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define MOVE_SPD 0.1
# define ROTATE_SPD 0.1
# define PI 3.141592

typedef struct s_img
{
	void	*img;
	int		texture[4][TEXWIDTH * TEXHEIGHT];
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		floor;
	int		ceiling;
	int		width;
	int		height;
}				t_img;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	int				check_flag;
	int				background_flag;
	char			**map;
	int				width;
	int				height;
	int				map_w;
	int				map_h;
	int				buf[HEIGHT][WIDTH];
	int				color;
	int				no_flag;
	int				so_flag;
	int				we_flag;
	int				ea_flag;
	double			player_x;
	double			player_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	struct s_img	*img;
}				t_info;

typedef struct s_dda
{
	int		x;
	int		y;
	int		texnum;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	double	wall_x;
	int		text_x;
	int		text_y;
	double	step;
	double	text_pos;
	double	raydirx0;
	double	raydiry0;
	double	raydirx1;
	double	raydiry1;
	int		p;
	double	pos_z;
	double	floorstep_x;
	double	floorstep_y;
	double	floor_x;
	double	floor_y;
	double	rowdistance;
}				t_dda;

/* gnl part */
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strncat(char *s1, char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* libft part */
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memset(void *b, int c, size_t len);
int		print_error(char *str);

/* parsing part */
int		check_arguments(t_info *info, int fd);
int		check_argu_util(t_info *info, int fd, char **temp, char **tmp);
int		check_map(t_info *info);
int		get_map(t_info *info, int fd);
int		check_first_last(char *map);
int		check_middle(char **all_map, char *map, int r);
int		check_wall(char **map);
void	set_rotate_player(t_info *info, char c, int i, int j);
int		check_line(char *str, char *line);
int		check_line_middle_space(char *str);
char	**make_rotate_map(char **map);
char	**make_check_map(t_info *info);
int		strlen_double_size_arr(char **str);
char	*rearrange_map(int dest, char *str);
int		set_player(t_info *info);
char	*map_join(char *s1, char *s2);
int		set_rgb(t_img *img, char **rgb, int flag);
int		rgb_atoi(char *str);
int		check_texture(t_info *info, t_img *img, char *str);
void	set_texture(t_info *info, t_img *img, char *path, int num);

/* dda algorithm */
void	dda_algorithm(t_info *info, t_dda *dda);
void	init_dda(t_info *info, t_dda *dda);
void	dda_util1(t_info *info, t_dda *dda);
void	dda_util2(t_info *info, t_dda *dda);
void	dda_util3(t_info *info, t_dda *dda);
void	dda_util3_util(t_info *info, t_dda *dda);
void	dda_util4(t_info *info, t_dda *dda);
void	dda_util5(t_info *info, t_dda *dda);

/* main util part */
void	print_info(t_info *info);
int		check_argv(char *str);
void	draw(t_info *info);
void	rotate_right(t_info *info, double radian);
int		strlen_double_size_arr(char **str);
void	two_pointer_free(char **av);
int		main_loop(t_info *info);

/*key util part */
void	key_up(t_info *info);
void	key_down(t_info *info);
void	key_left(t_info *info);
void	key_right(t_info *info);
void	rotate_left(t_info *info, double radian);
void	rotate_right(t_info *info, double radian);
int		exit_program(t_info *info);
int		key_press(int key, t_info *info);

int		check_background_util(t_info *info, char **rgb, int flag);
int		get_map_util(t_info *info, char *line, char *tmp);
void	malloc_err(t_info *info);
#endif
