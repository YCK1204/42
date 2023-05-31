/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:31:11 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:39:36 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/pipex_bonus.h"

void	err(t_pipex *p, char *msg)
{
	ft_putstr(msg, 2);
	all_free(p);
	exit(1);
}

void	ft_putstr(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	start_len;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start || len == 0)
		return (ft_strdup(""));
	start_len = ft_strlen(s + start);
	if (len > start_len)
		len = start_len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
