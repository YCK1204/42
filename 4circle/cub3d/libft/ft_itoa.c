/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:02:46 by seongmpa          #+#    #+#             */
/*   Updated: 2022/11/15 16:29:55 by seongmpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_size(long n)
{
	unsigned int	size;

	size = 1;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n / 10 != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long			tmp;
	unsigned int	size;
	char			*result;
	char			*base;

	tmp = n;
	base = "0123456789";
	size = check_size(tmp);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	result[size] = '\0';
	if (tmp < 0)
	{
		tmp *= -1;
		result[0] = '-';
	}
	while (1)
	{
		result[--size] = base[tmp % 10];
		if ((tmp / 10) == 0)
			break ;
		tmp /= 10;
	}
	return (result);
}
