/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:16:05 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/15 17:11:25 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/push_swap_bonus.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*b_first;
	t_node	*b_second;

	if (b->size == 0)
		return ;
	b_first = b->head->next;
	b_second = b_first->next;
	if (b->size == 1)
	{
		b->head->next = b->tail;
		b->tail->prev = b->head;
	}
	else
	{
		b->head->next = b_second;
		b_second->prev = b->head;
	}
	ft_lstadd_front(a, b_first);
	a->size++;
	b->size--;
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*a_first;
	t_node	*a_second;

	if (a->size == 0)
		return ;
	a_first = a->head->next;
	a_second = a_first->next;
	if (a->size == 1)
	{
		a->head->next = a->tail;
		a->tail->prev = a->head;
	}
	else
	{
		a->head->next = a_second;
		a_second->prev = a->head;
	}
	ft_lstadd_front(b, a_first);
	b->size++;
	a->size--;
}

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a->size < 2)
		return ;
	first = a->head->next;
	second = first->next;
	ft_lstadd_back(a, first);
	a->head->next = second;
	second->prev = a->head;
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (b->size < 2)
		return ;
	first = b->head->next;
	second = first->next;
	ft_lstadd_back(b, first);
	b->head->next = second;
	second->prev = b->head;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
