/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:09 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/23 15:19:40 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

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

	vis = (int **)malloc(sizeof(int *) * game->graphic.height);
	if (vis == NULL)
		return (0);
	i = -1;
	while ((size_t)++i < game->graphic.height)
	{
		vis[i] = (int *)malloc(sizeof(int) * game->graphic.width);
		if (vis[i] == NULL)
		{
			visited_free(vis, i + 1);
			return (0);
		}
	}
	i = -1;
	while ((size_t)++i < game->graphic.height)
	{
		j = -1;
		while ((size_t)++j < game->graphic.width)
			vis[i][j] = 0;
	}
	return (vis);
}

int	target_promising(t_game_info *game, t_dfs *dfs, size_t x, size_t y)
{
	if (game->graphic.all_map[y][x] == '1' || \
			game->graphic.all_map[y][x] == 'E' || \
			dfs->visited[y][x] || !dfs->objs)
		return (0);
	if (game->graphic.all_map[y][x] == 'C')
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
	target_check(game, &dfs, game->player.x, game->player.y);
	visited_free(dfs.visited, game->graphic.height);
	dfs.visited = visited_init(game);
	if (dfs.visited == NULL)
		return ;
	exit_check(game, &dfs, game->player.x, game->player.y);
	visited_free(dfs.visited, game->graphic.height);
	if (dfs.objs || !dfs.exit_cnt)
		err("Unclearable Map\n");
}
