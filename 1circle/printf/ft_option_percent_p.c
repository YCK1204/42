/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_percent_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:52:57 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/18 17:31:14 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_print(unsigned long long nbr, char *base, int length, int *len)
{
	unsigned long long	*div;
	int					i;
	unsigned long		notation;

	div = (unsigned long long *)malloc(sizeof(unsigned long long) * length);
	notation = 16;
	i = 0;
	while (nbr / notation != 0)
	{
		div[i++] = nbr % notation;
		nbr /= notation;
		*len = *len + 1;
	}
	i--;
	*len = *len + 1;
	write(1, &base[nbr], 1);
	while (i >= 0)
		write(1, &base[div[i--]], 1);
	free(div);
}

void	ft_putaddress(void *n, int *len)
{
	unsigned long long	tmp;
	int					i;

	i = 1;
	tmp = (unsigned long long)n;
	while (tmp / 16 != 0)
	{
		tmp /= 16;
		i++;
	}
	write(1, "0x", 2);
	*len = *len + 2;
	hex_print((unsigned long long)n, "0123456789abcdef", i, len);
}
