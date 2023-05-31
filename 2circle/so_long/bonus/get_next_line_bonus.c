/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:53 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/20 15:45:07 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/so_long_bonus.h"

char	*make_backup(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	temp = ft_strdup(line + i + 1);
	if (temp == NULL)
		return (NULL);
	line[i + 1] = '\0';
	return (temp);
}

char	*make_line(int fd, char *backup, char *buf, int n)
{
	char	*temp;

	while (n)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		buf[n] = '\0';
		if (n == 0)
			break ;
		if (backup == NULL)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buf);
		free(temp);
		if (backup == NULL)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	line = make_line(fd, backup, buf, 1);
	free(buf);
	if (line == NULL || *line == '\0')
	{
		free(backup);
		return (NULL);
	}
	backup = make_backup(line);
	return (line);
}
