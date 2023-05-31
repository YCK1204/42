/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:14:58 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/17 20:32:52 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned long	i;

	i = 0;
	while (str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
		return (&((char *)str)[i]);
	return (NULL);
}
