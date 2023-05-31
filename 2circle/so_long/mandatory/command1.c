/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:15:28 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 02:24:38 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/so_long.h"

void	info_init(t_game_info *game, char *line)
{
	if (line == NULL)
		err("NULL FILE\n");
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->map = ft_strdup(line);
	game->objs = 0;
}

void	pos_init(t_game_info *game)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while ((size_t)++i < game->height)
	{
		j = -1;
		while ((size_t)++j < game->width)
		{
			if (game->all_map[i][j] == 'P')
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 1)
			break ;
	}
	game->x = j;
	game->y = i;
	game->total_step = 0;
}

int	key_press(int key, t_game_info *game)
{
	int	i;

	i = 0;
	if (key == UP)
		i = key_up(game);
	else if (key == DOWN)
		i = key_down(game);
	else if (key == LEFT)
		i = key_left(game);
	else if (key == RIGHT)
		i = key_right(game);
	else if (key == KEY_ESC)
		exit(0);
	drawing_map(game->mlx, game->mlx_win, &game->imgs, game);
	if (i)
		print_steps((int)game->total_step);
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
