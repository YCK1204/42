/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:35:15 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/25 14:36:08 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	here_doc_dollar(char **lst, int i[])
{
	while ((*lst)[i[0]] != '<' && (*lst)[i[0]] != '\0')
		i[0]++;
	while ((*lst)[i[0]] == '<' && (*lst)[i[0]] != '\0')
		i[0]++;
	while ((*lst)[i[0]] == ' ' && (*lst)[i[0]] != '\0')
		i[0]++;
	while ((*lst)[i[0]] != ' ' && (*lst)[i[0]] != '\0')
		i[0]++;
}

void	for_yishipoh(char **lst, int i[])
{
	i[1] = i[0]++;
	while (dollar_alnum((*lst)[i[0]]) == 4)
		i[0]++;
}

void	init_num_arr(int i[])
{
	i[0] = -1;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
}

void	set_num_arr(int i[])
{
	i[0] = i[1];
	i[0]--;
}

void	change_dollars(t_lst **head, t_lst **tail, char **lst)
{
	int		i[4];

	init_num_arr(i);
	while ((*lst)[++i[0]])
	{
		if ((*lst)[i[0]] == '\'')
			i[3]++;
		if ((*lst)[i[0]] == '<' && (*lst)[i[0] + 1] == '<' && i[3] % 2 == 0)
			here_doc_dollar(lst, i);
		if ((*lst)[i[0]] == '$' && (*lst)[i[0] + 1] == '?' && i[3] % 2 == 0)
		{
			dollar_mul(lst, i);
			continue ;
		}
		if ((*lst)[i[0]] == '$' && i[3] % 2 == 0)
		{
			for_yishipoh(lst, i);
			dollar_chn(head, tail, lst, i);
			set_num_arr(i);
		}
	}
}
