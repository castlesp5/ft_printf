/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 03:08:58 by iboujdad          #+#    #+#             */
/*   Updated: 2026/03/01 19:59:09 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ihatenorm(char *s, va_list list, int *parindex)
{
	int	z;
	int	i;

	z = 0;
	i = 0;
	if (s[i] == '0')
	{
		z += padd(va_arg(list, int), &s[++i]);
		(*parindex) += 2;
	}
	else if (s[i] == 'c')
		z += ft_putchar(va_arg(list, int));
	else if (s[i] == 's')
		z += ft_putstr(va_arg(list, char *));
	else if (s[i] == 'x')
		z += ft_puthex(va_arg(list, int), "0123456789abcdef", 0);
	else if (s[i] == 'X')
		z += ft_puthex(va_arg(list, int), "0123456789ABCDEF", 0);
	else if (s[i] == 'p')
		z += ft_putptr(va_arg(list, void *));
	else if (s[i] == 'd' || *s == 'i')
		z += ft_putnbr(va_arg(list, int), 0);
	else if (s[i] == 'u')
		z += ft_putuns(va_arg(list, unsigned int), 0);
	else if (s[i] == '%')
		z += write(1, "%", 1);
	return (z);
}

int	ft_printf(char *s, ...)
{
	int		i;
	int		z;
	va_list	list;

	va_start(list, s);
	i = 0;
	z = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
			{
				z += write(1, &s[i - 1], 1);
				return (z);
			}
			z += ihatenorm(&s[i], list, &i);
		}
		else
			z += write(1, &s[i], 1);
		i++;
	}
	va_end(list);
	return (z);
}
