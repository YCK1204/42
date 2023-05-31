/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:09:26 by seongmpa          #+#    #+#             */
/*   Updated: 2022/11/14 07:46:58 by seongmpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	if (dst == 0 && src == 0)
		return ((void *)0);
	while (i < n)
	{
		(((unsigned char *)dst)[i] = ((unsigned char *)src)[i]);
		i++;
	}
	return (dst);
}
