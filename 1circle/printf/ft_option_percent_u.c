/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_percent_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:52:11 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/17 13:34:04 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int n, int *len)
{
	unsigned long long	div;
	unsigned long long	temp;
	char				tmp;

	temp = n;
	div = 1;
	if (n == 0)
	{
		write(1, "0", 1);
		*len = *len + 1;
	}
	while (n / div != 0)
		div *= 10;
	div /= 10;
	while (div != 0)
	{
		tmp = temp / div + '0';
		write(1, &tmp, 1);
		temp %= div;
		div /= 10;
		*len = *len + 1;
	}
}
