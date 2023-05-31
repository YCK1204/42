/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:19:59 by seongmpa          #+#    #+#             */
/*   Updated: 2022/11/15 16:14:57 by seongmpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf;
	unsigned char	*tmp;

	tmp = dst;
	buf = (unsigned char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (dst <= src)
	{
		while (len--)
			*tmp++ = *buf++;
	}
	else
	{
		tmp += len;
		buf += len;
		while (len--)
			*--tmp = *--buf;
	}
	return (dst);
}
