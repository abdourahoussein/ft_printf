/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:33:34 by abhousse          #+#    #+#             */
/*   Updated: 2021/12/09 23:12:45 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int		ft_convertp(unsigned long int ptr);
int		ft_convertx(unsigned int n);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnum(unsigned int n);
int		ft_putstr(char *s);
int		ft_convertxx(unsigned int n);
void	ft_printf2(const char *fmt, va_list rt, int *j, int *i);

#endif
