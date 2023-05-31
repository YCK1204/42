/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 02:36:39 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:47:24 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/pipex_bonus.h"

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
	p->p_cmds = NULL;
	p->cmds = NULL;
	p->path = NULL;
	p->fds = NULL;
}

void	all_free(t_pipex *p)
{
	int	i;

	if (p->path)
		two_pointer_free(p->path);
	if (p->p_cmds)
	{
		i = 0;
		while (p->p_cmds[i])
			two_pointer_free(p->p_cmds[i++]);
		free(p->p_cmds);
	}
	if (p->cmds)
		two_pointer_free(p->cmds);
	if (p->fds)
		free(p->fds);
}
