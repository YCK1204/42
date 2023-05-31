/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:27:26 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/15 17:09:21 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/push_swap.h"

int	temp_sort(t_stack *a)
{
	t_node	*temp;
	int		flag;

	if (a->size < 2)
		return (1);
	temp = a->head->next;
	flag = 0;
	while (temp->next != a->tail)
	{
		if (temp->rank + 1 != temp->next->rank)
			flag++;
		if (flag > 1)
			break ;
		temp = temp->next;
	}
	if (flag > 1)
		return (0);
	return (1);
}

void	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9') && str[i] != ' ')
			err();
		i++;
	}
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			i;
	int			m_cnt;

	check_str((char *)str);
	i = 0;
	m_cnt = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			m_cnt++;
	}
	if (!('0' <= str[i] && str[i] <= '9'))
		err();
	while ('0' <= str[i] && str[i] <= '9')
	{
		num *= 10;
		num += str[i++] - '0';
	}
	if (m_cnt)
		num = -num;
	if (num < -2147483648 || num > 2147483647)
		err();
	return ((int)num);
}

void	three(t_stack *a)
{
	t_node	*top;
	t_node	*bottom;

	while (!is_sort(a))
	{
		top = a->head->next;
		bottom = a->tail->prev;
		if (top->rank + 2 == top->next->rank || \
				top->rank - 1 == top->next->rank)
			sa(a, 1);
		else if (top->rank - 2 == top->next->rank)
			ra(a, 1);
		else if (top->rank - 1 == bottom->rank)
			rra(a, 1);
	}
}

void	rotate(t_stack *a, int next_rank)
{
	t_node	*node;
	int		i;

	i = 0;
	node = a->head->next;
	while (node->rank != next_rank && ++i)
		node = node->next;
	if (i <= a->size / 2)
		while (a->head->next->rank != next_rank)
			ra(a, 1);
	else
		while (a->head->next->rank != next_rank)
			rra(a, 1);
}
