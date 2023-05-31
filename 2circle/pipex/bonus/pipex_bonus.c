/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:22:54 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:44:30 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/pipex_bonus.h"

void	create_pipe(t_pipex *pipex)
{
	int	i;

	i = -1;
	pipex->fds = (int *)malloc(sizeof(int) * ((pipex->cmd_count - 1) * 2));
	if (pipex->fds == NULL)
		err(pipex, "malloc error!");
	while (++i < pipex->cmd_count)
	{
		if (pipe(&pipex->fds[i * 2]) == -1)
			err(pipex, "pipe error!");
	}
}

void	sub_dup2(t_pipex *pipex, int fd1, int fd2)
{
	if (dup2(fd1, 0) == -1)
		err(pipex, "dup2 error!");
	if (dup2(fd2, 1) == -1)
		err(pipex, "dup2 error!");
}

void	ex(t_pipex *p, char **ep)
{
	if (execve(p->cmds[p->i], p->p_cmds[p->i], ep) == -1)
		err(p, "execve error!");
}

void	close_pipes(t_pipex *p)
{
	int	i;

	i = -1;
	while (++i < p->cmd_count * 2)
		close(p->fds[i]);
}

void	ft_pipex(t_pipex *p, char **ep)
{
	pid_t	pid;

	p->i = -1;
	while (++p->i < p->cmd_count)
	{
		pid = fork();
		if (pid == -1)
			err(p, "fork error!");
		if (pid == 0)
		{
			if (p->i == 0)
				sub_dup2(p, p->infile, p->fds[1]);
			else if (p->i == p->cmd_count - 1)
				sub_dup2(p, p->fds[p->i * 2 - 2], p->outfile);
			else
				sub_dup2(p, p->fds[p->i * 2 - 2], p->fds[p->i * 2 + 1]);
			close_pipes(p);
			ex(p, ep);
		}
	}
	close_pipes(p);
	p->i = -1;
	waitpid(pid, &p->status, 0);
	while (++p->i < p->cmd_count - 1)
		waitpid(-1, NULL, 0);
}
