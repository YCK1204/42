/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:53:57 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/26 13:29:04 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*cmd_root(t_pipex *pipex, char *cmd)
{
	size_t	i;
	char	*temp;
	char	*root;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (pipex->path == NULL)
		return (ft_strdup("/"));
	i = 0;
	temp = ft_strjoin("/", cmd);
	root = ft_strjoin(pipex->path[i], temp);
	while (pipex->path[i] && access(root, X_OK))
	{
		free(root);
		root = ft_strjoin(pipex->path[i], temp);
		i++;
	}
	free(temp);
	return (root);
}

char	*pipe_split(t_pipex *pipex, char *line, size_t *i)
{
	size_t	p;

	p = *i;
	while (line[*i])
	{
		if (line[*i] == '|')
		{
			*i += 1;
			break ;
		}
		else if (line[*i] == '\'' || line[*i] == '\"')
			quote_pass_util(pipex, line, i, &pipex->k);
		else
			*i += 1;
	}
	return (ft_substr(line, p, *i - p - 1));
}

void	cut_pipe(t_pipex *pipex, char *line, size_t point)
{
	size_t	i;
	size_t	j;

	if (pipex->pipe_cnt == 0)
	{
		pipex->cmd->cut_pipe = (char **)malloc(sizeof(char *) * 2);
		pipex->cmd->cut_pipe[1] = NULL;
		pipex->cmd->cut_pipe[0] = ft_strdup(line);
		return ;
	}
	i = 0;
	j = 0;
	pipex->cmd->cut_pipe = (char **)malloc(sizeof(char *) * \
			(pipex->pipe_cnt + 2));
	pipex->cmd->cut_pipe[pipex->pipe_cnt + 1] = NULL;
	while (i < pipex->pipe_cnt)
		pipex->cmd->cut_pipe[i++] = pipe_split(pipex, line, &j);
	pipex->cmd->cut_pipe[i] = ft_substr(line, j, \
			ft_strlen(&line[point]) - 1);
}

void	quote_pass_util(t_pipex *pipex, char *line, size_t *i, size_t *ret)
{
	pipex->cmd->quote_flag = 1;
	if (line[*i] == '\'')
		pass_quote(pipex, line, i, '\'');
	else if (line[*i] == '\"')
		pass_quote(pipex, line, i, '\"');
	if (ret)
	{
		while (line[*i] && line[*i] == ' ')
			*i += 1;
		*ret += 1;
	}
}

void	quote_pass_util1(t_pipex *pipex, char *line, size_t *i, size_t *ret)
{
	size_t	j;

	j = *i;
	pipex->k++;
	pipex->cmd->quote_flag = 1;
	if (line[*i] == '\'')
		pass_quote1(line, i, '\'');
	else if (line[*i] == '\"')
		pass_quote1(line, i, '\"');
	if (*i == j + 1)
	{
		pipex->cmd->quote_flag = 0;
		pipex->k--;
	}
	if (ret)
	{
		while (line[*i] && line[*i] == ' ')
			*i += 1;
		*ret += 1;
	}
}
