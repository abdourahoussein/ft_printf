/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:33:58 by abhousse          #+#    #+#             */
/*   Updated: 2021/12/08 16:34:00 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_putchar(char c)
{
	int i;

	 write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	unsigned int	nbr;
	int i;
	i = 0;

	if (n < 0)
	{
		i = i + ft_putchar('-');
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
		i = i + ft_putnbr(nbr / 10);
	i = i + ft_putchar(nbr % 10 + 48);
	return (i);
}

int	ft_putnum(unsigned int n)
{
	unsigned int	nbr;
	int i;

	i = 0;
	if (n >= 0)
		nbr = n;
	if (nbr >= 10)
		i = i + ft_putnum(nbr / 10);
	i += ft_putchar(nbr % 10 + 48);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;
	int j;

	i = 0;
	j = 0;
    if (!s)
        j = write (1, "(null)", 6);
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i++]);
			j++;
		}
	}
	return(j);
}


int  ft_convertX(unsigned int n)
{
    char nbr[24];
    int temp;
    int i;
    int j;

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
            nbr[i] = 55 + temp;
        n = n / 16;
        i++;
    }
    nbr[i] = '\0';
	while (--i >= 0)
		j += ft_putchar(nbr[i]);
	return(j);
}