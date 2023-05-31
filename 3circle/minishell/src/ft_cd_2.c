/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:13 by wonljeon          #+#    #+#             */
/*   Updated: 2023/03/26 10:36:54 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*find_env_value(char *key, t_lst **head, t_lst **tail)
{
	t_lst	*cur;

	cur = (*head)->next;
	while (cur != (*tail))
	{
		if (!ft_strncmp(cur->envs, key, ft_strlen(key)))
			return (&cur->envs[ft_strlen(key) + 1]);
		cur = cur->next;
	}
	return ("");
}

void	free_cd_all(char *a, char *b, char *c)
{
	free(a);
	free(b);
	free(c);
}

char	*wave_add(t_lst **head, t_lst **tail)
{
	int		point;
	char	*first;
	char	*second;
	t_lst	*tmp;

	tmp = (*head)->next;
	while (tmp != *tail)
	{
		point = ft_strchr_num(tmp->envs, '=');
		first = ft_substr(tmp->envs, 0, point);
		second = ft_substr(tmp->envs, point + 1, ft_strlen(tmp->envs));
		if (!ft_strcmp(first, "HOME"))
		{
			free(first);
			return (second);
		}
		free(first);
		free(second);
		tmp = tmp->next;
	}
	return (NULL);
}

void	move_home_and_set_pwd(t_lst **head, t_lst **tail, int pipe_cnt)
{
	ft_move_home(head, tail, pipe_cnt);
	set_oldpwd_pwd(head, tail);
}

void	move_back_and_set_pwd(t_lst **head, t_lst **tail, int pipe_cnt)
{
	ft_move_back(head, tail, pipe_cnt);
	set_oldpwd_pwd(head, tail);
	ft_pwd(head, tail);
}
