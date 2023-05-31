/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:47 by wonljeon          #+#    #+#             */
/*   Updated: 2023/03/27 15:22:19 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*find_special_middle_for_unset(char *str, int pipe_cnt)
{
	char	*tmp;
	int		i;

	i = -1;
	if (!ft_isalpha(str[0]))
	{
		printf("unset: `%s': not a valid identifier\n", str);
		check_pipe_cnt(pipe_cnt);
		return (NULL);
	}
	tmp = ft_strdup(str);
	free(str);
	while (tmp[++i])
	{
		if (ft_isalnum(tmp[i]) == 0)
		{
			printf("unset: `%s': not a valid identifier\n", str);
			check_pipe_cnt(pipe_cnt);
			return (NULL);
		}
	}
	return (tmp);
}

t_lst	*find_equal(t_lst *cur, char *a, char *cmd)
{
	t_lst	*tmp;

	if (ft_strcmp(cmd, a) == 0)
	{
		free(cur->envs);
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		tmp = cur;
		cur = cur->prev;
		free(tmp);
	}
	return (cur);
}

void	check_cmd_in_list(t_lst **head, t_lst **tail, char *cmd)
{
	int		i;
	t_lst	*cur;
	char	*check_str;

	cur = (*head)->next;
	while (cur != (*tail))
	{
		if (ft_strchr(cur->envs, '=') != 0)
		{
			i = ft_strchr_num(cur->envs, '=');
			check_str = ft_substr(cur->envs, 0, i);
			cur = find_equal(cur, check_str, cmd);
			free(check_str);
		}
		else if (ft_strchr(cur->envs, '=') == 0)
			find_equal(cur, cur->envs, cmd);
		cur = cur->next;
	}
}

void	ft_unset(t_lst **head, t_lst **tail, char **cmdline, int pipe_cnt)
{
	char	*ret;
	int		i[2];

	i[0] = 0;
	g_exit_code = 0;
	while (cmdline[++i[0]] != NULL)
	{
		ret = ft_strdup(cmdline[i[0]]);
		ret = find_special_middle_for_unset(ret, pipe_cnt);
		if (!ret)
		{
			free(ret);
			continue ;
		}
		check_cmd_in_list(head, tail, ret);
		free(ret);
	}
}
