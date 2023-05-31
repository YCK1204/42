/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:26:55 by wonljeon          #+#    #+#             */
/*   Updated: 2022/11/14 16:36:51 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	number;
	char	num[15];

	i = 0;
	number = (long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		number = (long)n * -1;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	while (number)
	{
		num[i++] = (number % 10) + '0';
		number /= 10;
	}
	while (--i >= 0)
		write(fd, &num[i], 1);
}
