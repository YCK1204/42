/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:31 by wonljeon          #+#    #+#             */
/*   Updated: 2023/03/27 15:21:27 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_isalpha_export(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (2);
	else if (c == '_')
		return (3);
	else
		return (0);
}

void	print_error_export(char **str, int pipe_cnt)
{
	printf("export: `%s': not a valid identifier\n", *str);
	check_pipe_cnt(pipe_cnt);
	free(*str);
	*str = NULL;
}

char	*find_special_middle_for_export(char *str, int i[])
{
	int		j;
	char	*equal_cmd;

	if (!ft_isalpha_export(str[0]))
	{
		printf("export: `%s': not a valid identifier\n", str);
		check_pipe_cnt(i[2]);
		free(str);
		return (NULL);
	}
	if (ft_strchr(str, '=') == 0)
	{
		find_special_middle_for_export_2(&str, i);
		if (str == NULL)
			return (NULL);
	}
	else if (ft_strchr(str, '=') != 0)
	{
		j = ft_strchr_num(str, '=');
		equal_cmd = ft_substr(str, 0, j);
		find_special_middle_for_export_3(&equal_cmd, i);
		if (equal_cmd == NULL)
			print_error_export(&str, i[2]);
	}
	return (str);
}

void	twenty_five(t_lst **head, t_lst **tail, char *cmdline_i, int i[])
{
	char	*tmp;
	char	*ret;

	tmp = ft_strdup(cmdline_i);
	ret = find_special_middle_for_export(tmp, i);
	if (!ret)
		return ;
	i[1] = double_check(head, 0, tail, ret);
	if (i[1] == 1)
	{
		free(ret);
		return ;
	}
	lst_insert_orm(head, tail, ret);
	free(ret);
}

void	ft_export(t_lst **head, t_lst **tail, char **cmdline, int pipe_cnt)
{
	int		i[3];
	int		j;

	i[0] = 0;
	i[2] = pipe_cnt;
	j = 1;
	while (cmdline[++i[0]])
		if (ft_strcmp(cmdline[i[0]], "\0") != 0)
			j++;
	if (j == 1)
		print_export_orm(head, tail);
	i[0] = 0;
	while (cmdline[++i[0]])
	{
		if (cmdline[i[0]][0] == ' ')
		{
			printf("export: `%s': not a valid identifier\n", cmdline[i[0]]);
			check_pipe_cnt(pipe_cnt);
			return ;
		}
	}
	g_exit_code = 0;
	i[0] = 0;
	while (cmdline[++i[0]] != NULL)
		twenty_five(head, tail, cmdline[i[0]], i);
}
