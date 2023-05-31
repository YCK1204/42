/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:03:45 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/10 20:47:00 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	draw(t_info *info)
{
	int	i;
	int	j;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
			info->img->data[j * WIDTH + i] = info->buf[j][i];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img->img, 0, 0);
}

void	dda_util5(t_info *info, t_dda *dda)
{
	if (dda->side == 0 && dda->raydir_x > 0)
		dda->text_x = 64 - dda->text_x - 1;
	if (dda->side == 1 && dda->raydir_y < 0)
		dda->text_x = 64 - dda->text_x - 1;
	dda->step = 1.0 * 64 / dda->line_height;
	dda->text_pos = (dda->draw_start - HEIGHT / 2 + \
			dda->line_height / 2) * dda->step;
	dda->y = dda->draw_start;
	while (dda->y < dda->draw_end)
	{
		dda->text_y = (int)dda->text_pos & (TEXHEIGHT - 1);
		dda->text_pos += dda->step;
		info->color = info->img->texture[dda->texnum][TEXHEIGHT \
					* dda->text_y + dda->text_x];
		info->buf[dda->y][dda->x] = info->color;
		dda->y++;
	}
}

void	dda_algorithm(t_info *info, t_dda *dda)
{
	dda_util3(info, dda);
	dda->x = -1;
	while (++dda->x < info->width)
	{
		init_dda(info, dda);
		dda_util1(info, dda);
		dda_util2(info, dda);
		dda_util4(info, dda);
		dda_util5(info, dda);
	}
}
