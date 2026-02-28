/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 03:08:58 by iboujdad          #+#    #+#             */
/*   Updated: 2026/02/28 01:51:49 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ihatenorm(char *s, va_list list)
{
	int	z;

	z = 0;
	if (*s == 'c')
		z += ft_putchar(va_arg(list, int));
	else if (*s == 's')
		z += ft_putstr(va_arg(list, char *));
	else if (*s == 'x')
		z += ft_puthex(va_arg(list, int), "0123456789abcdef", 0);
	else if (*s == 'X')
		z += ft_puthex(va_arg(list, int), "0123456789ABCDEF", 0);
	else if (*s == 'p')
		z += ft_putptr(va_arg(list, void *));
	else if (*s == 'd' || *s == 'i')
		z += ft_putnbr(va_arg(list, int), 0);
	else if (*s == 'u')
		z += ft_putuns(va_arg(list, unsigned int), 0);
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
			z += ihatenorm(&s[i], list);
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(list);
	return (z);
}

int	main(void)
{
	int	x;
	int	z;
	int	d;

	x = 42;
	d = ft_printf("%p", &x);
	printf("\n%d", d);
}
