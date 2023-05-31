/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:44:22 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/21 16:54:01 by seongmpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	set_texture(t_info *info, t_img *img, char *path, int num)
{
	int	i;
	int	j;

	j = -1;
	info->img->img = \
		mlx_xpm_file_to_image(info->mlx, path, &img->width, &img->height);
	img->data = \
	(int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	while (++j < img->height)
	{
		i = -1;
		while (++i < img->width)
			img->texture[num][img->width * j + i] \
				= img->data[img->width * j + i];
	}
	mlx_destroy_image(info->mlx, img->img);
}

int	check_texture(t_info *info, t_img *img, char *str)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 1;
	while (str[++i] == ' ')
		;
	tmp = ft_substr(str, i, ft_strlen(str));
	fd = open(tmp, O_RDONLY);
	if (fd < 0)
	{
		free(tmp);
		return (1);
	}
	close(fd);
	if (ft_strncmp(str, "NO", 2) == 0 && ++info->no_flag)
		set_texture(info, img, tmp, NO);
	else if (ft_strncmp(str, "SO", 2) == 0 && ++info->so_flag)
		set_texture(info, img, tmp, SO);
	else if (ft_strncmp(str, "WE", 2) == 0 && ++info->we_flag)
		set_texture(info, img, tmp, WE);
	else if (ft_strncmp(str, "EA", 2) == 0 && ++info->ea_flag)
		set_texture(info, img, tmp, EA);
	free(tmp);
	return (0);
}

int	rgb_atoi(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (!str)
		return (-255);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str - '0');
		else
			break ;
		str++;
	}
	return (num * sign);
}

int	check_rgb_num(char **rgb)
{
	int	i;
	int	j;

	i = -1;
	while (rgb[++i])
	{
		j = -1;
		while (rgb[i][++j])
		{
			if (rgb[i][j] < '0' || rgb[i][j] > '9')
				return (1);
		}
	}
	return (0);
}

int	set_rgb(t_img *img, char **rgb, int flag)
{
	int	red;
	int	green;
	int	blue;

	if (check_rgb_num(rgb) == 1)
		return (1);
	red = rgb_atoi(rgb[0]);
	green = rgb_atoi(rgb[1]);
	blue = rgb_atoi(rgb[2]);
	two_pointer_free(rgb);
	if ((red < 0 || red > 255) || (green < 0 || green > 255) \
		|| (blue < 0 || blue > 255))
		return (1);
	if (flag == 1)
		img->floor = (red << 16 | green << 8 | blue);
	else if (flag == 2)
		img->ceiling = (red << 16 | green << 8 | blue);
	return (0);
}
