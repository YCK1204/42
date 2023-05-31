/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:34 by wonljeon          #+#    #+#             */
/*   Updated: 2023/03/25 14:31:13 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_strchr_num(const char *str, int c)
{
	int		i;
	char	temp;
	char	*stemp;

	i = 0;
	temp = (char)c;
	stemp = (char *)str;
	while (stemp[i] != temp)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (i);
}

void	print_export_orm(t_lst **head, t_lst **tail)
{
	int		i;
	char	*first;
	char	*second;
	t_lst	*cur;

	i = -1;
	cur = (*head)->next;
	while (cur != *tail)
	{
		if (ft_strchr(cur->envs, '=') != 0)
		{
			i = ft_strchr_num(cur->envs, '=');
			first = ft_substr(cur->envs, 0, i + 1);
			second = ft_substr(cur->envs, i + 1, \
			ft_strlen(cur->envs) - (i + 1));
			printf("%s\"%s\"\n", first, second);
			free(first);
			free(second);
		}
		else
			printf("%s\n", cur->envs);
		cur = cur->next;
	}
}

void	print_export_orm_without_quote(t_lst **head, t_lst **tail)
{
	t_lst	*cur;

	cur = (*head)->next;
	while (cur != *tail)
	{
		printf("%s\n", cur->envs);
		cur = cur->next;
	}
}

int	free_and_dup(t_lst *cur, char *cmd, char *equal_cmd)
{
	free(cur->envs);
	cur->envs = ft_strdup(cmd);
	free(equal_cmd);
	return (1);
}

void	for_25(int	*i, char **equal_cmd, char *cmd)
{
	if (ft_strchr(cmd, '=') != 0)
	{
		*i = ft_strchr_num(cmd, '=');
		*equal_cmd = ft_substr(cmd, 0, *i);
	}
	else if (ft_strchr(cmd, '=') == 0)
	{
		*equal_cmd = ft_strdup(cmd);
	}
}
