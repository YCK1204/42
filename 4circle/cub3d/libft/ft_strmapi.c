/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:14:22 by seongmpa          #+#    #+#             */
/*   Updated: 2022/11/15 09:25:35 by seongmpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tmp;
	char			*result;

	if (!s)
		return (NULL);
	i = 0;
	tmp = (char *)s;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (0);
	while (tmp[i])
	{
		result[i] = f(i, tmp[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
