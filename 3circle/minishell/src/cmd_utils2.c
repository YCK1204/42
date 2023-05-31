/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:50:00 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/25 17:48:37 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

size_t	cmd_cnt(t_pipex *pipex, char *line, size_t i, size_t ret)
{
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == '<' || line[i] == '>')
			pass_redirect(line, &i, &pipex->j);
		else
		{
			while (line[i] && line[i] != ' ' && \
				line[i] != '<' && line[i] != '>')
			{
				if (line[i] == '\'' || line[i] == '\"')
					quote_pass_util1(pipex, line, &i, 0);
				else
					i++;
			}
			ret++;
		}
	}
	return (ret);
}

char	*cmd(t_pipex *pipex, char *line, size_t *i)
{
	pipex->k = *i;
	while (line[*i])
	{
		if (line[*i] == ' ')
			*i += 1;
		else if (line[*i] == '<' || line[*i] == '>')
			pass_redirect(line, i, &pipex->j);
		else
			return (quote_trim(pipex, line, i, ft_strdup("")));
	}
	return (ft_strdup(""));
}

char	**cmd_split(t_pipex *pipex, char *line, int k)
{
	char	**ret;
	size_t	size;
	size_t	i;
	size_t	j;

	pipex->f = 0;
	size = cmd_cnt(pipex, line, 0, 0);
	pipex->execve_cmd[k] = size;
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	ret[size] = NULL;
	i = 0;
	j = 0;
	while (i < size)
	{
		pipex->cmd->quote_flag = 0;
		ret[i++] = cmd(pipex, line, &j);
	}
	if (size == 0)
		pipex->cmd->cmd[k] = ft_strdup("");
	else if (++pipex->cmd->execve_cnt)
		pipex->cmd->cmd[k] = ft_strdup(ret[0]);
	return (ret);
}

size_t	redirect_cnt(t_pipex *pipex, char *line)
{
	size_t	ret;
	size_t	i;

	i = 0;
	ret = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quote_pass_util1(pipex, line, &i, &pipex->j);
		else if (line[i] == '<' || line[i] == '>')
		{
			pass_redirect(line, &i, &ret);
			while (line[i] && line[i] != '<' && line[i] != '>')
				i++;
		}
		else
			i++;
	}
	return (ret);
}

void	check_redirect_syntax(t_pipex *p, int i, int j)
{
	while (p->cmd->redirect[++i])
	{
		j = -1;
		while (p->cmd->redirect[i][++j])
		{
			if (j % 2)
			{
				if (p->syntax->err_flag[(int)p->cmd->redirect[i][j][0]] || \
						p->cmd->redirect[i][j][0] == '\0')
				{
					p->syntax->err = 1;
					p->syntax->err_idx[0] = i;
					p->syntax->err_idx[1] = j;
					if (p->cmd->redirect[i][j][0] == '\0')
						p->syntax->err_name = ft_strdup("newline");
					else
						p->syntax->err_name = ft_strdup(p->cmd->redirect[i][j]);
					syntax_err_continue(p, 1);
					return ;
				}
			}
		}
	}
}
