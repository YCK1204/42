/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student->42seoul->kr>         +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:38:27 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 01:57:31 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

void	key_up(t_game_info *game)
{
	game->player.direction = 0;
	game->player.steps++;
	if (game->graphic.all_map[game->player.y - 1][game->player.x] == '1')
		return ;
	if (game->graphic.graph[game->player.y - 1][game->player.x] == 'G')
		game_over(game);
	if (game->graphic.all_map[game->player.y - 1][game->player.x] == 'E')
	{
		if (game->objs > 0)
			return ;
		else
		{
			ft_putstr("GAME CLEAR!\n", 1);
			exit(0);
		}
	}
	if (game->graphic.all_map[game->player.y - 1][game->player.x] == 'C')
		game->objs--;
	game->graphic.all_map[game->player.y--][game->player.x] = '0';
	game->graphic.all_map[game->player.y][game->player.x] = 'P';
	game->player.step++;
}

void	key_down(t_game_info *game)
{
	game->player.direction = 1;
	game->player.steps++;
	if (game->graphic.all_map[game->player.y + 1][game->player.x] == '1')
		return ;
	if (game->graphic.graph[game->player.y + 1][game->player.x] == 'G')
		game_over(game);
	if (game->graphic.all_map[game->player.y + 1][game->player.x] == 'E')
	{
		if (game->objs > 0)
			return ;
		else
		{
			ft_putstr("GAME CLEAR!\n", 1);
			exit(0);
		}
	}
	if (game->graphic.all_map[game->player.y + 1][game->player.x] == 'C')
		game->objs--;
	game->graphic.all_map[game->player.y++][game->player.x] = '0';
	game->graphic.all_map[game->player.y][game->player.x] = 'P';
	game->player.step++;
}

void	key_left(t_game_info *game)
{
	game->player.direction = 2;
	game->player.steps++;
	if (game->graphic.all_map[game->player.y][game->player.x - 1] == '1')
		return ;
	if (game->graphic.graph[game->player.y][game->player.x - 1] == 'G')
		game_over(game);
	if (game->graphic.all_map[game->player.y][game->player.x - 1] == 'E')
	{
		if (game->objs > 0)
			return ;
		else
		{
			ft_putstr("GAME CLEAR!\n", 1);
			exit(0);
		}
	}
	if (game->graphic.all_map[game->player.y][game->player.x - 1] == 'C')
		game->objs--;
	game->graphic.all_map[game->player.y][game->player.x--] = '0';
	game->graphic.all_map[game->player.y][game->player.x] = 'P';
	game->player.step++;
}

void	key_right(t_game_info *game)
{
	game->player.direction = 3;
	game->player.steps++;
	if (game->graphic.all_map[game->player.y][game->player.x + 1] == '1')
		return ;
	if (game->graphic.graph[game->player.y][game->player.x + 1] == 'G')
		game_over(game);
	if (game->graphic.all_map[game->player.y][game->player.x + 1] == 'E')
	{
		if (game->objs > 0)
			return ;
		else
		{
			ft_putstr("GAME CLEAR!\n", 1);
			exit(0);
		}
	}
	if (game->graphic.all_map[game->player.y][game->player.x + 1] == 'C')
		game->objs--;
	game->graphic.all_map[game->player.y][game->player.x++] = '0';
	game->graphic.all_map[game->player.y][game->player.x] = 'P';
	game->player.step++;
}
