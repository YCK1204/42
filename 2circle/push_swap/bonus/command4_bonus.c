/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command4_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:16:17 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/13 21:02:08 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/push_swap_bonus.h"

void	check_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			j = 1;
		i++;
	}
	if (j == 0)
		err();
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			i;
	int			m_cnt;

	check_space((char *)str);
	i = 0;
	m_cnt = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			m_cnt++;
	}
	if (!('0' <= str[i] && str[i] <= '9'))
		err();
	while ('0' <= str[i] && str[i] <= '9')
	{
		num *= 10;
		num += str[i++] - '0';
	}
	if (m_cnt)
		num = -num;
	if (num < -2147483648 || num > 2147483647)
		err();
	return ((int)num);
}
