/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 01:31:08 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 01:33:23 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/pipex.h"

void	quote_pass(char *cmd, size_t *i, int c)
{
	*i += 1;
	while (cmd[*i] && cmd[*i] != c)
		*i += 1;
	if (cmd[*i])
		*i += 1;
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	i = 0;
	while ((i < len) && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	*parsing_util(char *cmd, char *tmp, char *temp, size_t *i)
{
	size_t	start;
	size_t	f;
	char	*str;

	str = ft_strdup("");
	while (cmd[*i] && cmd[*i] != ' ')
	{
		f = 0;
		start = *i;
		if ((cmd[*i] == '\'' || cmd[*i] == '\"') && ++f && ++start)
			quote_pass(cmd, i, cmd[*i]);
		else
			while (cmd[*i] && cmd[*i] != ' ' && \
					cmd[*i] != '\'' && cmd[*i] != '\"')
				*i += 1;
		tmp = ft_substr(cmd, start, *i - start - f);
		temp = ft_strdup(str);
		free(str);
		str = ft_strjoin(temp, tmp);
		free(temp);
		free(tmp);
	}
	return (str);
}

size_t	count_size(char *cmd, size_t i)
{
	size_t	cnt;

	cnt = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
			i++;
		else
		{
			cnt++;
			while (cmd[i] && cmd[i] != ' ')
			{
				if (cmd[i] == '\'' || cmd[i] == '\"')
					quote_pass(cmd, &i, cmd[i]);
				else
					i++;
			}
		}
	}
	return (cnt);
}

char	**parsing(char *cmd, size_t i, size_t cnt, size_t j)
{
	char	**cmds;

	cnt = count_size(cmd, 0);
	cmds = (char **)malloc(sizeof(char *) * (cnt + 1));
	cmds[cnt] = NULL;
	while (cmd[i])
	{
		cmds[j++] = parsing_util(cmd, "", "", &i);
		if (cmd[i])
			i++;
	}
	return (cmds);
}
