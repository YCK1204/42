/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_commands_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:16:29 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/13 21:02:28 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/push_swap_bonus.h"

void	ft_lstadd_back(t_stack *lst, t_node *new)
{
	t_node	*last_node;

	last_node = lst->tail->prev;
	if (lst->size == 0)
	{
		lst->head->next = new;
		new->prev = lst->head;
	}
	else
	{
		last_node->next = new;
		new->prev = last_node;
	}
	lst->tail->prev = new;
	new->next = lst->tail;
}

void	ft_lstadd_front(t_stack *stack, t_node *new)
{
	t_node	*stack_first;

	stack_first = stack->head->next;
	if (stack->size == 0)
	{
		stack->tail->prev = new;
		new->next = stack->tail;
	}
	else
	{
		new->next = stack_first;
		stack_first->prev = new;
	}
	new->prev = stack->head;
	stack->head->next = new;
}

t_node	*ft_lstnew(int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (0);
	new_node->content = content;
	new_node->rank = 1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
