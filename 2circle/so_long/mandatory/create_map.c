/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:41:03 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/25 17:17:42 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/so_long.h"

void	imgs_init(void *mlx, t_imgs *imgs)
{
	imgs->character = mlx_xpm_file_to_image(mlx, "./mandatory_imgs/char.xpm", \
			&imgs->width, &imgs->height);
	imgs->wall = mlx_xpm_file_to_image(mlx, "./mandatory_imgs/wall.xpm", \
			&imgs->width, &imgs->height);
	imgs->escape = mlx_xpm_file_to_image(mlx, "./mandatory_imgs/escape.xpm", \
			&imgs->width, &imgs->height);
	imgs->target = mlx_xpm_file_to_image(mlx, "./mandatory_imgs/target.xpm", \
			&imgs->width, &imgs->height);
	imgs->tiles = mlx_xpm_file_to_image(mlx, "./mandatory_imgs/tiles.xpm", \
			&imgs->width, &imgs->height);
}

void	drawing_map(void *mlx, void *mlx_win, t_imgs *imgs, t_game_info *game)
{
	imgs->i = -1;
	while ((size_t)++imgs->i < game->height)
	{
		imgs->j = -1;
		while ((size_t)++imgs->j < game->width)
		{
			mlx_put_image_to_window(mlx, mlx_win, imgs->tiles, \
					imgs->j * 100, imgs->i * 100);
			if (game->all_map[imgs->i][imgs->j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, imgs->wall, \
						imgs->j * 100 + 10, imgs->i * 100);
			else if (game->all_map[imgs->i][imgs->j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, imgs->character, \
						imgs->j * 100 + 5, imgs->i * 100);
			else if (game->all_map[imgs->i][imgs->j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, imgs->target, \
						imgs->j * 100, imgs->i * 100 + 15);
			else if (game->all_map[imgs->i][imgs->j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, imgs->escape, \
					imgs->j * 100, imgs->i * 100);
			else if (game->all_map[imgs->i][imgs->j] != '0')
				err("Map Error\n");
		}
	}
}
