/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:16:35 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:34:58 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/pipex.h"

void	ex(t_pipex *p, char *cmd, char **p_cmd, char **ep)
{
	if (execve(cmd, p_cmd, ep) == -1)
		err(p, "execve error!");
}

void	child(t_pipex *pipex, char **ep)
{
	close(pipex->fd[0]);
	if (dup2(pipex->infile, 0) == -1)
		err(pipex, "child error!");
	if (dup2(pipex->fd[1], 1) == -1)
		err(pipex, "child error!");
	close(pipex->infile);
	close(pipex->fd[1]);
	ex(pipex, pipex->cmd1, pipex->p_cmd1, ep);
}

void	parent(t_pipex *pipex, char **ep)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		err(pipex, "fork error!");
	if (!pid)
	{
		close(pipex->fd[1]);
		if (dup2(pipex->fd[0], 0) == -1)
			err(pipex, "dup2 error!");
		if (dup2(pipex->outfile, 1) == -1)
			err(pipex, "dup2 error!");
		close(pipex->fd[0]);
		close(pipex->outfile);
		ex(pipex, pipex->cmd2, pipex->p_cmd2, ep);
	}
	else
	{
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		waitpid(pid, &pipex->status, 0);
		waitpid(-1, NULL, 0);
	}
}

void	ft_pipex(char **ep, t_pipex *pipex)
{
	pid_t	pid;

	if (pipe(pipex->fd) < 0)
		err(pipex, "pipe error!");
	pid = fork();
	if (pid == -1)
		err(pipex, "fork error!");
	else if (!pid)
		child(pipex, ep);
	else if (pid > 0)
		parent(pipex, ep);
}
