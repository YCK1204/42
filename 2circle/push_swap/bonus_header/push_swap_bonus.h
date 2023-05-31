/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:16:44 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/15 18:47:55 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define BUFFER_SIZE 42
# define STDIN 0
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

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
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
void	checker(t_stack *a, t_stack *b);
int		is_sort(t_stack *lst);
void	s_sort(t_stack *a, t_stack *b);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
#endif
