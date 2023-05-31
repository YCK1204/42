/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:11:46 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:32:39 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		fd[2];
	int		status;
	pid_t	pid;
	char	**path;
	char	**p_cmd1;
	char	**p_cmd2;
	char	*cmd1;
	char	*cmd2;
}	t_pipex;

void	err(t_pipex *p, char *msg);
void	all_free(t_pipex *p);
void	init(t_pipex *p);
void	ft_putstr(char *str, int fd);
char	**ft_split(t_pipex *p, char *s, char *c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlen(char *str);
void	ft_pipex(char **ep, t_pipex *pipex);
char	*ft_strdup(char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*awk_opt(char **s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**parsing(char *cmd, size_t i, size_t cnt, size_t j);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
#endif
