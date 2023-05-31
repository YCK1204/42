/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeckim <yeckim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:02:44 by yeckim            #+#    #+#             */
/*   Updated: 2022/11/17 15:07:06 by yeckim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(char n, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putunsigned(unsigned int n, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putlowhex(unsigned int n, int *len);
void	ft_putuphex(unsigned int n, int *len);
void	ft_putaddress(void *n, int *len);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
void	ft_operator(char c, va_list ap, int *len);
int		ft_printf(const char *str, ...);
#endif
