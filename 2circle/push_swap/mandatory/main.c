/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@stdent.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:09:34 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/15 19:15:39 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/push_swap.h"

void	init(int ac, char **av, t_stack **a)
{
	int		i;
	int		j;
	char	**temp;

	i = ac;
	while (--i > 0)
	{
		temp = ft_split(av[i], ' ');
		j = 0;
		while (temp[j])
			j++;
		while (--j >= 0)
		{
			(*a)->size++;
			ft_lstadd_front(*a, ft_lstnew(ft_atoi(temp[j])));
			free(temp[j]);
		}
		free(temp);
	}
}

void	overlap_check(t_stack *a)
{
	t_node	*temp;
	t_node	*cur;

	temp = a->head->next;
	while (temp != a->tail)
	{
		cur = temp->next;
		while (cur != a->tail)
		{
			if (temp->content == cur->content)
				err();
			cur = cur->next;
		}
		temp = temp->next;
	}
}

void	init_rank(t_stack *a)
{
	t_node	*temp;
	t_node	*cur;

	temp = a->head->next;
	while (temp != a->tail)
	{
		cur = a->head->next;
		while (cur != a->tail)
		{
			if (temp->content > cur->content)
				temp->rank++;
			cur = cur->next;
		}
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (ac == 1)
		return (0);
	i = 1;
	while (i < ac)
		ft_atoi(av[i++]);
	a = init_stack();
	b = init_stack();
	init(ac, av, &a);
	overlap_check(a);
	if (is_sort(a))
		return (0);
	init_rank(a);
	if (a->size < 10)
		s_sort(a, b);
	else
		a_to_b(a, b, 1, (a->size / 100) * 5 + 7);
	return (0);
}
