/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:28:29 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 12:54:08 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/pipex_bonus.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] == str2[i])
	{
		if (!str1[i])
			return (0);
		i++;
	}
	return (str1[i] - str2[i]);
}

void	here_doc(t_pipex *pipex, char **av, int fd)
{
	char	*line;
	char	*limit;

	limit = ft_strjoin(av[2], "\n");
	line = get_next_line(0);
	while (ft_strcmp(limit, line))
	{
		ft_putstr("heredoc> ", 1);
		ft_putstr(line, fd);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	free(limit);
	close(fd);
	pipex->infile = open("here_doc.txt", O_RDONLY);
	if (pipex->infile == -1)
	{
		unlink("here_doc.txt");
		err(pipex, "infile error!");
	}
}

void	get_infile(t_pipex *pipex, char **av, int ac)
{
	int	fd;

	pipex->hd = 0;
	if (ft_strnstr(av[1], "here_doc", 8))
	{
		if (ac != 6)
			err(pipex, "argument error!");
		pipex->hd++;
		fd = open("here_doc.txt", O_RDWR | O_CREAT, 0644);
		if (fd == -1)
			err(pipex, "open error!");
		write(1, "heredoc> ", 9);
		here_doc(pipex, av, fd);
	}
	else
		pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile == -1)
		err(pipex, "infile error!");
}

void	get_outfile(t_pipex *pipex, int ac, char **av)
{
	if (pipex->hd)
		pipex->outfile = open(av[ac - 1], O_APPEND | O_CREAT | O_RDWR, 0644);
	else
		pipex->outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		err(pipex, "outfile error!");
}
