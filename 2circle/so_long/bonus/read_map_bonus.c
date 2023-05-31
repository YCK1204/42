/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:40:32 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 15:13:58 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

void	character_exit_target_check(t_game_info *game, \
		size_t enemy_cnt, size_t exit_cnt, size_t char_cnt)
{
	game->imgs.i = -1;
	while ((size_t)++game->imgs.i < game->graphic.height)
	{
		game->imgs.j = -1;
		while ((size_t)++game->imgs.j < game->graphic.width)
		{
			if (game->graphic.all_map[game->imgs.i][game->imgs.j] == 'C')
				game->objs++;
			else if (game->graphic.all_map[game->imgs.i][game->imgs.j] == 'P')
				char_cnt++;
			else if (game->graphic.all_map[game->imgs.i][game->imgs.j] == 'E')
				exit_cnt++;
			else if (game->graphic.all_map[game->imgs.i][game->imgs.j] == 'G')
				enemy_cnt++;
			else if (game->graphic.all_map[game->imgs.i][game->imgs.j] == '0' \
					|| game->graphic.all_map[game->imgs.i][game->imgs.j] \
					== '1')
				continue ;
			else
				err("MAP ERROR!\n");
		}
	}
	if (!game->objs || char_cnt != 1 || exit_cnt != 1 || enemy_cnt != 1)
		err("Map Element Error\n");
}

void	surround_wall_check(t_game_info *game)
{
	int	i;

	i = -1;
	while ((size_t)++i < game->graphic.width)
	{
		if (game->graphic.all_map[0][i] != '1' || \
				game->graphic.all_map[game->graphic.height - 1][i] != '1')
			err("Map Wall Error!\n");
	}
	i = -1;
	while ((size_t)++i < game->graphic.height)
	{
		if (game->graphic.all_map[i][0] != '1' || \
				game->graphic.all_map[i][game->graphic.width - 1] != '1')
			err("Map Wall Error!\n");
	}
	character_exit_target_check(game, 0, 0, 0);
}

void	join_line(t_game_info *game, char *line)
{
	char	*temp;

	temp = game->graphic.map;
	game->graphic.map = ft_strjoin(temp, line);
	free(temp);
}

void	read_map(char *temp, t_game_info *game)
{
	int		fd;
	char	*line;
	char	*root;

	root = file(temp);
	fd = open((const char *)root, O_RDONLY);
	if (fd < 0)
		err("NONE FILE\n");
	line = get_next_line(fd);
	info_init(game, line);
	free(line);
	while (line)
	{
		game->graphic.height++;
		line = get_next_line(fd);
		if (line)
			join_line(game, line);
		free(line);
	}
	game->graphic.all_map = ft_split(game->graphic.map, '\n');
	game->graphic.graph = ft_split(game->graphic.map, '\n');
	close(fd);
	surround_wall_check(game);
	free(root);
}
