/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:18:39 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/14 17:18:47 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*value;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		value = f(lst->content);
		tmp = ft_lstnew(value);
		if (tmp == NULL)
			del(value);
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
