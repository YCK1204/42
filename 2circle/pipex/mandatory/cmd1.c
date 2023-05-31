/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:41:44 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:30:04 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/pipex.h"

void	err(t_pipex *p, char *msg)
{
	ft_putstr(msg, 2);
	all_free(p);
	exit(1);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	dest_len;
	unsigned int	idx;

	idx = 0;
	dest_len = ft_strlen(dest);
	while (src[idx])
		dest[dest_len++] = src[idx++];
	dest[dest_len] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	size_t			s1_len;
	size_t			s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	*str = '\0';
	ft_strcat(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	return (str);
}

void	ft_putstr(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
