/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:51:33 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 02:25:17 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/so_long.h"

void	print_steps(int steps)
{
	char	*step;

	step = ft_itoa(steps);
	ft_putstr("total step : ", 1);
	ft_putstr(step, 1);
	ft_putstr("\n", 1);
	free(step);
}

int	key_up(t_game_info *game)
{
	if (game->all_map[game->y - 1][game->x] == '1')
		return (0);
	if (game->all_map[game->y - 1][game->x] == 'E')
	{
		if (game->objs > 0)
			return (0);
		else
		{
			ft_putstr("GAME CLEAR!\n", 1);
			exit(0);
		}
	}
	if (game->all_map[game->y - 1][game->x] == 'C')
		game->objs--;
	game->all_map[game->y--][game->x] = '0';
	game->all_map[game->y][game->x] = 'P';
	game->total_step++;
	return (1);
}

int	key_down(t_game_info *game)
{
	if (game->all_map[game->y + 1][game->x] == '1')
		return (0);
	if (game->all_map[game->y + 1][game->x] == 'E')
	{
		if (game->objs > 0)
			return (0);
		else
		{
			ft_putstr("GAME CLEAR!\n", 1);
			exit(0);
		}
	}
	if (game->all_map[game->y + 1][game->x] == 'C')
		game->objs--;
	game->all_map[game->y++][game->x] = '0';
	game->all_map[game->y][game->x] = 'P';
	game->total_step++;
	return (1);
}

int	key_left(t_game_info *game)
{
	if (game->all_map[game->y][game->x - 1] == '1')
		return (0);
	if (game->all_map[game->y][game->x - 1] == 'E')
	{
		if (game->objs > 0)
			return (0);
		else
		{
			ft_putstr("GAME CLEAR!\n", 1);
			exit(0);
		}
	}
	if (game->all_map[game->y][game->x - 1] == 'C')
		game->objs--;
	game->all_map[game->y][game->x--] = '0';
	game->all_map[game->y][game->x] = 'P';
	game->total_step++;
	return (1);
}

int	key_right(t_game_info *game)
{
	if (game->all_map[game->y][game->x + 1] == '1')
		return (0);
	if (game->all_map[game->y][game->x + 1] == 'E')
	{
		if (game->objs > 0)
			return (0);
		else
		{
			ft_putstr("GAME CLEAR!\n", 1);
			exit(0);
		}
	}
	if (game->all_map[game->y][game->x + 1] == 'C')
		game->objs--;
	game->all_map[game->y][game->x++] = '0';
	game->all_map[game->y][game->x] = 'P';
	game->total_step++;
	return (1);
}
