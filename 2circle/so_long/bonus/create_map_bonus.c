/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:38:43 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 16:56:01 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

void	imgs_init3(void *mlx, t_imgs *i)
{
	i->g[2][0].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_l_0.xpm", &i->g[2][0].width, &i->g[2][0].height);
	i->g[2][1].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_l_1.xpm", &i->g[2][1].width, &i->g[2][1].height);
	i->g[2][2].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_l_2.xpm", &i->g[2][2].width, &i->g[2][2].height);
	i->g[2][3].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_l_3.xpm", &i->g[2][3].width, &i->g[2][3].height);
	i->g[3][0].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_r_0.xpm", &i->g[3][0].width, &i->g[2][0].height);
	i->g[3][1].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_r_1.xpm", &i->g[3][1].width, &i->g[2][1].height);
	i->g[3][2].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_r_2.xpm", &i->g[3][2].width, &i->g[2][2].height);
	i->g[3][3].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_r_3.xpm", &i->g[3][3].width, &i->g[2][3].height);
	i->wall.temp = mlx_xpm_file_to_image(mlx, "./bonus_imgs/wall.xpm", \
			&i->wall.width, &i->wall.height);
	i->target.temp = mlx_xpm_file_to_image(mlx, "./bonus_imgs/target.xpm", \
			&i->target.width, &i->target.height);
	i->escape.temp = mlx_xpm_file_to_image(mlx, "./bonus_imgs/escape.xpm", \
			&i->escape.width, &i->escape.height);
	i->tiles.temp = mlx_xpm_file_to_image(mlx, "./bonus_imgs/tiles.xpm", \
			&i->tiles.width, &i->tiles.height);
}

void	imgs_init2(void *mlx, t_imgs *i)
{
	i->c[3][0].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_r_0.xpm", &i->c[3][0].width, &i->c[3][0].height);
	i->c[3][1].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_r_1.xpm", &i->c[3][1].width, &i->c[3][1].height);
	i->c[3][2].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_r_2.xpm", &i->c[3][2].width, &i->c[3][2].height);
	i->c[3][3].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_r_3.xpm", &i->c[3][3].width, &i->c[3][3].height);
	i->g[0][0].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_u_0.xpm", &i->g[0][0].width, &i->g[0][0].height);
	i->g[0][1].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_u_1.xpm", &i->g[0][1].width, &i->g[0][1].height);
	i->g[0][2].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_u_2.xpm", &i->g[0][2].width, &i->g[0][2].height);
	i->g[0][3].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_u_3.xpm", &i->g[0][3].width, &i->g[0][3].height);
	i->g[1][0].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_d_0.xpm", &i->g[1][0].width, &i->g[1][0].height);
	i->g[1][1].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_d_1.xpm", &i->g[1][1].width, &i->g[1][1].height);
	i->g[1][2].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_d_2.xpm", &i->g[1][2].width, &i->g[1][2].height);
	i->g[1][3].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/g_d_3.xpm", &i->g[1][3].width, &i->g[1][3].height);
	imgs_init3(mlx, i);
}

void	imgs_init(void *mlx, t_imgs *i)
{
	i->c[0][0].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_u_0.xpm", &i->c[0][0].width, &i->c[0][0].height);
	i->c[0][1].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_u_1.xpm", &i->c[0][1].width, &i->c[0][1].height);
	i->c[0][2].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_u_2.xpm", &i->c[0][2].width, &i->c[0][2].height);
	i->c[0][3].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_u_3.xpm", &i->c[0][3].width, &i->c[0][3].height);
	i->c[1][0].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_d_0.xpm", &i->c[1][0].width, &i->c[1][0].height);
	i->c[1][1].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_d_1.xpm", &i->c[1][1].width, &i->c[1][1].height);
	i->c[1][2].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_d_2.xpm", &i->c[1][2].width, &i->c[1][2].height);
	i->c[1][3].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_d_3.xpm", &i->c[1][3].width, &i->c[1][3].height);
	i->c[2][0].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_l_0.xpm", &i->c[2][0].width, &i->c[2][0].height);
	i->c[2][1].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_l_1.xpm", &i->c[2][1].width, &i->c[2][1].height);
	i->c[2][2].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_l_2.xpm", &i->c[2][2].width, &i->c[2][2].height);
	i->c[2][3].temp = mlx_xpm_file_to_image(mlx, \
			"./bonus_imgs/c_l_3.xpm", &i->c[2][3].width, &i->c[2][3].height);
	imgs_init2(mlx, i);
}

void	draw_char_enemy(void *mlx, void *mlx_win, \
		t_imgs *imgs, t_game_info *game)
{
	if (game->graphic.all_map[imgs->i][imgs->j] == 'P')
	{
		mlx_put_image_to_window(mlx, mlx_win, \
				imgs->c[game->player.direction][game->player.steps % 4].temp, \
				imgs->j * 100 + 5, imgs->i * 100);
	}
	else if (game->graphic.graph[imgs->i][imgs->j] == 'G')
	{
		mlx_put_image_to_window(mlx, mlx_win, \
				imgs->g[game->enemy.direction][(int)(game->play_time \
					/ 0.05) % 4].temp, imgs->j * 100 + 5, imgs->i * 100);
	}
}

void	drawing_map(void *mlx, void *mlx_win, t_imgs *imgs, t_game_info *game)
{
	imgs->i = -1;
	while ((size_t)++imgs->i < game->graphic.height)
	{
		imgs->j = -1;
		while ((size_t)++imgs->j < game->graphic.width)
		{
			mlx_put_image_to_window(mlx, mlx_win, imgs->tiles.temp, \
					imgs->j * 100, imgs->i * 100);
			if (game->graphic.all_map[imgs->i][imgs->j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, imgs->wall.temp, \
						imgs->j * 100 + 10, imgs->i * 100);
			if (game->graphic.all_map[imgs->i][imgs->j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, imgs->target.temp, \
						imgs->j * 100, imgs->i * 100 + 15);
			if (game->graphic.all_map[imgs->i][imgs->j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, imgs->escape.temp, \
						imgs->j * 100, imgs->i * 100);
			if (game->graphic.all_map[imgs->i][imgs->j] == 'P' || \
					game->graphic.graph[imgs->i][imgs->j] == 'G')
				draw_char_enemy(mlx, mlx_win, imgs, game);
		}
	}
}
