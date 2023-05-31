/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:14:16 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:35:38 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory_header/pipex.h"

char	*ft_strdup(char *str)
{
	char	*arr;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		arr[i] = str[i];
		i++;
	}
	return (arr);
}

char	**path(t_pipex *p, char **ep)
{
	char	*tmp;

	while (ep && !ft_strnstr(*ep, "PATH", 4))
		ep++;
	if (*ep == NULL)
		err(p, "PATH MISSING!\n");
	tmp = *ep + 5;
	return (ft_split(p, tmp, ":"));
}

char	*cmd_path(char *cmd, t_pipex *pipex)
{
	size_t	i;
	char	*temp;
	char	*root;

	i = 0;
	if (!access(cmd, X_OK))
		return (cmd);
	temp = ft_strjoin("/", cmd);
	root = ft_strjoin(pipex->path[i], temp);
	while (pipex->path[i] && access(root, X_OK))
	{
		free(root);
		i++;
		root = ft_strjoin(pipex->path[i], temp);
	}
	free(temp);
	if (pipex->path[i] == NULL)
		return (NULL);
	return (root);
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

int	main(int ac, char **av, char **ep)
{
	t_pipex	pipex;

	init(&pipex);
	if (ac != 5)
		err(&pipex, "argument error!");
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile == -1)
		err(&pipex, "infile error!");
	pipex.outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	pipex.path = path(&pipex, ep);
	pipex.p_cmd1 = parsing(av[2], 0, 0, 0);
	pipex.p_cmd2 = parsing(av[3], 0, 0, 0);
	if (pipex.p_cmd1 == NULL || pipex.p_cmd2 == NULL)
		err(&pipex, "cmd error!");
	pipex.cmd1 = cmd_path(pipex.p_cmd1[0], &pipex);
	pipex.cmd2 = cmd_path(pipex.p_cmd2[0], &pipex);
	if (pipex.cmd1 == NULL || pipex.cmd2 == NULL)
		return (1);
	ft_pipex(ep, &pipex);
	all_free(&pipex);
	return (WEXITSTATUS(pipex.status));
}
