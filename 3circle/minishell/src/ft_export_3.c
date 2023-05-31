/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:31:37 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/26 11:30:46 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	for_25_2(int i, char *cmd, t_lst **head, t_lst **tail)
{
	t_lst	*cur;
	char	*equal_cmd;
	char	*equal_cur;

	cur = (*head)->next;
	for_25(&i, &equal_cmd, cmd);
	while (cur != (*tail))
	{
		for_25(&i, &equal_cur, cur->envs);
		if (ft_strncmp(equal_cmd, cur->envs, ft_strlen(equal_cmd)) == 0 \
		&& (ft_strlen(equal_cur) == ft_strlen(equal_cmd)))
		{
			free(equal_cur);
			return (free_and_dup(cur, cmd, equal_cmd));
		}
		cur = cur->next;
		free(equal_cur);
	}
	free(equal_cmd);
	return (0);
}

int	for_25_3(int i, t_lst **head, t_lst **tail, char *cmd)
{
	char	*equal_cmd;
	t_lst	*cur;

	cur = (*head)->next;
	while (cur != (*tail))
	{
		for_25(&i, &equal_cmd, cur->envs);
		if (ft_strncmp(cmd, equal_cmd, ft_strlen(equal_cmd)) == 0)
		{
			free(equal_cmd);
			return (1);
		}
		if (ft_strncmp(cmd, cur->envs, ft_strlen(cur->envs)) == 0)
		{
			free(equal_cmd);
			return (1);
		}
		cur = cur->next;
		free(equal_cmd);
	}
	return (0);
}

int	double_check(t_lst **head, int i, t_lst **tail, char *cmd)
{
	t_lst	*cur;
	int		j;

	cur = (*head)->next;
	if (ft_strchr(cmd, '=') != 0)
	{
		j = for_25_2(i, cmd, head, tail);
		if (j == 1)
			return (1);
	}
	else if (ft_strchr(cmd, '=') == 0)
	{
		j = for_25_3(i, head, tail, cmd);
		if (j == 1)
			return (1);
	}
	return (0);
}

int	ft_isalnum_for_export(int c)
{
	if (c == '=' || (c >= 48 && c <= 57) || (c >= 65 && c <= 90) \
	|| (c >= 97 && c <= 122) || c == '_')
		return (4);
	else
		return (1);
}
