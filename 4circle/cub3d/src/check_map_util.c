/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:46:24 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/21 17:26:22 by seongmpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_first_last(char *map)
{
	int	i;

	i = -1;
	while (map[++i] == ' ')
		;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_middle(char **all_map, char *map, int r)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (map[++i] == ' ')
		;
	j = i;
	while (map[j])
	{
		if (j == i || j == ((int)ft_strlen(map) - 1))
		{
			tmp = j;
			while (map[tmp] == ' ')
				tmp--;
			if (map[tmp] != '1')
				return (1);
		}
		else if (map[j] == '0' && (all_map[r - 1][j] == ' ' || \
				all_map[r + 1][j] == ' '))
			return (1);
		j++;
	}
	return (0);
}

int	check_wall(char **map)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (map[++i])
	{
		if (i == 0 || i == strlen_double_size_arr(map) - 1)
			res = check_first_last(map[i]);
		else
			res = check_middle(map, map[i], i);
		if (res == 1)
			return (1);
	}
	return (0);
}

void	set_rotate_player(t_info *info, char c, int i, int j)
{
	info->player_x = j + 0.5;
	info->player_y = i + 0.5;
	if (c == 'N')
		rotate_right(info, PI / 2);
	else if (c == 'W')
		rotate_right(info, PI);
	else if (c == 'S')
		rotate_right(info, PI * 3 / 2);
	info->map[i][j] = '0';
}

int	check_line(char *str, char *line)
{
	int		i;

	i = -1;
	if (check_line_middle_space(str) == 1)
	{
		free(line);
		free(str);
		return (1);
	}
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == 'E' \
		|| str[i] == 'S' || str[i] == 'W' || str[i] == 'N' \
		|| str[i] == '0' || str[i] == '1')
			continue ;
		else
		{
			free(line);
			free(str);
			return (1);
		}
	}
	return (0);
}
