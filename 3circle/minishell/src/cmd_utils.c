/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:34:10 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/25 17:37:51 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	discriminate_redirect(char *line, size_t *i)
{
	if (line[*i] == '<')
	{
		*i += 1;
		if (line[*i] == '<')
		{
			*i += 1;
			return (1);
		}
		else
			return (2);
	}
	else if (line[*i] == '>')
	{
		*i += 1;
		if (line[*i] == '>')
		{
			*i += 1;
			return (3);
		}
		else
			return (4);
	}
	return (0);
}

char	*redirect(t_pipex *pipex, char *line, size_t *i)
{
	int	n;

	while (line[*i])
	{
		if (line[*i] == '\'' || line[*i] == '\"')
			quote_pass_util1(pipex, line, i, &pipex->k);
		else
		{
			n = discriminate_redirect(line, i);
			if (n == 1)
			{
				pipex->cmd->here_doc_cnt++;
				return (ft_strdup("<<"));
			}
			else if (n == 2)
				return (ft_strdup("<"));
			else if (n == 3)
				return (ft_strdup(">>"));
			else if (n == 4)
				return (ft_strdup(">"));
			else if (n == 0)
				*i += 1;
		}
	}
	return (NULL);
}

char	*file_name(t_pipex *pipex, char *line, size_t *i)
{
	size_t	temp;

	while (line[*i])
	{
		if (line[*i] == ' ')
			*i += 1;
		else
		{
			temp = *i;
			while (line[*i] && pipex->syntax->err_flag[(int)line[*i]])
				*i += 1;
			return (quote_trim(pipex, line, i, \
						ft_substr(line, temp, *i - temp)));
		}
	}
	return (ft_strdup(""));
}

char	**redirect_split(t_pipex *p, char *line, size_t j, char **ret)
{
	size_t	size;

	size = redirect_cnt(p, line) * 2;
	p->cmd->limit_quote[p->i] = (size_t *)ft_calloc(sizeof(size_t), size);
	ret = (char **)ft_calloc(sizeof(char *), (size + 1));
	ret[size] = NULL;
	p->cmd->redirect_cnt += size;
	p->j = 0;
	while (p->j < size)
	{
		p->cmd->quote_flag = 0;
		p->cmd->limit_quote[p->i][p->j] = 0;
		ret[p->j++] = redirect(p, line, &j);
		ret[p->j++] = file_name(p, line, &j);
	}
	if (size == 0)
	{
		free(ret);
		ret = (char **)ft_calloc(sizeof(char *), 2);
		ret[0] = ft_strdup("");
		ret[1] = NULL;
	}
	return (ret);
}

void	execve_cmd_init(t_pipex *p, char *line, int i)
{
	if (p->syntax->err)
		return ;
	cut_pipe(p, line, 0);
	p->cmd->redirect_cnt = 0;
	p->cmd->cmd = (char **)ft_calloc(sizeof(char *), (p->pipe_cnt + 2));
	p->cmd->cmd_opt = (char ***)ft_calloc(sizeof(char **), (p->pipe_cnt + 2));
	p->cmd->redirect = (char ***)ft_calloc(sizeof(char **), (p->pipe_cnt + 2));
	p->execve_cmd = (int *)ft_calloc(sizeof(int), (p->pipe_cnt + 1));
	p->cmd->limit_quote = (size_t **)ft_calloc(sizeof(size_t *), \
		(p->pipe_cnt + 1));
	p->cmd->cmd[p->pipe_cnt + 1] = NULL;
	p->cmd->cmd_opt[p->pipe_cnt + 1] = NULL;
	p->cmd->redirect[p->pipe_cnt + 1] = NULL;
	p->i = 0;
	while ((size_t)++i <= p->pipe_cnt)
	{
		p->f = 1;
		p->cmd->redirect[i] = redirect_split(p, p->cmd->cut_pipe[i], 0, NULL);
		p->j = 0;
		p->cmd->cmd_opt[i] = cmd_split(p, p->cmd->cut_pipe[i], i);
		p->i++;
	}
	check_redirect_syntax(p, -1, -1);
}
