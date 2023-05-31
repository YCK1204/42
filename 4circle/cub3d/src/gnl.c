/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:08:34 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/06 18:37:31 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static char	*ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (NULL);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

static char	*ft_read(int fd, char *buf, char *backup)
{
	int		read_check;
	char	*tmp;

	read_check = 1;
	while (read_check)
	{
		read_check = read(fd, buf, BUFFER_SIZE);
		if (read_check == -1)
			return (NULL);
		else if (read_check == 0)
			break ;
		buf[read_check] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		if (!backup)
			return (ft_free(tmp));
		ft_free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*ft_make_str(char *line)
{
	int		i;
	char	*backup;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	backup = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!backup)
		return (NULL);
	if (backup[0] == '\0')
		return (ft_free(backup));
	line[i + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*line;
	static char		*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	line = ft_read(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = ft_make_str(line);
	return (line);
}
