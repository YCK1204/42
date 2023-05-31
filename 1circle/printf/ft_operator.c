/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:57:29 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/17 15:06:08 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_operator(char c, va_list ap, int *len)
{
	if (c == 'c')
		ft_putchar((char)va_arg(ap, char *), len);
	else if (c == 's')
		ft_putstr((char *)va_arg(ap, char *), len);
	else if (c == 'p')
		ft_putaddress((void *)va_arg(ap, char *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr((int)va_arg(ap, int), len);
	else if (c == 'u')
		ft_putunsigned((unsigned int)va_arg(ap, unsigned int), len);
	else if (c == 'x')
		ft_putlowhex((unsigned int)va_arg(ap, int), len);
	else if (c == 'X')
		ft_putuphex((unsigned int)va_arg(ap, int), len);
	else if (c == '%')
	{
		write(1, "%", 1);
		*len = *len + 1;
	}
}
