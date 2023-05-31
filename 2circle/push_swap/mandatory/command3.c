/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:16:36 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/12 22:58:39 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/push_swap.h"

void	rra(t_stack *a, int print)
{
	t_node	*last;
	t_node	*rev_second;

	if (a->size < 2)
		return ;
	if (print)
		ft_putstr("rra\n");
	last = a->tail->prev;
	rev_second = last->prev;
	ft_lstadd_front(a, last);
	rev_second->next = a->tail;
	a->tail->prev = rev_second;
}

void	rrb(t_stack *b, int print)
{
	t_node	*last;
	t_node	*rev_second;

	if (b->size < 2)
		return ;
	if (print)
		ft_putstr("rrb\n");
	last = b->tail->prev;
	rev_second = last->prev;
	ft_lstadd_front(b, last);
	rev_second->next = b->tail;
	b->tail->prev = rev_second;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putstr("rrr\n");
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
