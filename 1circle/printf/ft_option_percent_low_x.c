/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_percent_low_x.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:32:06 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/17 15:10:40 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_lowhex(int length, unsigned int nbr, char *base, int *len)
{
	char			*result;
	int				i;

	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return ;
	i = 0;
	while (nbr / 16 != 0)
	{
		result[i++] = nbr % 16;
		nbr /= 16;
		*len = *len + 1;
	}
	result[i--] = '\0';
	write(1, &base[nbr], 1);
	*len = *len + 1;
	while (i >= 0)
		write(1, &base[(int)result[i--]], 1);
	free(result);
}

void	ft_putlowhex(unsigned int nbr, int *len)
{
	int					i;
	unsigned long long	temp;

	temp = nbr;
	i = 1;
	while (temp / 16 != 0)
	{
		i++;
		temp /= 16;
	}
	print_lowhex(i, nbr, "0123456789abcdef", len);
}
