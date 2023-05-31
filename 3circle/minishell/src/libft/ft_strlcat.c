/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:56:46 by wonljeon          #+#    #+#             */
/*   Updated: 2022/11/14 20:34:37 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	idx_src;
	size_t	len_of_dest;
	size_t	len_of_src;
	size_t	count;

	idx_src = 0;
	len_of_dest = 0;
	len_of_src = 0;
	count = size;
	while (src[len_of_src])
		len_of_src++;
	if (!size)
		return (len_of_src);
	while (dest[len_of_dest] && len_of_dest < size)
		len_of_dest++;
	while (src[idx_src] && (len_of_dest + idx_src + 1) < size)
	{
		dest[len_of_dest + idx_src] = src[idx_src];
		idx_src++;
	}
	if (len_of_dest < size)
		dest[len_of_dest + idx_src] = '\0';
	return (len_of_dest + len_of_src);
}
