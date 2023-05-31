/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:02 by wonljeon          #+#    #+#             */
/*   Updated: 2023/03/27 15:22:01 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	set_oldpwd_pwd(t_lst **head, t_lst **tail)
{
	char	*tmp;
	char	*old_pwd;
	char	*current_pwd;
	t_lst	*cur;

	cur = (*head)->next;
	tmp = malloc(sizeof(char) * 1024);
	current_pwd = ft_strjoin("PWD=", getcwd(tmp, 1024));
	old_pwd = ft_strjoin("OLDPWD=", find_env_value("PWD", head, tail));
	while (cur != (*tail))
	{
		if (ft_strnstr(cur->envs, "PWD=", 4))
		{
			free(cur->envs);
			cur->envs = ft_strdup(current_pwd);
		}
		else if (ft_strnstr(cur->envs, "OLDPWD=", 7))
		{
			free(cur->envs);
			cur->envs = ft_strdup(old_pwd);
		}
		cur = cur->next;
	}
	free_cd_all(current_pwd, old_pwd, tmp);
}

void	ft_move_home(t_lst **head, t_lst **tail, int pipe_cnt)
{
	char	*path;

	path = find_env_value("HOME", head, tail);
	if (chdir(path) == -1)
	{
		printf("minishell: %s: %s\n", "cd", "HOME not set");
		if (pipe_cnt == 0)
			g_exit_code = 1;
		else if (pipe_cnt != 0)
			exit(1);
	}
}

void	ft_move_back(t_lst **head, t_lst **tail, int pipe_cnt)
{
	char	*path;

	path = find_env_value("OLDPWD", head, tail);
	if (chdir(path) == -1)
	{
		printf("minishell: %s: %s\n", "cd", "OLDPWD not set");
		if (pipe_cnt == 0)
			g_exit_code = 1;
		else if (pipe_cnt != 0)
			exit(1);
	}
}

void	real_move(t_lst **head, t_lst **tail, char **cmdline, int pipe_cnt)
{
	char	*address;
	char	*tmp;

	if ((cmdline[1][0] == '~' && cmdline[1][1] == '\0') || cmdline[1] == NULL)
		move_home_and_set_pwd(head, tail, pipe_cnt);
	else if (cmdline[1][0] == '-' && cmdline[1][1] == '\0')
		move_back_and_set_pwd(head, tail, pipe_cnt);
	else if (cmdline[1] != NULL)
	{
		if (cmdline[1][0] == '~')
		{
			address = wave_add(head, tail);
			tmp = ft_strtrim(cmdline[1], "~");
			free(cmdline[1]);
			cmdline[1] = ft_strjoin(address, tmp);
			free(address);
			free(tmp);
		}
		if (chdir(cmdline[1]) == -1)
		{
			printf("minishell: %s: %s: %s\n", "cd", cmdline[1], strerror(errno));
			check_pipe_cnt(pipe_cnt);
		}
		set_oldpwd_pwd(head, tail);
	}
}

void	ft_cd(t_lst **head, t_lst **tail, char **cmdline, int pipe_cnt)
{
	int		i;

	i = 0;
	g_exit_code = 0;
	if (cmdline[1] == NULL)
	{
		ft_move_home(head, tail, pipe_cnt);
		set_oldpwd_pwd(head, tail);
		return ;
	}
	real_move(head, tail, cmdline, pipe_cnt);
}
