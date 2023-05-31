/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:37:42 by wonljeon          #+#    #+#             */
/*   Updated: 2022/11/14 16:22:09 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	temp;
	char	*stemp;

	i = 0;
	temp = (char)c;
	stemp = (char *)str;
	while (stemp[i] != temp)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (&stemp[i]);
}
