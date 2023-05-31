/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:23:46 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/17 12:43:22 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	size_t	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		*len = *len + 6;
		return ;
	}
	i = ft_strlen(str);
	*len = *len + (int)i;
	write(1, str, i);
}
