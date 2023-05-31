/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:02:21 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/27 14:38:37 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*quote_trim(t_pipex *p, char *line, size_t *i, char *a)
{
	char	*tmp;
	char	*temp;
	size_t	quote;

	quote = 0;
	while (line[*i] && line[*i] != '<' && line[*i] != '>' && line[*i] != ' ')
	{
		p->k = *i;
		p->cmd->quote_flag = 0;
		if (line[*i] == '\'' || line[*i] == '\"')
			quote_pass_util1(p, line, i, 0);
		else
			*i += 1;
		temp = ft_strdup(a);
		free(a);
		tmp = ft_substr(line, p->k, *i - p->k - p->cmd->quote_flag);
		quote += p->cmd->quote_flag;
		a = ft_strjoin(temp, tmp);
		free(tmp);
		free(temp);
	}
	if (p->f)
		p->cmd->limit_quote[p->i][p->j] = quote;
	return (a);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	parent_builtin(t_pipex *p, t_lst **head, t_lst **tail, char **cmdline)
{
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
}

void	builtin(t_pipex *p, t_lst **head, t_lst **tail)
{
	char	**cmdline;
	int		tmp[2];

	if (p->pipe_cnt)
		return (child_builtin(p, head, tail));
	cmdline = cmdline_init(p);
	pipe(tmp);
	dup2(0, tmp[0]);
	dup2(1, tmp[1]);
	sub_dup2(p);
	parent_builtin(p, head, tail, cmdline);
	two_pointer_free(cmdline);
	dup2(tmp[1], 1);
	dup2(tmp[0], 0);
	close(tmp[0]);
	close(tmp[1]);
	p->temp = g_exit_code;
}

int	is_builtin(t_pipex *p)
{
	if (p->cmd->cmd[p->i][0] == '\0')
		return (0);
	if (ft_strcmp(p->cmd->cmd[p->i], "export") && \
			ft_strcmp(p->cmd->cmd[p->i], "cd") && \
			ft_strcmp(p->cmd->cmd[p->i], "env") && \
			ft_strcmp(p->cmd->cmd[p->i], "unset") && \
			ft_strcmp(p->cmd->cmd[p->i], "pwd") && \
			ft_strcmp(p->cmd->cmd[p->i], "echo"))
		return (0);
	return (1);
}
