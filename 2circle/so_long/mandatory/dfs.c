/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:41:24 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/17 03:50:00 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/so_long.h"

void	visited_free(int **visited, int j)
{
	size_t	i;

	i = 0;
	while (i < (size_t)j)
		free(visited[i++]);
	free(visited);
}

int	**visited_init(t_game_info *game)
{
	int		**vis;
	int		i;
	int		j;

	vis = (int **)malloc(sizeof(int *) * game->height);
	if (vis == NULL)
		return (0);
	i = -1;
	while ((size_t)++i < game->height)
	{
		vis[i] = (int *)malloc(sizeof(int) * game->width);
		if (vis[i] == NULL)
		{
			visited_free(vis, i);
			return (0);
		}
	}
	i = -1;
	while ((size_t)++i < game->height)
	{
		j = -1;
		while ((size_t)++j < game->width)
			vis[i][j] = 0;
	}
	return (vis);
}

int	target_promising(t_game_info *game, t_dfs *dfs, size_t x, size_t y)
{
	if (game->all_map[y][x] == '1' || game->all_map[y][x] == 'E' || \
			dfs->visited[y][x] || !dfs->objs)
		return (0);
	if (game->all_map[y][x] == 'C')
		dfs->objs--;
	dfs->visited[y][x] = 1;
	return (1);
}

void	target_check(t_game_info *game, t_dfs *dfs, size_t x, size_t y)
{
	if (target_promising(game, dfs, x + 1, y))
		target_check(game, dfs, x + 1, y);
	if (target_promising(game, dfs, x - 1, y))
		target_check(game, dfs, x - 1, y);
	if (target_promising(game, dfs, x, y + 1))
		target_check(game, dfs, x, y + 1);
	if (target_promising(game, dfs, x, y - 1))
		target_check(game, dfs, x, y - 1);
}

void	clearable_check(t_game_info *game)
{
	t_dfs	dfs;

	dfs.exit_cnt = 0;
	dfs.objs = game->objs;
	dfs.visited = visited_init(game);
	if (dfs.visited == NULL)
		return ;
	target_check(game, &dfs, game->x, game->y);
	visited_free(dfs.visited, game->height);
	dfs.visited = visited_init(game);
	if (dfs.visited == NULL)
		return ;
	exit_check(game, &dfs, game->x, game->y);
	visited_free(dfs.visited, game->height);
	if (dfs.objs || !dfs.exit_cnt)
		err("Unclearable Map\n");
}
