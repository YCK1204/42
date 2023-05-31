/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:25:30 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/22 19:22:30 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	rotate_left(t_info *info, double radian)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->dir_x;
	oldplane_x = info->plane_x;
	info->dir_x = info->dir_x * cos(radian) - info->dir_y * sin(radian);
	info->dir_y = olddir_x * sin(radian) + info->dir_y * cos(radian);
	info->plane_x = info->plane_x * cos(radian) - info->plane_y * sin(radian);
	info->plane_y = oldplane_x * sin(radian) + info->plane_y * cos(radian);
}

void	rotate_right(t_info *info, double radian)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = info->dir_x;
	oldplane_x = info->plane_x;
	info->dir_x = info->dir_x * cos(-radian) - info->dir_y * sin(-radian);
	info->dir_y = olddir_x * sin(-radian) + info->dir_y * cos(-radian);
	info->plane_x = info->plane_x * cos(-radian) - info->plane_y * sin(-radian);
	info->plane_y = oldplane_x * sin(-radian) + info->plane_y * cos(-radian);
}

int	exit_program(t_info *info)
{
	two_pointer_free(info->map);
	free(info->img);
	exit(0);
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == UP)
		key_up(info);
	else if (key == DOWN)
		key_down(info);
	else if (key == LEFT)
		key_left(info);
	else if (key == RIGHT)
		key_right(info);
	else if (key == KEY_L)
		rotate_left(info, ROTATE_SPD);
	else if (key == KEY_R)
		rotate_right(info, ROTATE_SPD);
	else if (key == KEY_ESC)
		exit_program(info);
	main_loop(info);
	return (0);
}
