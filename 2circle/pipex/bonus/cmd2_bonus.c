/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:31:37 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:39:52 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/pipex_bonus.h"

int	str_cnt(char *s, char *c, int *ascii)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = -1;
	while (++i < 128)
		ascii[i] = 0;
	i = -1;
	while (c[++i])
		ascii[(int)c[i]]++;
	i = 0;
	while (s[i])
	{
		if (!ascii[(int)s[i]] && ++cnt)
			while (s[i] && !ascii[(int)s[i]])
				i++;
		else if (ascii[(int)s[i]])
			i++;
	}
	return (cnt);
}

int	str_init(char **ret, char *s, int *ascii, int j)
{
	int	i;
	int	k;

	i = 0;
	while (s[i])
	{
		if (!ascii[(int)s[i]])
		{
			k = i;
			while (s[k] && !ascii[(int)s[k]])
				k++;
			ret[j] = (char *)malloc(sizeof(char) * k - i + 1);
			if (ret[j] == NULL)
				return (1);
			k = 0;
			while (s[i] && !ascii[(int)s[i]])
				ret[j][k++] = s[i++];
			ret[j++][k] = '\0';
		}
		else
			i++;
	}
	return (0);
}

char	**ft_split(t_pipex *p, char *s, char *c)
{
	char	**ret;
	char	*tmp;
	int		n;
	int		ascii[128];

	tmp = ft_strdup(s);
	n = str_cnt(tmp, c, ascii);
	ret = (char **)malloc(sizeof(char *) * (n + 1));
	if (ret == NULL)
		err(p, "malloc error!\n");
	ret[n] = NULL;
	if (str_init(ret, tmp, ascii, 0))
		err(p, "malloc error!\n");
	free(tmp);
	return (ret);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{	
	unsigned long	i;
	unsigned long	j;

	i = 0;
	if (!*needle)
		return (&((char *)haystack)[0]);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && (i + j) < len && needle[j])
			j++;
		if (needle[j] == '\0')
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
