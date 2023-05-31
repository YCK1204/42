/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:02:49 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/11 15:42:51 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	div;
	long long	num;
	char		temp;

	if (n == 0)
		write(fd, "0", 1);
	num = n;
	div = 1;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	while (num / div != 0)
		div *= 10;
	div /= 10;
	while (div != 0)
	{
		temp = num / div + '0';
		write(fd, &temp, 1);
		num %= div;
		div /= 10;
	}
}
