/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:01:50 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/13 21:04:55 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/push_swap.h"

void	max_rot(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		max;
	int		i;

	i = 0;
	max = 0;
	node = a->head->next;
	while (node != a->tail)
	{
		if (node->rank > max)
			max = node->rank;
		node = node->next;
	}
	node = a->head->next;
	while (node->rank != max && ++i)
		node = node->next;
	if (i < a->size / 2)
		while (a->tail->prev->rank != max)
			ra(a, 1);
	else
		while (a->tail->prev->rank != max)
			rra(a, 1);
	pa(a, b);
}

void	min_rot(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		min;
	int		i;

	i = 0;
	min = 2147483647;
	node = a->head->next;
	while (node != a->tail)
	{
		if (node->rank < min)
			min = node->rank;
		node = node->next;
	}
	rotate(a, min);
	pa(a, b);
}

void	mid_rot(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		n_rank;
	int		i;

	i = 0;
	n_rank = 2147483647;
	node = a->head->next;
	while (node != a->tail)
	{
		if (node->rank > b->head->next->rank && node->rank < n_rank)
			n_rank = node->rank;
		node = node->next;
	}
	rotate(a, n_rank);
	pa(a, b);
}

void	head_rot(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = a->head->next;
	while (temp != a->tail && temp->rank > b->head->next->rank)
		temp = temp->next;
	if (temp == a->tail)
		return (min_rot(a, b));
	temp = a->head->next;
	while (temp != a->tail && temp->rank < b->head->next->rank)
		temp = temp->next;
	if (temp == a->tail)
		return (max_rot(a, b));
	mid_rot(a, b);
}

void	s_sort(t_stack *a, t_stack *b)
{
	int		size;

	size = a->size;
	if (size < 4)
		return (three(a));
	while (!temp_sort(a))
		rot_a(a, b, size);
	while (b->size != 0)
	{
		if (b->size > 1 && b->head->next->rank < b->tail->prev->rank)
			rrb(b, 1);
		else if (b->size > 1 && b->head->next->rank + 1 == \
				b->head->next->next->rank)
			sb(b, 1);
		else
			head_rot(a, b);
	}
	rotate(a, 1);
}
