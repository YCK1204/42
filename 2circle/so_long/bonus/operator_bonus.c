/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:49:24 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 17:49:27 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

void	enemy_move_left(t_game_info *game)
{
	game->graphic.graph[game->enemy.y][game->enemy.x] = '0';
	game->graphic.graph[game->enemy.y][game->enemy.x - 1] = 'G';
	game->enemy.x--;
	game->enemy.direction = 2;
}

void	enemy_move_down(t_game_info *game)
{
	game->graphic.graph[game->enemy.y][game->enemy.x] = '0';
	game->graphic.graph[game->enemy.y + 1][game->enemy.x] = 'G';
	game->enemy.y++;
	game->enemy.direction = 1;
}

void	enemy_move_up(t_game_info *game)
{
	game->graphic.graph[game->enemy.y][game->enemy.x] = '0';
	game->graphic.graph[game->enemy.y - 1][game->enemy.x] = 'G';
	game->enemy.y--;
	game->enemy.direction = 0;
}

void	enemy_move_right(t_game_info *game)
{
	game->graphic.graph[game->enemy.y][game->enemy.x] = '0';
	game->graphic.graph[game->enemy.y][game->enemy.x + 1] = 'G';
	game->enemy.x++;
	game->enemy.direction = 3;
}
