/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:05:51 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/22 19:10:04 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_dda(t_info *info, t_dda *dda)
{
	dda->perpwalldist = 0;
	dda->sidedist_x = 0;
	dda->sidedist_y = 0;
	dda->step_x = 0;
	dda->step_y = 0;
	dda->hit = 0;
	dda->camera_x = 2 * dda->x / (double)info->width - 1;
	dda->raydir_x = info->dir_x + info->plane_x * dda->camera_x;
	dda->raydir_y = info->dir_y + info->plane_y * dda->camera_x;
	dda->map_x = (int)info->player_x;
	dda->map_y = (int)info->player_y;
	dda->deltadist_x = fabs(1 / dda->raydir_x);
	dda->deltadist_y = fabs(1 / dda->raydir_y);
}

int	main_loop(t_info *info)
{
	t_dda	dda;

	dda_algorithm(info, &dda);
	draw(info);
	return (0);
}

void	set_info_array(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->height)
		ft_memset(info->buf[i], 0, info->width);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < TEXWIDTH * TEXHEIGHT)
			info->img->texture[i][j] = 0;
	}
}

void	init_info(t_info *info)
{
	info->img = (t_img *)malloc(sizeof(t_img));
	if (info->img == NULL)
		malloc_err(info);
	info->map = NULL;
	ft_memset(info->img, 0, 0);
	info->mlx = mlx_init();
	info->width = 640;
	info->height = 480;
	info->map_w = 0;
	info->map_h = 0;
	info->dir_x = -1;
	info->dir_y = 0;
	info->plane_x = 0;
	info->plane_y = 0.66;
	info->color = 0;
	info->no_flag = 0;
	info->so_flag = 0;
	info->we_flag = 0;
	info->ea_flag = 0;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2 || check_argv(argv[1]) == 1)
		return (print_error("Wrong map. no extesion .cub"));
	init_info(&info);
	set_info_array(&info);
	if (check_arguments(&info, open(argv[1], O_RDONLY)) == 1)
		return (print_error("Wrong map. please check map again."));
	if (info.no_flag != 1 || info.so_flag != 1 \
	|| info.we_flag != 1 || info.ea_flag != 1)
		return (print_error("Wrong map. please check map again."));
	info.win = mlx_new_window(info.mlx, info.width, info.height, "cub3D");
	info.img->img = mlx_new_image(info.mlx, info.width, info.height);
	info.img->data = (int *)mlx_get_data_addr(info.img->img, \
			&info.img->bpp, &info.img->size_l, &info.img->endian);
	main_loop(&info);
	mlx_hook(info.win, 2, 0, &key_press, &info);
	mlx_hook(info.win, 17, 0, &exit_program, &info);
	mlx_loop(info.mlx);
	return (0);
}
