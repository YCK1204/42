/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:57:13 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/26 17:00:57 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	init_pipe_cnt(t_pipex *pipex, char *line)
{
	size_t	i;
	int		ret;

	if (pipex->syntax->err)
		return ;
	i = 0;
	ret = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
			ret++;
			i++;
		}
		else if (line[i] == '\'' | line[i] == '\"')
			quote_pass_util(pipex, line, &i, &pipex->k);
		else
			i++;
	}
	pipex->pipe_cnt = ret;
}

void	create_pipe(t_pipex *pipex)
{
	int	i;

	if (!pipex->pipe_cnt)
		return ;
	i = -1;
	pipex->fds = (int *)malloc(sizeof(int) * (pipex->pipe_cnt * 2));
	while ((size_t)++i < pipex->pipe_cnt)
		pipe(&pipex->fds[i * 2]);
}

void	close_pipes(t_pipex *p)
{
	int	i;

	i = -1;
	while ((size_t)++i < p->pipe_cnt * 2)
	{
		close(p->fds[i]);
	}
}
