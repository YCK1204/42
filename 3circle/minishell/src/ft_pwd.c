/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:43 by wonljeon          #+#    #+#             */
/*   Updated: 2023/03/27 15:22:50 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_pwd(t_lst **head, t_lst **tail)
{
	char	*str;
	char	*tmp;

	g_exit_code = 0;
	(void)head;
	(void)tail;
	str = NULL;
	tmp = getcwd(str, 1024);
	printf("%s\n", tmp);
	free(tmp);
}
