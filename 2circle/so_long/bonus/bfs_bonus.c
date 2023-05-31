/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:49:15 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 17:49:20 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

void	q_init(t_game_info *game)
{
	t_node	*node;

	game->q = create_queue();
	game->arr = create_arr(game);
	game->arr[game->player.y][game->player.x] = 0;
	node = create_node(game->player.y, game->player.x);
	direction_insert(game->q, node);
	game->q->visited = visited_init(game);
	vis_init(game, game->q->visited, game->arr);
	free(node);
}

void	discriminate(t_game_info *game)
{
	t_node	*node;

	q_init(game);
	while (game->arr[game->enemy.y][game->enemy.x] == INF)
	{
		node = q_pop(game->q);
		if (node->y <= 0 || node->y >= (int)game->graphic.height || \
				node->x <= 0 || node->x >= (int)game->graphic.width)
		{
			free(node);
			continue ;
		}
		promising(node, game->q, game->arr);
		game->q->visited[node->y][node->x] = 1;
		free(node);
	}
	visited_free(game->q->visited, game->graphic.height);
	enemy_move(game, game->enemy.y, game->enemy.x);
	arr_free(game, game->arr);
	queue_free(game->q->head);
	free(game->q);
}

void	bfs(t_game_info *game)
{
	t_node	*node;

	bfs_init(game);
	while (game->graphic.arr[game->player.y][game->player.x] == INF)
	{
		node = q_pop(game->bfs);
		if (node->y <= 0 || node->y >= (int)game->graphic.height || \
				node->x <= 0 || node->x >= (int)game->graphic.width)
		{
			free(node);
			continue ;
		}
		promising(node, game->bfs, game->graphic.arr);
		game->bfs->visited[node->y][node->x] = 1;
		free(node);
	}
	visited_free(game->bfs->visited, game->graphic.height);
	discriminate(game);
	arr_free(game, game->graphic.arr);
	queue_free(game->bfs->head);
	free(game->bfs);
}

void	enemy_move(t_game_info *game, size_t y, size_t x)
{
	int	**arr;
	int	**arr1;

	if ((int)y <= 0 || (int)y >= (int)game->graphic.height || (int)x <= 0 \
			|| (int)x >= (int)game->graphic.width)
		return ;
	arr = game->graphic.arr;
	arr1 = game->arr;
	if (arr[y - 1][x] == 1 && arr1[y - 1][x] != INF)
		enemy_move_up(game);
	else if (arr[y + 1][x] == 1 && arr1[y + 1][x] != INF)
		enemy_move_down(game);
	else if (arr[y][x + 1] == 1 && arr1[y][x + 1] != INF)
		enemy_move_right(game);
	else if (arr[y][x - 1] == 1 && arr1[y][x - 1] != INF)
		enemy_move_left(game);
	if (game->player.y == game->enemy.y && game->player.x == game->enemy.x)
		game_over(game);
}
