/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:25:17 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/17 13:54:15 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	len_init(int n, int *len, long long *div, long long *temp)
{
	*div = 1;
	if (*temp == 0)
	{
		write(1, "0", 1);
		*len = *len + 1;
	}
	if (*temp < 0)
	{
		write(1, "-", 1);
		*temp = -*temp;
		*len = *len + 1;
	}
	while (n / *div != 0)
	{
		*div *= 10;
		*len = *len + 1;
	}
	*div /= 10;
}

void	ft_putnbr(int n, int *len)
{
	long long	div;
	long long	temp;
	char		tmp;

	temp = n;
	len_init(n, len, &div, &temp);
	while (div != 0)
	{
		tmp = temp / div + '0';
		write(1, &tmp, 1);
		temp %= div;
		div /= 10;
	}
}
