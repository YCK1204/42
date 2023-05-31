/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 02:24:31 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:29:59 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/pipex.h"

void	two_pointer_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	init(t_pipex *p)
{
	p->p_cmd1 = NULL;
	p->p_cmd2 = NULL;
	p->cmd1 = NULL;
	p->cmd2 = NULL;
	p->path = NULL;
}

void	all_free(t_pipex *p)
{
	if (p->path)
		two_pointer_free(p->path);
	if (p->p_cmd1)
		two_pointer_free(p->p_cmd1);
	if (p->p_cmd2)
		two_pointer_free(p->p_cmd2);
	if (p->cmd1)
		free(p->cmd1);
	if (p->cmd2)
		free(p->cmd2);
}
