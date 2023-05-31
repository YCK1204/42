/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:25:34 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 01:38:08 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

void	queue_free(t_node *node)
{
	if (node->next != NULL)
		queue_free(node->next);
	free(node);
}

void	promising(t_node *node, t_bfs *q, int **arr)
{	
	if (arr[node->y][node->x] == -1 || q->visited[node->y][node->x])
		return ;
	init_arr(node, arr);
	direction_insert(q, node);
}

void	init_arr(t_node *node, int **arr)
{
	int	ret;

	ret = INF;
	if (arr[node->y][node->x + 1] != -1 && arr[node->y][node->x + 1] < ret)
		ret = arr[node->y][node->x + 1];
	if (arr[node->y][node->x - 1] != -1 && arr[node->y][node->x - 1] < ret)
		ret = arr[node->y][node->x - 1];
	if (arr[node->y + 1][node->x] != -1 && arr[node->y + 1][node->x] < ret)
		ret = arr[node->y + 1][node->x];
	if (arr[node->y - 1][node->x] != -1 && arr[node->y - 1][node->x] < ret)
		ret = arr[node->y - 1][node->x];
	if (ret + 1 < arr[node->y][node->x] && ret != INF)
		arr[node->y][node->x] = ret + 1;
}

int	**create_arr(t_game_info *game)
{
	int	i;
	int	j;
	int	**t;

	i = -1;
	t = (int **)malloc(sizeof(int *) * game->graphic.height);
	while ((size_t)++i < game->graphic.height)
		t[i] = (int *)malloc(sizeof(int) * game->graphic.width);
	i = -1;
	while ((size_t)++i < game->graphic.height)
	{
		j = -1;
		while ((size_t)++j < game->graphic.width)
		{
			if (game->graphic.all_map[i][j] == '1' || \
					game->graphic.all_map[i][j] == 'E')
				t[i][j] = -1;
			else
				t[i][j] = INF;
		}
	}
	return (t);
}

void	direction_insert(t_bfs *queue, t_node *node)
{
	insert_queue(queue, create_node(node->y - 1, node->x));
	insert_queue(queue, create_node(node->y, node->x - 1));
	insert_queue(queue, create_node(node->y, node->x + 1));
	insert_queue(queue, create_node(node->y + 1, node->x));
}
