/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:26:38 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 17:46:16 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/so_long.h"

char	*file(char *name)
{
	char	*f;

	f = "./mandatory_files_map/";
	f = ft_strjoin(f, name);
	if (f == NULL)
		return (NULL);
	return (f);
}

int	game_over(t_game_info *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_putstr("GAME OVER\n", 1);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game_info	game;

	if (ac == 2)
	{
		read_map(av[1], &game);
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx, game.width * 100, \
				game.height * 100, "so_long");
		imgs_init(game.mlx, &game.imgs);
		drawing_map(game.mlx, game.mlx_win, &game.imgs, &game);
		pos_init(&game);
		clearable_check(&game);
		mlx_hook(game.mlx_win, 2, 0, &key_press, &game);
		mlx_hook(game.mlx_win, 17, 0, &game_over, &game);
		mlx_loop(game.mlx);
	}
	else
		err("Map Is Missing\n");
	return (0);
}
