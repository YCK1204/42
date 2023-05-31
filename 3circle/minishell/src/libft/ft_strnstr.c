/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:51:51 by wonljeon          #+#    #+#             */
/*   Updated: 2022/11/30 12:56:49 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	temp;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (!len)
		return (0);
	while (big[i] && i < len)
	{
		temp = 0;
		if (little[temp] == big[i + temp])
		{
			while (little[temp] && big[i + temp])
			{
				if (little[temp] != big[i + temp] || (i + temp) >= len)
					break ;
				temp++;
			}
			if (little[temp] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
