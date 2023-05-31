/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:01:17 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/14 19:01:04 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
		return (NULL);
	temp->head = ft_lstnew(0);
	temp->tail = ft_lstnew(0);
	temp->head->next = temp->tail;
	temp->tail->prev = temp->head;
	temp->head->prev = NULL;
	temp->tail->next = NULL;
	temp->size = 0;
	temp->head->rank = -1;
	temp->tail->rank = -1;
	return (temp);
}

void	err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	sa(t_stack *a, int print)
{
	t_node	*first;
	t_node	*second;
	int		content;
	float	rank;

	if (a->size < 2)
		return ;
	if (print)
		ft_putstr("sa\n");
	first = a->head->next;
	second = first->next;
	content = first->content;
	rank = first->rank;
	first->content = second->content;
	first->rank = second->rank;
	second->content = content;
	second->rank = rank;
}

void	sb(t_stack *b, int print)
{
	t_node	*first;
	t_node	*second;
	int		content;
	float	rank;

	if (b->size < 2)
		return ;
	if (print)
		ft_putstr("sb\n");
	first = b->head->next;
	second = first->next;
	content = first->content;
	rank = first->rank;
	first->content = second->content;
	first->rank = second->rank;
	second->content = content;
	second->rank = rank;
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	sa(a, 0);
	sb(b, 0);
	ft_putstr("ss\n");
}
