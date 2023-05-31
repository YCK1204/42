/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:25:07 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/10 21:28:45 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	key_up(t_info *info)
{
	if (info->map[(int)(info->player_y + info->dir_y * \
				MOVE_SPD)][(int)info->player_x] != '1')
		info->player_y += info->dir_y * MOVE_SPD;
	if (info->map[(int)info->player_y][(int)(info->player_x \
				+ info->dir_x * MOVE_SPD)] != '1')
		info->player_x += info->dir_x * MOVE_SPD;
}

void	key_down(t_info *info)
{
	if (info->map[(int)(info->player_y - info->dir_y \
				* MOVE_SPD)][(int)info->player_x] != '1')
		info->player_y -= info->dir_y * MOVE_SPD;
	if (info->map[(int)info->player_y][(int)(info->player_x \
				- info->dir_x * MOVE_SPD)] != '1')
		info->player_x -= info->dir_x * MOVE_SPD;
}

void	key_left(t_info *info)
{
	if (info->map[(int)(info->player_y - info->plane_y \
				* MOVE_SPD)][(int)info->player_x] != '1')
		info->player_y -= info->plane_y * MOVE_SPD;
	if (info->map[(int)info->player_y][(int)(info->player_x \
				- info->plane_x * MOVE_SPD)] != '1')
		info->player_x -= info->plane_x * MOVE_SPD;
}

void	key_right(t_info *info)
{
	if (info->map[(int)(info->player_y + info->plane_y \
				* MOVE_SPD)][(int)info->player_x] != '1')
		info->player_y += info->plane_y * MOVE_SPD;
	if (info->map[(int)info->player_y][(int)(info->player_x \
				+ info->plane_x * MOVE_SPD)] != '1')
		info->player_x += info->plane_x * MOVE_SPD;
}

void	two_pointer_free(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}
