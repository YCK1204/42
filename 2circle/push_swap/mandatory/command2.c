/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:07:24 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/12 22:58:33 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/push_swap.h"

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
	ft_putstr("pa\n");
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
	ft_putstr("pb\n");
}

void	ra(t_stack *a, int print)
{
	t_node	*first;
	t_node	*second;

	if (a->size < 2)
		return ;
	if (print)
		ft_putstr("ra\n");
	first = a->head->next;
	second = first->next;
	ft_lstadd_back(a, first);
	a->head->next = second;
	second->prev = a->head;
}

void	rb(t_stack *b, int print)
{
	t_node	*first;
	t_node	*second;

	if (b->size < 2)
		return ;
	if (print)
		ft_putstr("rb\n");
	first = b->head->next;
	second = first->next;
	ft_lstadd_back(b, first);
	b->head->next = second;
	second->prev = b->head;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	ft_putstr("rr\n");
}
