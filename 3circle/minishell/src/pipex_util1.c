/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:33:01 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/27 15:39:40 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	init_shell(t_pipex *pipex)
{
	pipex->syntax->err = 0;
	pipex->redirect->err_file = 0;
	pipex->cmd->execve_cnt = 0;
	pipex->cmd->here_doc_cnt = 0;
	pipex->redirect->infile = 0;
	pipex->redirect->outfile = 0;
	pipex->comment_flag = 0;
	pipex->pipe_cnt = 0;
	pipex->cmd->limit_quote = NULL;
	pipex->fds = NULL;
	pipex->line = NULL;
	pipex->ep = NULL;
	pipex->is_cmd = NULL;
	pipex->cmd->cmd = NULL;
	pipex->cmd->cmd_opt = NULL;
	pipex->cmd->redirect = NULL;
	pipex->cmd->cut_pipe = NULL;
	pipex->syntax->err_name = NULL;
	pipex->execve_cmd = NULL;
	pipex->is_cmd = NULL;
	unlink("here_doc_tmp.txt");
	pipex->line = readline("minishell$ ");
	add_history(pipex->line);
	if (WIFEXITED(g_exit_code))
		g_exit_code = WEXITSTATUS(g_exit_code);
}

char	*actual_change(t_lst **head, t_lst **tail, char *tmp)
{
	int		i;
	t_lst	*cur;
	char	*first;
	char	*second;

	cur = (*head)->next;
	while (cur != (*tail))
	{
		if (ft_strchr(cur->envs, '=') != 0)
		{
			i = ft_strchr_num(cur->envs, '=');
			first = ft_substr(cur->envs, 0, i);
			second = ft_substr(cur->envs, i + 1, ft_strlen(cur->envs));
			if (ft_strcmp(tmp, first) == 0)
			{
				free(first);
				return (second);
			}
			free(first);
			free(second);
		}
		cur = cur->next;
	}
	second = ft_strdup("");
	return (second);
}

void	free_util(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	if (pipex->cmd->limit_quote)
	{
		while (i <= pipex->pipe_cnt)
			free(pipex->cmd->limit_quote[i++]);
		free(pipex->cmd->limit_quote);
	}
	if (pipex->ep)
		two_pointer_free(pipex->ep);
	if (pipex->cmd->cmd_opt)
		three_pointer_free(pipex->cmd->cmd_opt);
	if (pipex->cmd->redirect)
		three_pointer_free(pipex->cmd->redirect);
	if (pipex->cmd->cut_pipe)
		two_pointer_free(pipex->cmd->cut_pipe);
	if (pipex->cmd->cmd)
		two_pointer_free(pipex->cmd->cmd);
	if (pipex->is_cmd)
		free(pipex->is_cmd);
}

void	end_shell(t_pipex *pipex)
{
	unlink("here_doc_tmp.txt");
	unlink("print_err.txt");
	if (pipex->line)
		free(pipex->line);
	if (pipex->fds)
		free(pipex->fds);
	if (pipex->syntax->err_name)
		free(pipex->syntax->err_name);
	if (pipex->execve_cmd)
		free(pipex->execve_cmd);
	if (pipex->redirect->infile)
		close(pipex->redirect->infile);
	if (pipex->redirect->outfile)
		close(pipex->redirect->outfile);
	if (pipex->redirect->err_file)
		close(pipex->redirect->err_file);
	free_util(pipex);
}

int	dollar_alnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || \
	(c >= 97 && c <= 122) || c == '_')
		return (4);
	else
		return (0);
}
