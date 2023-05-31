/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:02:27 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/12 22:58:51 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/push_swap.h"

void	rot_a(t_stack *a, t_stack *b, int size)
{
	if ((a->size > 1 && a->head->next->rank == a->head->next->next->rank + 1) \
			|| (a->size > 2 && a->head->next->rank + 1 == \
				a->head->next->next->next->rank))
	{
		if (b->size > 1 && b->head->next->rank < b->head->next->next->rank)
			ss(a, b);
		else
			sa(a, 1);
	}
	else if (a->head->next->rank + 1 == \
			a->head->next->next->rank)
	{
		if (b->size > 1 && b->head->next->rank < b->tail->prev->rank)
			rr(a, b);
		else
			ra(a, 1);
	}
	else
		pb(a, b);
}

unsigned long	ft_count(char *str, char c)
{
	unsigned long	cnt;
	unsigned long	i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != '\0' && str[i] != c)
		{
			cnt++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
		{
			while (str[i] != '\0' && str[i] == c)
				i++;
		}
	}
	return (cnt);
}

unsigned long	ft_len(char *str, char c)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

int	str_init(char **str, char c, unsigned long cnt, char *src)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;

	k = 0;
	i = 0;
	while (i < cnt)
	{
		if (src[k] != '\0' && src[k] != c)
		{
			j = 0;
			str[i] = (char *)malloc(sizeof(char) * (ft_len(&src[k], c) + 1));
			if (str[i] == NULL)
				return (1);
			while (src[k] != '\0' && src[k] != c)
				str[i][j++] = src[k++];
			str[i++][j] = '\0';
		}
		else
			while (src[k] != '\0' && src[k] == c)
				k++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned long	cnt;
	unsigned long	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	cnt = ft_count((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (str == NULL)
		return (NULL);
	if (str_init(str, c, cnt, (char *)s))
	{
		while (str[i])
			free(str[i++]);
		free(str);
		return (NULL);
	}
	str[cnt] = NULL;
	return (str);
}
