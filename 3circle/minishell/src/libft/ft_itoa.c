/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:42:53 by wonljeon          #+#    #+#             */
/*   Updated: 2022/11/14 14:00:08 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

void	fill_int(char *ret, size_t len, size_t i, int n)
{
	while (len-- > i)
	{
		if (n < 0)
		{
			ret[len] = '0' + n % 10 * (-1);
			n = n / 10;
		}
		else
		{
			ret[len] = '0' + n % 10;
			n = n / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = get_len(n);
	ret = malloc(sizeof(char) * (len + 1));
	if (!(ret))
		return (0);
	ret[len] = '\0';
	i = 0;
	if (n < 0)
	{
		ret[0] = '-';
		i = 1;
	}
	fill_int(ret, len, i, n);
	return (ret);
}
