/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:21:58 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/15 19:12:12 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/push_swap_bonus.h"

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1[i] == str2[i])
	{
		if (!str1[i])
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return ((int)((unsigned char)str1[i] - (unsigned char)str2[i]));
}

void	operator(t_stack *a, t_stack *b, char *cmd, int n)
{
	if (!ft_strncmp(cmd, "ra", n))
		ra(a);
	else if (!ft_strncmp(cmd, "rb", n))
		rb(b);
	else if (!ft_strncmp(cmd, "rr", n))
		rr(a, b);
	else if (!ft_strncmp(cmd, "pa", n))
		pa(a, b);
	else if (!ft_strncmp(cmd, "pb", n))
		pb(a, b);
	else if (!ft_strncmp(cmd, "rra", n))
		rra(a);
	else if (!ft_strncmp(cmd, "rrb", n))
		rrb(b);
	else if (!ft_strncmp(cmd, "rrr", n))
		rrr(a, b);
	else if (!ft_strncmp(cmd, "sa", n))
		sa(a);
	else if (!ft_strncmp(cmd, "sb", n))
		sb(b);
	else if (!ft_strncmp(cmd, "ss", n))
		ss(a, b);
	else
		err();
}

void	checker(t_stack *a, t_stack *b)
{
	char	*cmd;
	char	*line;
	int		i;

	line = get_next_line(0);
	free(line);
	while (line)
	{
		operator(a, b, line, BUFFER_SIZE + 1);
		line = get_next_line(0);
		free(line);
	}
	if (is_sort(a))
		return (ft_putstr("OK\n"));
	return (ft_putstr("KO\n"));
}
