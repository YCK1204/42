/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:49:10 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 17:49:14 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

void	enemy_pos_init(t_game_info *game)
{
	int	i;
	int	j;

	i = -1;
	while ((size_t)++i < game->graphic.height)
	{
		j = -1;
		while ((size_t)++j < game->graphic.width)
		{
			if (game->graphic.all_map[i][j] == 'G')
			{
				game->enemy.x = j;
				game->enemy.y = i;
			}
		}
	}
	pos_init(game);
	imgs_init(game->graphic.mlx, &game->imgs);
	clearable_check(game);
}

void	graph_init(t_game_info *game)
{
	int		i;

	game->graphic.graph = (char **)malloc(sizeof(char *) * \
			game->graphic.height + 1);
	i = -1;
	while ((size_t)++i < game->graphic.height)
		game->graphic.graph[i] = ft_strdup(game->graphic.all_map[i]);
	game->graphic.graph[game->graphic.height] = NULL;
}

void	arr_free(t_game_info *game, int **arr)
{
	size_t	i;

	i = 0;
	while (i < game->graphic.height)
		free(arr[i++]);
	free(arr);
}

void	bfs_init(t_game_info *game)
{
	t_node	*node;

	game->bfs = create_queue();
	game->graphic.arr = create_arr(game);
	game->graphic.arr[game->enemy.y][game->enemy.x] = 0;
	node = create_node(game->enemy.y, game->enemy.x);
	direction_insert(game->bfs, node);
	game->bfs->visited = visited_init(game);
	vis_init(game, game->bfs->visited, game->graphic.arr);
	free(node);
}

void	vis_init(t_game_info *game, int **vis, int **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->graphic.height)
	{
		j = 0;
		while (j < game->graphic.width)
		{
			if (arr[i][j] == -1)
				vis[i][j]++;
			j++;
		}
		i++;
	}
}
