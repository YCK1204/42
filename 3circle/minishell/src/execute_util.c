/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:01:45 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/26 18:56:09 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	print_err(t_pipex *p, char *cmd, char *msg)
{
	char	*err_msg;
	char	*tmp;
	int		fd;

	fd = 1;
	tmp = ft_strjoin("minishell: ", cmd);
	err_msg = ft_strjoin(tmp, msg);
	if (p->redirect->err_file == 0)
		p->redirect->err_file = open("print_err.txt", \
				O_APPEND | O_CREAT | O_RDWR, 0644);
	if (p->cmd->here_doc_cnt && p->redirect->err_file)
		fd = p->redirect->err_file;
	ft_putstr_fd(err_msg, fd);
	free(tmp);
	free(err_msg);
}

void	sub_dup2(t_pipex *p)
{
	if (p->pipe_cnt)
	{
		if (p->i == p->pipe_cnt)
			dup2(p->fds[p->i * 2 - 2], 0);
		else if (p->i == 0)
			dup2(p->fds[1], 1);
		else
		{
			dup2(p->fds[p->i * 2 - 2], 0);
			dup2(p->fds[p->i * 2 + 1], 1);
		}
	}
	if (p->redirect->infile > 0)
		dup2(p->redirect->infile, 0);
	if (p->redirect->outfile > 0)
		dup2(p->redirect->outfile, 1);
	close_pipes(p);
}

void	priority_redirect(t_pipex *p)
{
	int		n;
	size_t	k;

	if (p->cmd->redirect[p->i][p->j][0] == '\0')
	{
		p->j++;
		return ;
	}
	k = 0;
	n = discriminate_redirect(p->cmd->redirect[p->i][p->j++], &k);
	if (n == 1)
	{
		signal(SIGINT, SIG_IGN);
		here_doc(p, p->i, p->j, NULL);
		signal(SIGINT, signal_cmd);
	}
	else if (n == 2)
		get_file(p, p->i, p->j, 2);
	else if (n == 3)
		get_file(p, p->i, p->j, 0);
	else if (n == 4)
		get_file(p, p->i, p->j, 1);
	p->j++;
}

void	ft_execve_util(t_pipex *p, char *temp)
{
	g_exit_code = 127;
	if (!ft_strcmp(temp, "."))
	{
		print_err(p, temp, ": filename argument required\n.: \
usage: . filename [arguments]\n");
		g_exit_code = 2;
	}
	else if (p->path)
		print_err(p, temp, ": command not found\n");
	else
		print_err(p, temp, ": No such file or directory\n");
	free(temp);
	p->cmd->execve_cnt--;
	p->temp = g_exit_code;
	return ;
}

void	ft_execve(t_pipex *p, t_lst **head)
{
	char	*temp;
	pid_t	pid;

	init_ep(p, head);
	if (!ft_strcmp(p->cmd->cmd[p->i], "exit"))
		return (ft_exit(p, head));
	temp = ft_strdup(p->cmd->cmd[p->i]);
	free(p->cmd->cmd[p->i]);
	p->cmd->cmd[p->i] = cmd_root(p, temp);
	if (p->cmd->cmd[p->i][ft_strlen(p->cmd->cmd[p->i]) - 1] == '/' || \
			access(p->cmd->cmd[p->i], X_OK) || !ft_strcmp(temp, "."))
		return (ft_execve_util(p, temp));
	free(temp);
	two_pointer_free(p->path);
	p->path = NULL;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, hand);
		signal(SIGQUIT, hand);
		sub_dup2(p);
		execve(p->cmd->cmd[p->i], p->cmd->cmd_opt[p->i], p->ep);
	}
	else if (p->i == (size_t)p->last_execve_cmd)
		wait_child(p, pid);
}
