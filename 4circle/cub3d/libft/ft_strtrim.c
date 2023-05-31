/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:28:13 by seongmpa          #+#    #+#             */
/*   Updated: 2022/11/14 16:27:57 by seongmpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	front;
	size_t	back;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front = 0;
	back = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (back > 0 && s1[back - 1] && ft_strchr(set, s1[back - 1]))
		back--;
	if (front >= back)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (back - front + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *)s1 + front, back - front + 1);
	return (result);
}
