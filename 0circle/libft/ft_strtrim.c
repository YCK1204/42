/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:03:47 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/14 15:01:06 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	left = 0;
	right = ft_strlen(s1);
	while (ft_strchr(set, s1[left]) && s1[left])
		left++;
	while (ft_strchr(set, s1[right]) && left < right)
		right--;
	return (ft_substr(s1, left, right - left + 1));
}
