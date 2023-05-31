/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@stdent.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:11:25 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/12 17:17:26 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				content;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b);
void	ft_lstadd_front(t_stack *lst, t_node *new);
void	ft_lstadd_back(t_stack *lst, t_node *new);
void	err(void);
void	ft_putstr(char *str);
t_stack	*init_stack(void);
t_node	*ft_lstlast(t_stack *lst);
t_node	*ft_lstnew(int content);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);

void	three(t_stack *a);
int		temp_sort(t_stack *a);
void	insert_b(t_stack *a, t_stack *b, int div, int level);
void	s_sort(t_stack *a, t_stack *b);
void	a_to_b(t_stack *a, t_stack *b, int level, int chunk);
int		is_sort(t_stack *lst);
void	rotate(t_stack *a, int next_rank);
void	rot_a(t_stack *a, t_stack *b, int size);
#endif
