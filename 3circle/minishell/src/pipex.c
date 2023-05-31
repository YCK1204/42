/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:19:15 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/26 16:34:29 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	start_shell_util(t_pipex *pipex, t_lst **head, t_lst **tail, char *tmp)
{
	is_space(pipex, pipex->line);
	tmp = ft_strtrim(pipex->line, " ");
	free(pipex->line);
	pipex->line = ft_strdup(tmp);
	free(tmp);
	init_pipe_cnt(pipex, pipex->line);
	signal(SIGINT, SIG_IGN);
	check_semi_colon_back_slash(pipex, pipex->line);
	check_pipe_syntax(pipex, pipex->line, 0, 0);
	change_dollars(head, tail, &pipex->line);
	is_space(pipex, pipex->line);
	execve_cmd_init(pipex, pipex->line, -1);
	execute(pipex, head, tail);
	end_shell(pipex);
}

void	start_shell(t_pipex *pipex, t_lst **head, t_lst **tail, char *tmp)
{
	while (1)
	{
		signal(SIGINT, signal_cmd);
		init_shell(pipex);
		if (pipex->line == NULL)
			exit_shell(pipex, head, 0);
		if (!ft_strcmp(pipex->line, "\0"))
		{
			end_shell(pipex);
			continue ;
		}
		start_shell_util(pipex, head, tail, tmp);
	}
}
