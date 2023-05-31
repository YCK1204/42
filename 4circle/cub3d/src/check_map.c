/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:27:47 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/22 19:21:06 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_map(t_info *info)
{
	int		i;
	int		col;
	char	**check_map;
	char	**rotate_check_map;

	i = -1;
	while (++i < info->map_h)
	{
		col = ft_strlen(info->map[i]);
		if (col > info->map_w)
			info->map_w = col;
	}
	check_map = make_check_map(info);
	rotate_check_map = make_rotate_map(check_map);
	if (check_wall(check_map) == 1 || check_wall(rotate_check_map) == 1)
	{
		two_pointer_free(check_map);
		two_pointer_free(rotate_check_map);
		return (1);
	}
	two_pointer_free(check_map);
	two_pointer_free(rotate_check_map);
	if (set_player(info) == 1)
		return (1);
	return (0);
}

static char	*map_ncat(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		s1[i + n] = s2[i];
		i++;
	}
	return (s1);
}

char	*map_join(char *s1, char *s2)
{
	char			*result;
	size_t			len1;
	size_t			len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (0);
	result = map_ncat(result, (char *)s1, 0);
	result = map_ncat(result, (char *)s2, len1);
	result[len1 + len2] = 0;
	free(s1);
	free(s2);
	return (result);
}

void	get_map_util_util(t_info *info, char **temp, char **line, char **tmp)
{
	*temp = ft_strdup(*line);
	free(*line);
	if (*temp == NULL)
		malloc_err(info);
	*line = map_join(*temp, *tmp);
	if (*line == NULL)
		malloc_err(info);
	info->map_h++;
}

int	get_map(t_info *info, int fd)
{
	char	*line;
	char	*tmp;
	char	*temp;

	line = ft_strdup("");
	if (line == NULL)
		malloc_err(info);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		else if (ft_strcmp(tmp, "\n") == 0)
		{
			free(tmp);
			continue ;
		}
		if (check_line(tmp, line) == 1)
			return (1);
		get_map_util_util(info, &temp, &line, &tmp);
	}
	return (get_map_util(info, line, tmp));
}
