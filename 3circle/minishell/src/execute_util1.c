/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:24:21 by yeckim            #+#    #+#             */
/*   Updated: 2023/04/02 13:06:35 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	wait_child(t_pipex *p, pid_t pid)
{
	int	status;

	close_pipes(p);
	waitpid(pid, &status, 0);
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
	p->temp = g_exit_code;
	p->cmd->execve_cnt--;
}

void	init_is_cmd_util(t_pipex *p, int i)
{
	char	*temp;

	temp = cmd_root(p, p->cmd->cmd[i]);
	if (temp[ft_strlen(temp) - 1] == '/' || \
			!ft_strcmp(temp, "."))
		p->is_cmd[i] = 0;
	else if (!access(temp, X_OK))
		p->is_cmd[i] = 1;
	else if (access(temp, X_OK))
		p->is_cmd[i] = 0;
	free(temp);
}

void	init_is_cmd(t_pipex *p)
{
	int		i;

	init_ep(p, &p->head);
	p->err = 0;
	if (!p->path)
	{
		p->err = 1;
		return ;
	}
	i = -1;
	p->is_cmd = (int *)malloc(sizeof(int) * p->cmd->execve_cnt);
	while (p->cmd->cmd[++i])
	{
		if (!p->cmd->cmd[i][0])
		{
			p->is_cmd[i] = 0;
			continue ;
		}
		init_is_cmd_util(p, i);
	}
	while (--i >= 0)
		if (p->is_cmd[i])
			break ;
	p->last_execve_cmd = i;
}

void	pass_redirect(char *line, size_t *i, size_t *ret)
{
	*i += 1;
	if (line[*i] == '<' || line[*i] == '>')
		*i += 1;
	while (line[*i] && line[*i] == ' ')
		*i += 1;
	while (line[*i] && line[*i] != ' ' && line[*i] != '<' && line[*i] != '>')
		*i += 1;
	*ret += 1;
}

void	check_pipe_syntax(t_pipex *pipex, char *line, size_t i, int f)
{
	if (pipex->syntax->err)
		return ;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == '|' && ++i)
		{
			if (f == 0)
				return (occur_syntax_err(pipex, 0, 0, "|"));
			f = 0;
		}
		else
		{
			f = 1;
			if (line[i] == '\'' || line[i] == '\"')
				quote_pass_util(pipex, line, &i, &pipex->k);
			else
				i++;
		}
	}
	if (f == 0)
		return (occur_syntax_err(pipex, 0, 0, "|"));
}
