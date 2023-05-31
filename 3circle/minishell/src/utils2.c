/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:38:25 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/26 17:14:26 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

size_t	count_cmd(char **cmds)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = -1;
	while (cmds[++i])
		if (cmds[i][0])
			ret++;
	return (ret);
}

char	**cmdline_init(t_pipex *p)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	**ret;

	size = count_cmd(p->cmd->cmd_opt[p->i]);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	ret[size] = NULL;
	i = -1;
	j = 0;
	while (p->cmd->cmd_opt[p->i][++i])
		if (p->cmd->cmd_opt[p->i][i][0])
			ret[j++] = ft_strdup(p->cmd->cmd_opt[p->i][i]);
	return (ret);
}

void	child_builtin(t_pipex *p, t_lst **head, t_lst **tail)
{
	char	**cmdline;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		cmdline = cmdline_init(p);
		sub_dup2(p);
		if (ft_strcmp(p->cmd->cmd[p->i], "export") == 0)
			ft_export(head, tail, cmdline, p->pipe_cnt);
		else if (ft_strcmp(p->cmd->cmd[p->i], "cd") == 0)
			ft_cd(head, tail, cmdline, p->pipe_cnt);
		else if (ft_strcmp(p->cmd->cmd[p->i], "env") == 0)
			ft_env(*head, *tail, cmdline, p->pipe_cnt);
		else if (ft_strcmp(p->cmd->cmd[p->i], "unset") == 0)
			ft_unset(head, tail, cmdline, p->pipe_cnt);
		else if (ft_strcmp(p->cmd->cmd[p->i], "pwd") == 0)
			ft_pwd(head, tail);
		else if (ft_strcmp(p->cmd->cmd[p->i], "echo") == 0)
			ft_echo(cmdline);
		exit(0);
	}
	else if (pid > 0 && p->i == (size_t)p->last_execve_cmd)
		wait_child(p, pid);
}
