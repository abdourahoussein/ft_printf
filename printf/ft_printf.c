/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:29:59 by abhousse          #+#    #+#             */
/*   Updated: 2021/12/08 23:23:24 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convertx(unsigned int n)
{
	char	nbr[24];
	int		temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = 0;
	if (!n)
		return (ft_putchar(48));
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			nbr[i] = 48 + temp;
		else
			nbr[i] = 87 + temp;
		n = n / 16;
		i++;
	}
	nbr[i] = '\0';
	while (--i >= 0)
		j += ft_putchar (nbr[i]);
	return (j);
}

int	ft_convertp(unsigned long int ptr)
{
	char				nbr[24];
	int					temp;
	int					i;

	i = 0;
	temp = 0;
	if (!ptr)
		return (temp += write (1, "0x0", 3), temp);
	while (ptr != 0)
	{
		temp = ptr % 16;
		if (temp < 10)
			nbr[i] = 48 + temp;
		else
			nbr[i] = 87 + temp;
		ptr /=  16;
		i++;
	}
	nbr[i++] = 'x';
	nbr[i++] = '0';
	temp = 0;
	while (--i >= 0)
		temp += ft_putchar(nbr[i]);
	return (temp);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	rt;
	int		i;
	int		j;

	va_start(rt, fmt);
	i = 0;
	j = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
		{
			ft_putchar(fmt[i]);
			j++;
		}
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 'c')
				j = j + ft_putchar(va_arg(rt, int));
			else if (fmt[i] == 'd' || fmt[i] == 'i')
				j = j + ft_putnbr(va_arg(rt, int));
			else if (fmt[i] == 'u')
				j += ft_putnum(va_arg(rt, int));
			else if (fmt[i] == 's')
				j = j + ft_putstr(va_arg(rt, char *));
			else if (fmt[i] == 'x')
				j = j + ft_convertx(va_arg(rt, unsigned int));
			else if (fmt[i] == 'X')
				j += ft_convertX(va_arg(rt, unsigned int));
			else if (fmt[i] == '%')
				j += ft_putchar('%');
			else if (fmt[i] == 'p')
				j += ft_convertp(va_arg(rt, unsigned long int));
		}
		i++;
	}
	va_end(rt);
	return (j);
}
// int main ()
// {
// 	printf ("%d\n" ,printf("%p\n", 0));
// 	ft_printf ("%d\n" ,ft_printf("%p\n", 0));
// 	//printf("%x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	//ft_printf("%x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// }
