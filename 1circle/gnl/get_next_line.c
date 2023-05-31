/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:05:53 by yeckim            #+#    #+#             */
/*   Updated: 2022/12/12 17:34:55 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (n == 0)
			break ;
		buf[n] = '\0';
		if (backup == NULL)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
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
	buf = NULL;
	if (line == NULL || *line == '\0')
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = make_backup(line);
	return (line);
}
/*
#include <sys/stat.h>          // mode_t
#include <fcntl.h>
#include <unistd.h>            // 윈도우에선 <io.h>헤더
#include <stdlib.h>
int	main()
{
	int fd;
	char	*s;
	fd = open("aa.txt",O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("%s", s);
		s = get_next_line(fd);
	}
	close(fd);
}*/
