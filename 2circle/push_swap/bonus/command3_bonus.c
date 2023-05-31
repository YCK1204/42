/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:16:12 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/15 19:13:21 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/push_swap_bonus.h"

void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*rev_second;

	if (a->size < 2)
		return ;
	last = a->tail->prev;
	rev_second = last->prev;
	ft_lstadd_front(a, last);
	rev_second->next = a->tail;
	a->tail->prev = rev_second;
}

void	rrb(t_stack *b)
{
	t_node	*last;
	t_node	*rev_second;

	if (b->size < 2)
		return ;
	last = b->tail->prev;
	rev_second = last->prev;
	ft_lstadd_front(b, last);
	rev_second->next = b->tail;
	b->tail->prev = rev_second;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	is_sort(t_stack *lst)
{
	t_node	*temp;

	if (lst->size < 2)
		return (1);
	temp = lst->head->next;
	while (temp->next != lst->tail)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
