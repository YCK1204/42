/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:36:34 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/27 15:43:53 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	node_free(t_lst *node)
{
	if (node->next != NULL)
		node_free(node->next);
	free(node->envs);
	free(node);
}

void	exit_shell(t_pipex *pipex, t_lst **node, int i)
{
	end_shell(pipex);
	node_free(*node);
	free(pipex->cmd);
	free(pipex->syntax);
	free(pipex->redirect);
	if (!pipex->pipe_cnt)
		write(1, "exit\n", 5);
	exit(i);
}

int	is_int(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if ('0' > str[i] || str[i] > '9')
			return (0);
	return (1);
}

void	ft_exit_util(t_pipex *p, t_lst **head)
{
	char	*err_msg;
	char	*tmp;

	if (p->redirect->err_file == 0)
		p->redirect->err_file = open("print_err.txt", \
				O_APPEND | O_CREAT | O_RDWR, 0644);
	if (!p->i && !p->pipe_cnt)
		ft_putstr_fd("exit\n", p->redirect->err_file);
	tmp = ft_strjoin("mimishell: exit: ", p->cmd->cmd_opt[p->i][1]);
	err_msg = ft_strjoin(tmp, ": numeric argument required\n");
	if (p->cmd->here_doc_cnt)
		ft_putstr_fd(err_msg, p->redirect->err_file);
	else
		ft_putstr_fd(err_msg, 2);
	free(tmp);
	free(err_msg);
	if (!p->i && !p->pipe_cnt)
		exit_shell(p, head, 255);
}

void	ft_exit(t_pipex *p, t_lst **head)
{
	if (p->cmd->cmd_opt[p->i][1] && !is_int(p->cmd->cmd_opt[p->i][1]))
		ft_exit_util(p, head);
	else if (p->cmd->cmd_opt[p->i][1] && !p->pipe_cnt)
		exit_shell(p, head, ft_atoi(p->cmd->cmd_opt[p->i][1]));
	else if (p->cmd->cmd_opt[p->i][1] && p->pipe_cnt)
	{
		g_exit_code = ft_atoi(p->cmd->cmd_opt[p->i][1]);
		p->temp = g_exit_code;
	}
	else if (!p->cmd->cmd_opt[p->i][1] && p->pipe_cnt)
	{
		g_exit_code = 0;
		p->temp = g_exit_code;
	}
	else if (!p->pipe_cnt)
	{
		exit_shell(p, head, 0);
		p->temp = 0;
	}
}
