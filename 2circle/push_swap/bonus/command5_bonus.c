/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command5_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:16:23 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/13 13:47:35 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/push_swap_bonus.h"

unsigned long	ft_count(char *str, char c)
{
	unsigned long	cnt;
	unsigned long	i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != '\0' && str[i] != c)
		{
			cnt++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
		{
			while (str[i] != '\0' && str[i] == c)
				i++;
		}
	}
	return (cnt);
}

unsigned long	ft_len(char *str, char c)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

int	str_init(char **str, char c, unsigned long cnt, char *src)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	k;

	k = 0;
	i = 0;
	while (i < cnt)
	{
		if (src[k] != '\0' && src[k] != c)
		{
			j = 0;
			str[i] = (char *)malloc(sizeof(char) * (ft_len(&src[k], c) + 1));
			if (str[i] == NULL)
				return (1);
			while (src[k] != '\0' && src[k] != c)
				str[i][j++] = src[k++];
			str[i++][j] = '\0';
		}
		else
			while (src[k] != '\0' && src[k] == c)
				k++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned long	cnt;
	unsigned long	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	cnt = ft_count((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (str == NULL)
		return (NULL);
	if (str_init(str, c, cnt, (char *)s))
	{
		while (str[i])
			free(str[i++]);
		free(str);
		return (NULL);
	}
	str[cnt] = NULL;
	return (str);
}
