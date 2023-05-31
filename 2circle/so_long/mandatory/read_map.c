/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:50:40 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/25 17:18:21 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/so_long.h"

void	map_check(t_game_info *game, int i, int j)
{
	while ((size_t)++i < game->height)
	{
		j = -1;
		while (game->all_map[i][++j])
		{
			if ((size_t)j >= game->width)
				err("Map Wall Error!\n");
		}
	}
}

void	character_exit_target_check(t_game_info *game)
{
	size_t	exit_cnt;
	size_t	char_cnt;
	int		i;
	int		j;

	exit_cnt = 0;
	char_cnt = 0;
	i = -1;
	while ((size_t)++i < game->height)
	{
		j = -1;
		while ((size_t)++j < game->width)
		{
			if (game->all_map[i][j] == 'C')
				game->objs++;
			if (game->all_map[i][j] == 'P')
				char_cnt++;
			if (game->all_map[i][j] == 'E')
				exit_cnt++;
		}
	}
	if (game->objs == 0 || char_cnt != 1 || exit_cnt != 1)
		err("Map Element Error\n");
}

void	surround_wall_check(t_game_info *game)
{
	int	i;

	i = -1;
	while ((size_t)++i < game->width)
	{
		if (game->all_map[0][i] != '1' || \
				game->all_map[game->height - 1][i] != '1')
			err("Map Wall Error!\n");
	}
	i = -1;
	while ((size_t)++i < game->height)
	{
		if (game->all_map[i][0] != '1' || \
				game->all_map[i][game->width - 1] != '1')
			err("Map Wall Error!\n");
	}
	character_exit_target_check(game);
	map_check(game, -1, -1);
}

void	join_line(t_game_info *game, char *line)
{
	char	*temp;

	temp = game->map;
	game->map = ft_strjoin(temp, line);
	free(temp);
}

void	read_map(char *temp, t_game_info *game)
{
	int		fd;
	char	*line;
	char	*root;

	root = file(temp);
	fd = open(root, O_RDONLY);
	if (fd < 0)
		err("NONE FILE\n");
	line = get_next_line(fd);
	info_init(game, line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
			join_line(game, line);
		free(line);
	}
	game->all_map = ft_split(game->map, '\n');
	close(fd);
	surround_wall_check(game);
	free(root);
}
