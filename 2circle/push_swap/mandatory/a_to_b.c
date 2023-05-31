/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:31:44 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/13 21:03:59 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/push_swap.h"

int	search_max(t_stack *b, int max)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = b->head->next;
	while (temp->rank != max && ++i)
		temp = temp->next;
	if (i <= b->size / 2)
		return (1);
	return (-1);
}

void	b_to_a(t_stack *a, t_stack *b, int max)
{
	while (b->size != 0)
	{
		if (search_max(b, max) > 0)
		{
			while (b->head->next->rank != max)
				rb(b, 1);
		}
		else
		{
			while (b->head->next->rank != max)
				rrb(b, 1);
		}
		max--;
		pa(a, b);
	}
}

int	search_fit_rank(t_stack *a, int fit)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = a->head->next;
	while (temp->rank > fit && ++i)
		temp = temp->next;
	if (i <= a->size / 2)
		return (1);
	return (-1);
}

void	a_to_b(t_stack *a, t_stack *b, int level, int chunk)
{
	int	rank;
	int	max;

	max = a->size;
	while (a->size != 0)
	{
		rank = a->head->next->rank;
		if (rank <= level && ++level)
			pb(a, b);
		else if (rank > level && rank <= level + chunk && ++level)
		{
			pb(a, b);
			rb(b, 1);
		}
		else
		{
			if (search_fit_rank(a, level + chunk) > 0)
				ra(a, 1);
			else
				rra(a, 1);
		}
	}
	b_to_a(a, b, max);
}
