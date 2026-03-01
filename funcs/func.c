/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:36:07 by iboujdad          #+#    #+#             */
/*   Updated: 2026/02/28 00:36:07 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				i;

	i = 0;
	if (ptr == NULL)
	{
		i += write(1, "(nil)", 5);
		return (i);
	}
	p = (unsigned long)ptr;
	i += write(1, "0x", 2);
	i += ft_puthex2(p, "0123456789abcdef", 0);
	return (i);
}

int	ft_putnbr(int nb, int i)
{
	long	n;
	char	x;

	n = (long)nb;
	if (nb < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		i = ft_putnbr(n / 10, i);
	x = (n % 10) + 48;
	i += write(1, &x, 1);
	return (i);
}

int	ft_puthex(unsigned int n, char *base, int i)
{
	long	x;

	if (n >= 16)
		i = ft_puthex(n / 16, base, i);
	x = (n % 16);
	i += write(1, &base[x], 1);
	return (i);
}
