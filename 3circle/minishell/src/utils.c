/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:51:07 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/25 12:22:08 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	print_syntax_err(t_pipex *pipex)
{
	char	*err_msg;
	char	*tmp;
	char	*err;

	err = pipex->syntax->err_name;
	tmp = ft_strjoin("minishell: syntax error near unexpected token `", err);
	err_msg = ft_strjoin(tmp, "\'\n");
	g_exit_code = 258;
	ft_putstr_fd(err_msg, 2);
	free(tmp);
	free(err_msg);
}

void	syntax_err_continue(t_pipex *pipex, int f)
{
	print_syntax_err(pipex);
	if (f)
		handle_syntax_err(pipex);
}

void	two_pointer_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	if (str != NULL)
		free(str);
}

void	three_pointer_free(char ***str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
		two_pointer_free(str[i++]);
	if (str != NULL)
		free(str);
}

int	built_in_init(t_lst **head, t_lst **tail, char **ep, t_pipex *p)
{
	int	i;

	(void)p;
	i = -1;
	*head = (t_lst *)malloc(sizeof(t_lst));
	*tail = (t_lst *)malloc(sizeof(t_lst));
	(*head)->envs = NULL;
	(*tail)->envs = NULL;
	(*head)->next = *tail;
	(*head)->prev = NULL;
	(*tail)->next = NULL;
	(*tail)->prev = *head;
	while (ep[++i] != NULL)
		lst_insert_orm(head, tail, ep[i]);
	return (0);
}
