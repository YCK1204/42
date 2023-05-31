/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:54:37 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/22 19:16:11 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	check_background_util(t_info *info, char **rgb, int flag)
{
	if (strlen_double_size_arr(rgb) != 3)
	{
		two_pointer_free(rgb);
		return (1);
	}
	else if (set_rgb(info->img, rgb, flag) == 1)
		return (1);
	return (0);
}

int	get_map_util(t_info *info, char *line, char *tmp)
{
	free(tmp);
	info->map = ft_split(line, '\n');
	if (info->map == NULL)
		malloc_err(info);
	free(line);
	if (info->map_h < 3 || check_map(info) == 1)
		return (1);
	return (0);
}

void	malloc_err(t_info *info)
{
	free(info->img);
	exit(print_error("malloc error"));
}
