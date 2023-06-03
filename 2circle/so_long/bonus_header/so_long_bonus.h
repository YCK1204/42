/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:27:24 by yeckim            #+#    #+#             */
/*   Updated: 2023/06/04 02:31:59 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define KEY_ESC 53
# define BUFFER_SIZE 5
# define INF 2147483647
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include "../mlx/mlx.h"

typedef struct s_a
{
	void	*temp;
	int		width;
	int		height;
}	t_v;

typedef struct s_imgs
{
	t_v		c[4][4];
	t_v		g[4][4];
	t_v		wall;
	t_v		target;
	t_v		escape;
	t_v		tiles;
	int		i;
	int		j;
}	t_imgs;

typedef struct s_enemy_info
{
	size_t	direction;
	size_t	x;
	size_t	y;
}	t_enemy;

typedef struct s_char_info
{
	size_t	x;
	size_t	y;
	size_t	step;
	size_t	direction;
	size_t	steps;
}	t_player;

typedef struct s_graphic
{
	size_t	height;
	size_t	width;
	char	*map;
	char	**all_map;
	char	**graph;
	int		**arr;
	void	*mlx;
	void	*mlx_win;
}	t_graphic;

typedef struct s_node
{
	int				y;
	int				x;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_bfs
{
	t_node	*head;
	t_node	*tail;
	int		**visited;
	int		up;
	int		left;
	int		right;
	int		down;
}	t_bfs;

typedef struct s_game_info
{
	size_t		objs;
	double		play_time;
	double		time;
	int			**arr;
	t_graphic	graphic;
	t_player	player;
	t_enemy		enemy;
	t_imgs		imgs;
	t_bfs		*bfs;
	t_bfs		*q;
}	t_game_info;

typedef struct s_dfs
{
	size_t	exit_cnt;
	size_t	objs;
	int		**visited;
}	t_dfs;

char	*file(char *name);
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
void	read_map(char *temp, t_game_info *game);
char	**ft_split(const char *s, char c);
void	ft_putstr(char *str, int fd);
void	err(char *str);
void	imgs_init(void *mlx, t_imgs *i);
void	imgs_init1(void *mlx, t_imgs *i);
void	imgs_init2(void *mlx, t_imgs *i);
void	drawing_map(void *mlx, void *mlx_win, t_imgs *imgs, t_game_info *game);
void	key_up(t_game_info *game);
void	key_down(t_game_info *game);
void	key_left(t_game_info *game);
void	key_right(t_game_info *game);
int		print_time_steps(t_game_info *game);
void	clearable_check(t_game_info *game);
void	exit_check(t_game_info *game, t_dfs *dfs, size_t x, size_t y);
char	*ft_itoa(int n);
void	info_init(t_game_info *game, char *line);
int		**visited_init(t_game_info *game);
int		game_over(t_game_info *game);
void	graph_init(t_game_info *game);
void	bfs(t_game_info *game);
void	enemy_pos_init(t_game_info *game);
void	enemy_move_left(t_game_info *game);
void	enemy_move_down(t_game_info *game);
void	enemy_move_up(t_game_info *game);
void	enemy_move_right(t_game_info *game);
void	enemy_move(t_game_info *game, size_t y, size_t x);
void	insert_queue(t_bfs *queue, t_node *node);
t_bfs	*create_queue(void);
t_node	*q_pop(t_bfs *queue);
t_node	*create_node(size_t y, size_t x);
void	queue_free(t_node *node);
void	promising(t_node *node, t_bfs *q, int **arr);
void	init_arr(t_node *node, int **arr);
int		**create_arr(t_game_info *game);
void	direction_insert(t_bfs *queue, t_node *node);
void	enemy_pos_init(t_game_info *game);
void	graph_init(t_game_info *game);
void	visited_free(int **visited, int j);
void	bfs_init(t_game_info *game);
void	arr_free(t_game_info *game, int **arr);
void	vis_init(t_game_info *game, int **vis, int **arr);
#endif
