/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:38:57 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/22 01:33:00 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

int	exit_promising(t_game_info *game, t_dfs *dfs, size_t x, size_t y)
{
	if (game->graphic.all_map[y][x] == '1' || dfs->visited[y][x] || dfs->objs)
		return (0);
	dfs->visited[y][x] = 1;
	return (1);
}

void	exit_check(t_game_info *game, t_dfs *dfs, size_t x, size_t y)
{
	if (game->graphic.all_map[y][x] == 'E')
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
