/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonljeon <wonljeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:48:47 by wonljeon          #+#    #+#             */
/*   Updated: 2022/11/14 16:19:57 by wonljeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	temp;
	char	*stemp;

	i = 0;
	temp = (char)c;
	stemp = (char *)s;
	j = -1;
	if (temp == 0)
	{
		while (stemp[i])
			i++;
		return (stemp + i);
	}
	while (stemp[i])
	{
		if (stemp[i] == temp)
			j = i;
		i++;
	}
	if (j == -1)
		return (0);
	else
		return (stemp + j);
}
