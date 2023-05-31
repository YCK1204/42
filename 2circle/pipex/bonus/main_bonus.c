/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:39:30 by yeckim            #+#    #+#             */
/*   Updated: 2023/05/22 02:47:57 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_header/pipex_bonus.h"

char	**path(t_pipex *p, char **ep)
{
	while (ep && !ft_strnstr(*ep, "PATH", 4))
		ep++;
	if (*ep == NULL)
		err(p, "PATH MISSING!");
	return (ft_split(p, *ep + 5, ":"));
}

void	cmd_split(t_pipex *pipex, int ac, char **av)
{
	int	i;

	pipex->p_cmds = (char ***)malloc(sizeof(char **) \
		* (ac - 3 - pipex->hd + 1));
	if (pipex->p_cmds == NULL)
		err(pipex, "malloc error!");
	pipex->p_cmds[ac - 3 - pipex->hd] = NULL;
	i = -1;
	while (++i < ac - 3 - pipex->hd)
	{
		pipex->p_cmds[i] = parsing(av[i + 2 + pipex->hd], 0, 0, 0);
		if (pipex->p_cmds[i] == NULL)
			err(pipex, "split error!");
	}
}

char	*cmd_path(char *cmd, t_pipex *pipex)
{
	size_t	i;
	char	*temp;
	char	*root;

	i = 0;
	if (!cmd)
		err(pipex, "cmd error");
	temp = ft_strjoin("/", cmd);
	root = ft_strjoin(pipex->path[i], temp);
	while (pipex->path[i] && access(root, X_OK))
	{
		free(root);
		root = ft_strjoin(pipex->path[i], temp);
		i++;
	}
	free(temp);
	if (pipex->path[i] == NULL)
		return (NULL);
	return (root);
}

void	get_cmd(t_pipex *pipex, int ac)
{
	int	i;

	pipex->cmds = (char **)malloc(sizeof(char *) * (ac - 3 - pipex->hd + 1));
	if (pipex->cmds == NULL)
		err(pipex, "malloc error!");
	i = -1;
	while (++i < ac - 3 - pipex->hd)
	{
		pipex->cmds[i] = cmd_path(pipex->p_cmds[i][0], pipex);
		if (pipex->cmds[i] == NULL)
			perror("cmd error!");
	}
	pipex->cmds[i] = NULL;
}

int	main(int ac, char **av, char **ep)
{
	t_pipex	pipex;

	init(&pipex);
	if (ac < 5)
		err(&pipex, "argument error!");
	get_infile(&pipex, av, ac);
	get_outfile(&pipex, ac, av);
	pipex.cmd_count = ac - 3 - pipex.hd;
	pipex.path = path(&pipex, ep);
	cmd_split(&pipex, ac, av);
	get_cmd(&pipex, ac);
	create_pipe(&pipex);
	ft_pipex(&pipex, ep);
	unlink("here_doc.txt");
	all_free(&pipex);
	return (WEXITSTATUS(pipex.status));
}
