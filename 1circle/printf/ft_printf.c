/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:42:05 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/17 15:08:31 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arr_init(char *ascii)
{
	int	i;

	i = 0;
	while (i < 256)
		ascii[i++] = 0;
	ascii[(int) 'c']++;
	ascii[(int) 's']++;
	ascii[(int) 'p']++;
	ascii[(int) 'd']++;
	ascii[(int) 'i']++;
	ascii[(int) 'u']++;
	ascii[(int) 'x']++;
	ascii[(int) 'X']++;
	ascii[(int) '%']++;
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				len;
	unsigned long	i;
	char			ascii[256];

	i = 0;
	len = 0;
	va_start(ap, str);
	arr_init(ascii);
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (!ascii[(int)str[i + 1]])
				i++;
			if (ascii[(int)str[i + 1]])
				ft_operator((char)str[i + 1], ap, &len);
			i += 2;
		}
		else
			ft_putchar((char)str[i++], &len);
	}
	va_end(ap);
	return (len);
}
/*
#include <stdio.h>
int	main()
{
	int	i;
	printf("%d\n", ft_printf(" %p ", &i));
	printf("%d\n", printf(" %p ", &i));
}*/
