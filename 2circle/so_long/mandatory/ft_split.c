/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:11:01 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/19 20:50:25 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/so_long.h"

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

unsigned long	ft_len(const char *str, char c)
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

char	**ft_split(const char *s, char c)
{
	char			*temp;
	char			**str;
	unsigned long	cnt;
	unsigned long	i;

	i = 0;
	temp = ft_strdup(s);
	if (temp == NULL)
		return (NULL);
	cnt = ft_count(temp, c);
	str = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (str == NULL)
		return (NULL);
	str[cnt] = 0;
	if (str_init(str, c, cnt, temp))
	{
		while (str[i])
			free(str[i++]);
		free(str);
		return (NULL);
	}
	free(temp);
	return (str);
}
