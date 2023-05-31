/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:22 by wonljeon          #+#    #+#             */
/*   Updated: 2023/03/26 17:15:14 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_newline_2(char **cmdline, int *i, int j)
{
	while (cmdline[*i])
	{
		if (cmdline[*i][0] == '-')
		{
			j = 1;
			while (cmdline[*i][j])
			{
				if (cmdline[*i][j] != 'n')
				{
					if (*i == 1)
						return (0);
					else if (*i != 1)
						return (-1);
				}
				j++;
			}
		}
		else if (cmdline[*i][0] != '-' && *i != 1)
			return (-1);
		else if (cmdline[*i][0] != '-' && *i == 1)
			return (0);
		*i = *i + 1;
	}
	return (-1);
}

int	check_newline(char **cmdline, int *i)
{
	int	j;
	int	n;

	j = 0;
	if (cmdline[1][0] != '-')
		return (0);
	n = check_newline_2(cmdline, i, j);
	return (n);
}

void	print_echo(char **cmdline, int j, int n)
{
	while (cmdline[j])
	{
		printf("%s", cmdline[j]);
		if (cmdline[j + 1] != NULL)
			printf(" ");
		j++;
	}
	if (n == 0)
		printf("\n");
}
