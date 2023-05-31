/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:48:28 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/17 07:01:16 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/so_long.h"

int	exit_promising(t_game_info *game, t_dfs *dfs, size_t x, size_t y)
{
	if (game->all_map[y][x] == '1' || dfs->visited[y][x] || dfs->objs)
		return (0);
	dfs->visited[y][x] = 1;
	return (1);
}

void	exit_check(t_game_info *game, t_dfs *dfs, size_t x, size_t y)
{
	if (game->all_map[y][x] == 'E')
	{
		dfs->exit_cnt++;
		return ;
	}
	if (exit_promising(game, dfs, x + 1, y))
		exit_check(game, dfs, x + 1, y);
	if (exit_promising(game, dfs, x - 1, y))
		exit_check(game, dfs, x - 1, y);
	if (exit_promising(game, dfs, x, y + 1))
		exit_check(game, dfs, x, y + 1);
	if (exit_promising(game, dfs, x, y - 1))
		exit_check(game, dfs, x, y - 1);
}
