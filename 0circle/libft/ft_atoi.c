/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:37:07 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/14 14:25:12 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check(char *str, int *m_cnt)
{
	int	idx;
	int	p_cnt;

	p_cnt = 0;
	idx = 0;
	while ((str[idx] == ' ') || (9 <= str[idx] && str[idx] <= 13))
		idx++;
	while (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			*m_cnt = *m_cnt + 1;
		if (str[idx] == '+')
			p_cnt++;
		if (*m_cnt + p_cnt >= 2)
			return (0);
		idx++;
	}
	if (!('0' <= str[idx] && str[idx] <= '9'))
		return (0);
	return (&str[idx]);
}

int	ft_atoi(const char *str)
{
	int	m_cnt;
	int	num;

	num = 0;
	m_cnt = 0;
	str = ft_check((char *)str, &m_cnt);
	if (!str)
		return (0);
	while ('0' <= *str && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (m_cnt)
		return (-num);
	return (num);
}
