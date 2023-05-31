/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:10:44 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/14 15:47:24 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_idx;

	dest_len = 0;
	src_idx = 0;
	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	while (src[src_idx] && src_idx + dest_len + 1 < size)
	{
		dest[dest_len + src_idx] = src[src_idx];
		src_idx++;
	}
	if (dest_len < size)
		dest[dest_len + src_idx] = '\0';
	return (dest_len + ft_strlen(src));
}
