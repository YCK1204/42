/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:52 by wonljeon          #+#    #+#             */
/*   Updated: 2023/04/10 18:52:25 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	lst_insert_orm(t_lst **head, t_lst **tail, char *envp)
{
	t_lst	*new;
	t_lst	*cur;
	t_lst	*prev;

	new = malloc(sizeof(t_lst));
	new->envs = ft_strdup(envp);
	cur = (*head)->next;
	while (cur != (*tail) && ft_strcmp(cur->envs, envp) < 0)
		cur = cur->next;
	prev = cur->prev;
	new->prev = prev;
	new->next = cur;
	cur->prev = new;
	prev->next = new;
}

void	signal_cmd(int sig)
{
	if (sig == 2)
	{
		g_exit_code = 1;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	redirect_flag_init(t_pipex *pipex)
{
	pipex->cmd = (t_cmd *)malloc(sizeof(t_cmd));
	pipex->syntax = (t_syntax *)malloc(sizeof(t_syntax));
	pipex->redirect = (t_redirect *)malloc(sizeof(t_redirect));
	ft_memset(pipex->syntax->err_flag, 0, 128);
	pipex->syntax->err_flag['<']++;
	pipex->syntax->err_flag['>']++;
	pipex->syntax->err_flag['#']++;
	pipex->syntax->err_flag['(']++;
	pipex->syntax->err_flag[')']++;
	pipex->syntax->err_flag['\n']++;
	pipex->syntax->err_flag[';']++;
	pipex->syntax->err_flag['|']++;
}

void	init_ep(t_pipex *pipex, t_lst **head)
{
	t_lst	*node;
	size_t	i;

	node = (*head)->next;
	i = 0;
	while (node->envs && ++i)
		node = node->next;
	pipex->ep = (char **)malloc(sizeof(char *) * (i + 1));
	pipex->ep[i] = NULL;
	node = (*head)->next;
	i = 0;
	while (node->envs)
	{
		pipex->ep[i++] = ft_strdup(node->envs);
		node = node->next;
	}
	i = 0;
	while (pipex->ep[i] && ft_strncmp(pipex->ep[i], "PATH", 4))
		i++;
	if (pipex->ep[i])
		pipex->path = ft_split(&pipex->ep[i][5], ':');
	else
		pipex->path = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex			pipex;
	struct termios	new;

	if (ac != 1)
	{
		ft_putstr_fd("minishell: argument error!\n", 2);
		return (127);
	}
	(void)av;
	if (built_in_init(&pipex.head, &pipex.tail, envp, &pipex))
		return (127);
	redirect_flag_init(&pipex);
	signal(SIGINT, signal_cmd);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(0, &new);
	new.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &new);
	start_shell(&pipex, &pipex.head, &pipex.tail, NULL);
	return (0);
}
