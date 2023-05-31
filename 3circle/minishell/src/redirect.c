/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:04:05 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/26 16:38:35 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	here_doc_util(t_pipex *pipex, pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exit_code = status;
	else if (WTERMSIG(status) == SIGINT)
		g_exit_code = 128 + SIGINT;
	else if (WTERMSIG(status) == SIGQUIT)
		g_exit_code = 128 + SIGQUIT;
	close(pipex->redirect->infile);
	pipex->redirect->infile = open("here_doc_tmp.txt", O_RDONLY);
	if (pipex->cmd->here_doc_cnt)
	{
		pipex->cmd->here_doc_cnt--;
		if (!pipex->cmd->here_doc_cnt && pipex->redirect->err_file)
			print_err_file(pipex);
	}
}

void	here_doc_util_2(t_pipex *pipex, char *line)
{
	ft_putstr_fd(line, pipex->redirect->infile);
	ft_putstr_fd("\n", pipex->redirect->infile);
	free(line);
	line = NULL;
}

void	here_doc(t_pipex *pipex, size_t i, size_t j, char *line)
{
	pid_t	pid;

	unlink("here_doc_tmp.txt");
	pipex->redirect->infile = open("here_doc_tmp.txt", \
			O_RDWR | O_CREAT | O_TRUNC, 0644);
	pid = fork();
	if (!pid)
	{
		signal(SIGINT, jasik_sig);
		signal(SIGQUIT, SIG_IGN);
		while (1)
		{
			line = readline("> ");
			if (!line || !ft_strcmp(pipex->cmd->redirect[i][j], line))
			{
				free(line);
				break ;
			}
			if (!pipex->cmd->limit_quote[pipex->i][pipex->j])
				change_dollars(&pipex->head, &pipex->tail, &line);
			here_doc_util_2(pipex, line);
		}
		exit(0);
	}
	here_doc_util(pipex, pid);
}

void	handle_syntax_err(t_pipex *pipex)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= pipex->syntax->err_idx[0])
	{
		j = -1;
		if (i == pipex->syntax->err_idx[0])
		{
			while (++j + 1 < pipex->syntax->err_idx[1])
				if (!ft_strcmp(pipex->cmd->redirect[i][j], "<<"))
					here_doc(pipex, i, ++j, NULL);
		}
		else
		{
			while (pipex->cmd->redirect[i][++j])
				if (!ft_strcmp(pipex->cmd->redirect[i][j], "<<"))
					here_doc(pipex, i, ++j, NULL);
		}
	}
}
