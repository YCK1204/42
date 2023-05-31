/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:18 by wonljeon          #+#    #+#             */
/*   Updated: 2023/03/27 15:22:26 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	find_special_middle_for_export_2(char **str, int k[])
{
	int	i;
	int	j;

	i = -1;
	if (!(*str))
		return ;
	while ((*str)[++i])
	{
		j = ft_isalnum_for_export((*str)[i]);
		if (j == 1)
		{
			printf("export: `%s': not a valid identifier\n", *str);
			check_pipe_cnt(k[2]);
			free(*str);
			*str = NULL;
			return ;
		}
	}
}

void	find_special_middle_for_export_3(char **str, int k[])
{
	int	i;
	int	j;

	i = -1;
	if (!(*str))
		return ;
	while ((*str)[++i])
	{
		j = ft_isalnum_for_export((*str)[i]);
		if (j == 1)
		{
			if (k[2] == 0)
				g_exit_code = 1;
			else if (k[2] != 0)
			{
				printf("export: `%s': not a valid identifier\n", *str);
				exit(1);
			}
			free(*str);
			*str = NULL;
			return ;
		}
	}
	free(*str);
}

void	check_pipe_cnt(int pipe_cnt)
{
	if (pipe_cnt == 0)
		g_exit_code = 1;
	else if (pipe_cnt != 0)
		exit(1);
}

void	ft_echo(char **cmdline)
{
	int		j;
	int		n;

	g_exit_code = 0;
	if (!cmdline[1])
	{
		printf("\n");
		return ;
	}
	j = 1;
	n = check_newline(cmdline, &j);
	if (n == 0)
		j = 1;
	print_echo(cmdline, j, n);
}
