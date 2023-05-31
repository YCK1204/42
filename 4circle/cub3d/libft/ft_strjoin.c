/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:19:07 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/10 17:23:50 by seongmpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		s1[i + n] = s2[i];
		i++;
	}
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	size_t			len1;
	size_t			len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (0);
	result = ft_strncat(result, (char *)s1, 0);
	result = ft_strncat(result, (char *)s2, len1);
	result[len1 + len2] = 0;
	return (result);
}
