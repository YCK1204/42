/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:15:58 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/14 19:13:37 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/push_swap_bonus.h"

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

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	int		content;
	float	rank;

	if (a->size < 2)
		return ;
	first = a->head->next;
	second = first->next;
	content = first->content;
	rank = first->rank;
	first->content = second->content;
	first->rank = second->rank;
	second->content = content;
	second->rank = rank;
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	int		content;
	float	rank;

	if (b->size < 2)
		return ;
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
	sa(a);
	sb(b);
}
