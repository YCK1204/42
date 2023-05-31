/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:37:37 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/26 17:10:11 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	print_err_file(t_pipex *p)
{
	char	*line;
	int		fd;

	if (!p->redirect->err_file)
		return ;
	close(p->redirect->err_file);
	fd = open("print_err.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_putstr_fd(line, 2);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	get_file(t_pipex *pipex, size_t i, size_t j, int f)
{
	if (f == 0)
	{
		pipex->redirect->outfile = open(pipex->cmd->redirect[i][j], \
				O_APPEND | O_CREAT | O_RDWR, 0644);
	}
	else if (f == 1)
	{
		pipex->redirect->outfile = open(pipex->cmd->redirect[i][j], \
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	else if (f == 2)
	{
		pipex->redirect->infile = open(pipex->cmd->redirect[i][j], O_RDONLY);
		if (pipex->redirect->infile == -1)
		{
			print_err(pipex, pipex->cmd->redirect[i][j], \
					": No such file or directory\n");
			pipex->redirect->infile_err = 1;
			g_exit_code = 1;
		}
	}
}

void	jasik_sig(int sig)
{
	if (sig == 2)
	{
		g_exit_code = 1;
		printf("\n");
		rl_on_new_line();
		exit(g_exit_code);
	}
}
