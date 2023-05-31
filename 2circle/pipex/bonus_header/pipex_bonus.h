/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 01:35:57 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:38:21 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_pipex
{
	int		infile;
	int		status;
	int		outfile;
	int		hd;
	int		pid;
	int		cmd_count;
	int		i;
	int		*fds;
	char	**path;
	char	**cmds;
	char	***p_cmds;
}	t_pipex;

void	err(t_pipex *p, char *msg);
void	ft_putstr(char *str, int fd);
char	**ft_split(t_pipex *p, char *s, char *c);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	child(t_pipex *pipex, int ac, char **ep);
void	get_cmds(t_pipex *pipex, int ac);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
void	get_outfile(t_pipex *pipex, int ac, char **av);
void	get_infile(t_pipex *pipex, char **av, int ac);
void	ft_pipex(t_pipex *pipex, char **ep);
void	create_pipe(t_pipex *pipex);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**parsing(char *cmd, size_t i, size_t cnt, size_t j);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
void	all_free(t_pipex *p);
void	init(t_pipex *p);
#endif
