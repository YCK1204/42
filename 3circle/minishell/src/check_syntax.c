/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:10:17 by yeckim            #+#    #+#             */
/*   Updated: 2023/03/26 13:33:37 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	pass_quote1(char *line, size_t *i, char c)
{
	*i += 1;
	while (line[*i] && line[*i] != c)
		*i += 1;
	if (line[*i] == c)
		*i += 1;
}

void	pass_quote(t_pipex *pipex, char *line, size_t *i, char c)
{
	char	*s;

	*i += 1;
	while (line[*i] && line[*i] != c)
		*i += 1;
	if (line[*i] != c)
	{
		s = (char *)malloc(sizeof(char) * 2);
		s[1] = '\0';
		s[0] = c;
		occur_syntax_err(pipex, 0, 0, s);
		free(s);
	}
	else
		*i += 1;
}

void	check_semi_colon_back_slash(t_pipex *pipex, char *line)
{
	size_t	i;

	if (pipex->syntax->err)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' | line[i] == '\"')
			quote_pass_util(pipex, line, &i, &pipex->k);
		else if (line[i] == ';' || line[i] == '\\')
			break ;
		else if (line[0] == '#' || (line[i] == '#' && i && line[i - 1] == ' ') \
			|| (line[i] == '#' && (line[i - 1] == '<' \
						|| line[i - 1] == '>')))
		{
			line[i] = '\0';
			return ;
		}
		else
			i++;
	}
	if (line[i] == ';')
		occur_syntax_err(pipex, -1, -1, ";");
	else if (line[i] == '\\')
		occur_syntax_err(pipex, -1, -1, "\\");
}

void	occur_syntax_err(t_pipex *pipex, size_t i, size_t j, char *err_file)
{
	pipex->syntax->err = 1;
	pipex->syntax->err_idx[0] = i;
	pipex->syntax->err_idx[1] = j;
	pipex->syntax->err_name = ft_strdup(err_file);
	syntax_err_continue(pipex, 0);
	g_exit_code = 258;
}

void	is_space(t_pipex *p, char *line)
{
	int	f;
	int	i;

	i = -1;
	f = 0;
	while (line[++i])
		if (line[i] != ' ')
			f = 1;
	if (f == 0)
		p->syntax->err = 1;
}
