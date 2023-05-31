/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:00:38 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/22 19:18:58 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_background(t_info *info, char *str)
{
	char	*tmp;
	char	**rgb;
	int		i;
	int		flag;

	i = 0;
	info->background_flag++;
	if (str[0] == 'F')
		flag = 1;
	else if (str[0] == 'C')
		flag = 2;
	while (str[i++] == ' ')
		;
	tmp = ft_substr(str, i + 1, ft_strlen(str));
	if (tmp == NULL)
		malloc_err(info);
	rgb = ft_split(tmp, ',');
	free(tmp);
	if (rgb == NULL)
		malloc_err(info);
	return (check_background_util(info, rgb, flag));
}

void	check_argu_util_util_util(char **temp, char **t)
{
	*temp = ft_strdup(*t);
	if (*temp == NULL)
		exit(print_error("malloc err"));
	free(*t);
	*t = ft_strtrim(*temp, " ");
	free(*temp);
	if (*t == NULL)
		exit(print_error("malloc err"));
	*temp = ft_strdup(*t);
	if (*temp == NULL)
		exit(print_error("malloc err"));
	free(*t);
	*t = ft_strtrim(*temp, "\n");
	free(*temp);
	if (*t == NULL)
		exit(print_error("malloc err"));
}

int	check_argu_util_util(t_info *info, char **temp, char **t)
{
	check_argu_util_util_util(temp, t);
	if (ft_strncmp(*t, "NO", 2) == 0 || ft_strncmp(*t, "SO", 2) == 0 \
			|| ft_strncmp(*t, "WE", 2) == 0 || ft_strncmp(*t, "EA", 2) == 0)
		info->check_flag = check_texture(info, info->img, *t);
	else if ((ft_strncmp(*t, "F", 1) == 0) \
			|| (ft_strncmp(*t, "C", 1) == 0))
		info->check_flag = check_background(info, *t);
	else
		return (1);
	return (0);
}

int	check_argu_util(t_info *info, int fd, char **temp, char **t)
{
	*t = get_next_line(fd);
	if (*t == NULL)
		malloc_err(info);
	while (1)
	{
		if (ft_strcmp(*t, "\n") != 0)
		{
			if (check_argu_util_util(info, temp, t))
				return (1);
			if (info->background_flag == 2 || info->check_flag == 1)
				break ;
			free(*t);
		}
		else
			free(*t);
		*t = get_next_line(fd);
		if (*t == NULL)
			malloc_err(info);
	}
	return (0);
}

int	check_arguments(t_info *info, int fd)
{
	char	*tmp;
	char	*temp;
	int		i;

	i = 0;
	if (fd < 0)
		return (1);
	temp = "";
	tmp = "";
	if (check_argu_util(info, fd, &temp, &tmp) == 1)
	{
		if (tmp)
			free(tmp);
		return (1);
	}
	if (tmp)
		free(tmp);
	if (info->check_flag == 1)
		return (1);
	else
		i = get_map(info, fd);
	close(fd);
	return (i);
}
