/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:38:07 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 02:17:05 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

void	info_init(t_game_info *game, char *line)
{
	if (line == NULL)
		err("NULL FILE\n");
	game->graphic.height = 0;
	game->graphic.width = ft_strlen(line) - 1;
	game->graphic.map = ft_strdup(line);
	game->objs = 0;
	game->player.step = 0;
	game->player.steps = 0;
	game->enemy.direction = 0;
	game->player.direction = 0;
	game->time = 0;
}

void	pos_init(t_game_info *game)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while ((size_t)++i < game->graphic.height)
	{
		j = -1;
		while ((size_t)++j < game->graphic.width)
		{
			if (game->graphic.all_map[i][j] == 'P')
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 1)
			break ;
	}
	game->player.x = j;
	game->player.y = i;
}

int	key_press(int key, t_game_info *game)
{
	if (key == UP)
		key_up(game);
	else if (key == DOWN)
		key_down(game);
	else if (key == LEFT)
		key_left(game);
	else if (key == RIGHT)
		key_right(game);
	else if (key == KEY_ESC)
		exit(0);
	drawing_map(game->graphic.mlx, game->graphic.mlx_win, &game->imgs, game);
	return (0);
}

void	err(char *str)
{
	ft_putstr("Error\n", 2);
	ft_putstr(str, 2);
	exit(1);
}

void	ft_putstr(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}
