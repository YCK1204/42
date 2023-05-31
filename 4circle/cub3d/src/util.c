/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmpa <seongmpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:47:57 by seongmpa          #+#    #+#             */
/*   Updated: 2023/04/23 15:10:13 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && s1 && s2)
		if (*s1++ != *s2++)
			return (*(unsigned char *)(--s1) - *(unsigned char *)(--s2));
	return (*(unsigned char *)(s1) - *(unsigned char *)(s2));
}

int	print_error(char *str)
{
	printf("%s\n", str);
	return (1);
}

void	print_double_size_array(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("%s\n", str[i]);
}

int	check_argv(char *str)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = NULL;
	while (str[++i])
		;
	while (i > -1 && str[--i] != '.')
		;
	if (str[i] == '.')
	{
		tmp = ft_substr(str, i + 1, ft_strlen(str));
		if (tmp == NULL)
			return (1);
		if (ft_strcmp(tmp, "cub") != 0)
		{
			free(tmp);
			return (1);
		}
	}
	free(tmp);
	return (0);
}

int	strlen_double_size_arr(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
