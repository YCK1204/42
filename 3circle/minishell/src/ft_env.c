/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:28 by wonljeon          #+#    #+#             */
/*   Updated: 2023/03/27 15:22:40 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

char	*remove_slash(char *str)
{
	char	*first;
	char	*second;
	char	*ret;
	int		cnt;

	if (!str)
		return (NULL);
	ret = ft_strdup(str);
	free(str);
	if (ft_strchr(ret, '\\') != 0)
	{
		while (ft_strchr(ret, '\\') != 0)
		{
			cnt = ft_strchr_num(ret, '\\');
			first = ft_substr(ret, 0, cnt);
			second = ft_substr(ret, cnt + 1, ft_strlen(ret));
			free(ret);
			ret = ft_strjoin(first, second);
			free(first);
			free(second);
		}
	}
	return (ret);
}

void	print_env(t_lst *head, t_lst *tail)
{
	t_lst	*cur;

	cur = head->next;
	while (cur != tail)
	{
		if (ft_strchr(cur->envs, '=') != 0)
			printf("%s\n", cur->envs);
		cur = cur->next;
	}
}

void	ft_env(t_lst *head, t_lst *tail, char **cmdline, int pipe_cnt)
{
	int		i[2];

	i[0] = 0;
	g_exit_code = 0;
	while (cmdline[++i[0]])
	{
		if (ft_strchr(cmdline[i[0]], '=') == 0)
		{
			printf("env: %s: No such file or directory\n", cmdline[1]);
			if (pipe_cnt == 0)
				g_exit_code = 1;
			else if (pipe_cnt != 0)
				exit (1);
			return ;
		}
	}
	print_env(head, tail);
	i[0] = 0;
	while (cmdline[++i[0]])
		printf("%s\n", cmdline[i[0]]);
}
