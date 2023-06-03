/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:27:24 by yeckim            #+#    #+#             */
/*   Updated: 2023/06/04 02:31:43 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define KEY_ESC 53
# define BUFFER_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

typedef struct s_imgs
{
	void	*character;
	void	*wall;
	void	*target;
	void	*escape;
	void	*tiles;
	int		width;
	int		height;
	int		i;
	int		j;
}	t_imgs;

typedef struct s_game_info
{
	size_t	height;
	size_t	width;
	size_t	obj;
	size_t	x;
	size_t	y;
	size_t	objs;
	size_t	total_step;
	char	*map;
	char	**all_map;
	void	*mlx;
	void	*mlx_win;
	t_imgs	imgs;
}	t_game_info;

typedef struct s_dfs
{
	size_t	exit_cnt;
	size_t	objs;
	int		**visited;
}	t_dfs;

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
char	*make_backup(char *line);
char	*make_line(int fd, char *backup, char *buf, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	pos_init(t_game_info *game);
int		key_press(int key, t_game_info *game);
void	read_map(char *filename, t_game_info *game);
char	**ft_split(const char *s, char c);
void	ft_putstr(char *str, int fd);
void	err(char *str);
void	imgs_init(void *mlx, t_imgs *imgs);
void	drawing_map(void *mlx, void *mlx_win, t_imgs *imgs, t_game_info *game);
int		key_up(t_game_info *game);
int		key_down(t_game_info *game);
int		key_left(t_game_info *game);
int		key_right(t_game_info *game);
void	print_steps(int steps);
void	clearable_check(t_game_info *game);
void	exit_check(t_game_info *game, t_dfs *dfs, size_t x, size_t y);
char	*ft_itoa(int n);
void	info_init(t_game_info *game, char *line);
char	*file(char *name);
#endif
