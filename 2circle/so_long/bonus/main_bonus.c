/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:40:15 by yeckim            #+#    #+#             */
/*   Updated: 2023/06/04 02:35:05 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

char	*file(char *name)
{
	char	*f;

	f = "./bonus_files_map/";
	f = ft_strjoin(f, name);
	if (f == NULL)
		return (NULL);
	return (f);
}

int	game_over(t_game_info *game)
{
	mlx_destroy_window(game->graphic.mlx, game->graphic.mlx_win);
	ft_putstr("GAME OVER\n", 1);
	exit(0);
}

int	print_time_steps(t_game_info *game)
{
	char	*steps;
	char	*time;
	void	*m;
	void	*w;

	m = game->graphic.mlx;
	w = game->graphic.mlx_win;
	time = ft_itoa((int)(game->play_time * 1.5));
	steps = ft_itoa(game->player.step);
	mlx_string_put(m, w, 100, 100, 0xFFFFFF, "TOTAL STEP : ");
	mlx_string_put(m, w, 250, 100, 0xFFFFFF, steps);
	mlx_string_put(m, w, game->graphic.width * \
			100 / 2 + 50, 100, 0xFFFFFF, time);
	free(time);
	free(steps);
	return (0);
}

int	init_time(t_game_info *game)
{
	game->play_time = (double)clock() / CLOCKS_PER_SEC;
	if (game->play_time > game->time)
	{
		game->time += 0.06;
		bfs(game);
	}
	drawing_map(game->graphic.mlx, game->graphic.mlx_win, &game->imgs, game);
	print_time_steps(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game_info	game;

	if (ac == 2)
	{
		read_map(av[1], &game);
		game.graphic.mlx = mlx_init();
		game.graphic.mlx_win = mlx_new_window(game.graphic.mlx, \
				game.graphic.width * 100, \
				game.graphic.height * 100, "so_long");
		enemy_pos_init(&game);
		drawing_map(game.graphic.mlx, game.graphic.mlx_win, &game.imgs, &game);
		game.play_time = (double)clock() / CLOCKS_PER_SEC;
		mlx_hook(game.graphic.mlx_win, 2, 0, &key_press, &game);
		mlx_hook(game.graphic.mlx_win, 17, 0, &game_over, &game);
		mlx_loop_hook(game.graphic.mlx, init_time, &game);
		mlx_loop(game.graphic.mlx);
	}
	err("Map Is Missing\n");
	return (0);
}
