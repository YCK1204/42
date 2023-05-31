/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:39:49 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/21 16:48:05 by seongmpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	dda_util1(t_info *info, t_dda *dda)
{
	if (dda->raydir_x < 0)
	{
		dda->step_x = -1;
		dda->sidedist_x = (info->player_x - dda->map_x) * dda->deltadist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->sidedist_x = (dda->map_x + 1.0 - info->player_x) * \
						dda->deltadist_x;
	}
	if (dda->raydir_y < 0)
	{
		dda->step_y = -1;
		dda->sidedist_y = (info->player_y - dda->map_y) * dda->deltadist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->sidedist_y = (dda->map_y + 1.0 - \
				info->player_y) * dda->deltadist_y;
	}
}

void	dda_util2(t_info *info, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if (dda->sidedist_x < dda->sidedist_y)
		{
			dda->sidedist_x += dda->deltadist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->sidedist_y += dda->deltadist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (info->map[dda->map_y][dda->map_x] > '0')
			dda->hit = 1;
	}
	if (dda->side == 0)
		dda->perpwalldist = (dda->map_x - info->player_x + \
				(1 - dda->step_x) / 2) / dda->raydir_x;
	else
		dda->perpwalldist = (dda->map_y - info->player_y + \
				(1 - dda->step_y) / 2) / dda->raydir_y;
	dda->line_height = (int)(HEIGHT / dda->perpwalldist);
	dda->draw_start = -dda->line_height / 2 + HEIGHT / 2;
}

void	dda_util3(t_info *info, t_dda *dda)
{
	dda->y = -1;
	while (++dda->y < HEIGHT)
	{
		dda->x = -1;
		while (++dda->x < WIDTH)
		{
			dda->color = info->img->floor;
			info->buf[dda->y][dda->x] = dda->color;
			dda->color = info->img->ceiling;
			info->buf[HEIGHT - dda->y - 1][dda->x] = dda->color;
		}
	}
}

void	dda_util4(t_info *info, t_dda *dda)
{
	if (dda->draw_start < 0)
		dda->draw_start = 0;
	dda->draw_end = dda->line_height / 2 + HEIGHT / 2;
	if (dda->draw_end >= HEIGHT)
		dda->draw_end = HEIGHT - 1;
	dda->texnum = info->map[dda->map_y][dda->map_x];
	if (dda->texnum == '1' && dda->side == 0 && dda->raydir_x < 0)
		dda->texnum = 3;
	else if (dda->texnum == '1' && dda->side == 0 && dda->raydir_x > 0)
		dda->texnum = 2;
	else if (dda->texnum == '1' && dda->side == 1 && dda->raydir_y < 0)
		dda->texnum = 1;
	else if (dda->texnum == '1' && dda->side == 1 && dda->raydir_y > 0)
		dda->texnum = 0;
	else
		dda->texnum = 0;
	if (dda->side == 0)
		dda->wall_x = info->player_y + dda->perpwalldist * dda->raydir_y;
	else
		dda->wall_x = info->player_x + dda->perpwalldist * dda->raydir_x;
	dda->wall_x -= floor(dda->wall_x);
	dda->text_x = (int)(dda->wall_x * (double)TEXWIDTH);
}
