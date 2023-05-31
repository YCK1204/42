/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:00:18 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/24 02:40:05 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/so_long.h"

unsigned long	ft_intlen(int n)
{
	unsigned long	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	*array_init(int n, char *arr)
{
	int			i;
	long long	div;
	long long	temp;

	temp = n;
	div = 1;
	i = 0;
	if (n < 0)
	{
		arr[i++] = '-';
		temp = -temp;
	}
	while (n / div != 0)
		div *= 10;
	div /= 10;
	while (div != 0)
	{
		arr[i++] = (temp / div) + '0';
		temp %= div;
		div /= 10;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (arr == NULL)
		return (NULL);
	if (n == 0)
	{
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	array_init(n, arr);
	return (arr);
}
