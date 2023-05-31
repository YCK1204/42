/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:24:21 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/02 13:06:33 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	g_exit_code;

void	hand(int signum)
{
	(void)signum;
	rl_redisplay();
	exit(1);
}

void	collect_child(t_pipex *p)
{
	int	status;

	if (!p->tmp || p->err)
		return ;
	close_pipes(p);
	p->i = -1;
	while (++p->i < p->cmd->execve_cnt)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
			g_exit_code = status;
		else if (WTERMSIG(status) == SIGINT)
		{
			printf("^C\n");
			g_exit_code = 128 + SIGINT;
		}
		else if (WTERMSIG(status) == SIGQUIT)
		{
			printf("Quit: 3\n");
			g_exit_code = 128 + SIGQUIT;
		}
	}
	if (p->is_cmd[p->tmp] == 0)
		g_exit_code = p->temp;
}

void	ep_path_free_util(t_pipex *p)
{
	if (p->ep)
		two_pointer_free(p->ep);
	p->ep = NULL;
	if (p->path)
		two_pointer_free(p->path);
	p->path = NULL;
}

void	execute(t_pipex *p, t_lst **head, t_lst **tail)
{
	if (p->syntax->err)
		return ;
	p->tmp = p->cmd->execve_cnt;
	init_is_cmd(p);
	ep_path_free_util(p);
	p->temp = g_exit_code;
	create_pipe(p);
	p->i = -1;
	while (++p->i <= p->pipe_cnt)
	{
		p->j = 0;
		p->redirect->infile = 0;
		p->redirect->outfile = 0;
		p->redirect->infile_err = 0;
		while (p->cmd->redirect_cnt && p->cmd->redirect[p->i][p->j] \
				&& !p->redirect->infile_err)
			priority_redirect(p);
		if (!p->redirect->infile_err && is_builtin(p))
			builtin(p, head, tail);
		else if (!p->redirect->infile_err && p->execve_cmd[p->i])
			ft_execve(p, head);
		ep_path_free_util(p);
	}
	collect_child(p);
}
