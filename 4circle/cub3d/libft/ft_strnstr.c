/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:39:33 by seongmpa          #+#    #+#             */
/*   Updated: 2022/11/14 13:02:41 by seongmpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	if (!haystack && len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		tmp = 0;
		if (haystack[tmp + i] == needle[tmp])
		{
			while (haystack[tmp + i] && needle[tmp])
			{
				if (needle[tmp] != haystack[tmp + i] || (tmp + i) >= len)
					break ;
				tmp++;
			}
			if (!needle[tmp])
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (0);
}
