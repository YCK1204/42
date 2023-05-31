/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:47:11 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/22 18:46:14 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	set_player(t_info *info)
{
	int	i;
	int	j;
	int	flag;
	int	width;

	i = -1;
	flag = 0;
	while (++i < info->map_h)
	{
		j = -1;
		width = ft_strlen(info->map[i]);
		while (++j < width)
		{
			if (flag == 1 && (info->map[i][j] == 'N' || info->map[i][j] \
					== 'E' || info->map[i][j] == 'S' || info->map[i][j] == 'W'))
				return (1);
			else if (info->map[i][j] == 'N' || info->map[i][j] == 'E' \
				|| info->map[i][j] == 'S' || info->map[i][j] == 'W')
			{
				set_rotate_player(info, info->map[i][j], i, j);
				flag = 1;
			}
		}
	}
	return (0);
}

char	*rearrange_map(int dest, char *str)
{
	int		i;
	char	*re_arr;

	i = -1;
	re_arr = (char *)malloc(sizeof(char) * (dest + 1));
	re_arr[dest] = '\0';
	while (str[++i])
		re_arr[i] = str[i];
	while (i < dest)
	{
		re_arr[i] = ' ';
		i++;
	}
	return (re_arr);
}

char	**make_check_map(t_info *info)
{
	char	**result;
	int		i;
	int		j;

	i = -1;
	result = (char **)malloc(sizeof(char *) * (info->map_h + 1));
	if (result == NULL)
		malloc_err(info);
	result[info->map_h] = NULL;
	while (info->map[++i])
	{
		if ((int)ft_strlen(info->map[i]) < info->map_w)
			result[i] = rearrange_map(info->map_w, info->map[i]);
		else
			result[i] = ft_strdup(info->map[i]);
		if (result == NULL)
		{
			j = -1;
			while (++j < i)
				free(result[i]);
			free(result);
			malloc_err(info);
		}
	}
	return (result);
}

char	**make_rotate_map(char **map)
{
	char	**result;
	int		i;
	int		j;
	int		width_len;
	int		height_len;

	i = -1;
	width_len = ft_strlen(map[0]);
	height_len = strlen_double_size_arr(map);
	result = (char **)malloc(sizeof(char *) * (width_len + 1));
	result[width_len] = NULL;
	while (++i < width_len)
	{
		result[i] = (char *)malloc(sizeof(char) * (height_len + 1));
		j = -1;
		while (++j < height_len)
			result[i][j] = map[height_len -(j + 1)][i];
		result[i][height_len] = '\0';
	}
	return (result);
}

int	check_line_middle_space(char *str)
{
	int		i;
	int		len;
	char	*tmp1;
	char	**tmp2;

	tmp1 = ft_strtrim(str, "\n");
	if (tmp1 == NULL)
		exit(print_error("malloc err"));
	tmp2 = ft_split(tmp1, ' ');
	free(tmp1);
	if (tmp2 == NULL)
		exit(print_error("malloc err"));
	i = -1;
	while (tmp2[++i])
	{
		len = ft_strlen(tmp2[i]);
		if (tmp2[i][0] != '1' || tmp2[i][len - 1] != '1')
		{
			two_pointer_free(tmp2);
			return (1);
		}
	}
	two_pointer_free(tmp2);
	return (0);
}
