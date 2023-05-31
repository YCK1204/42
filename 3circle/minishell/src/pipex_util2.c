/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:34:11 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/25 14:34:58 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	free_four(char *tmp, char *front, char *back, char *ret)
{
	if (tmp)
		free(tmp);
	if (front)
		free(front);
	if (back)
		free(back);
	if (ret)
		free(ret);
}

void	dollar_mul(char **lst, int i[3])
{
	char	*ito;
	char	*ap;
	char	*dui;
	char	*mp;

	i[1] = i[0];
	i[0] += 2;
	ito = ft_itoa(g_exit_code);
	ap = ft_substr((*lst), 0, i[1]);
	dui = ft_substr(*lst, i[0], ft_strlen(*lst));
	free(*lst);
	(*lst) = ft_strjoin(ap, ito);
	mp = ft_strdup(*lst);
	free(*lst);
	(*lst) = ft_strjoin(mp, dui);
	i[2] = ft_strlen(ito) - 2;
	i[0] = i[2];
	free(ito);
	free(dui);
	free(mp);
	free(ap);
}

void	free_two(char *a, char *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
}

void	free_three(char *a, char *b, char *c)
{
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free(c);
}

void	dollar_chn(t_lst **head, t_lst **tail, char **lst, int i[])
{
	char	*tmp;
	char	*ret;
	char	*front;
	char	*back;

	tmp = ft_substr(*lst, i[1] + 1, i[0] - i[1] - 1);
	ret = actual_change(head, tail, tmp);
	front = ft_substr(*lst, 0, i[1]);
	back = ft_substr(*lst, i[0], ft_strlen(*lst));
	if (ft_strcmp(ret, "") == 0)
	{
		free_two(*lst, tmp);
		*lst = ft_strjoin(front, back);
	}
	else
	{
		i[1] += ft_strlen(ret);
		free_two(*lst, tmp);
		*lst = ft_strjoin(front, ret);
		tmp = ft_strjoin(*lst, back);
		free(*lst);
		*lst = ft_strdup(tmp);
		free(tmp);
	}
	free_three(front, back, ret);
}
