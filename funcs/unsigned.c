/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 01:26:52 by iboujdad          #+#    #+#             */
/*   Updated: 2026/02/28 01:26:52 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_ltoa(long n)
{
	int		len;
	long	tmp;
	char	*str;

	tmp = n;
	len = (n <= 0);
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_puthex2(unsigned long n, char *base, int i)
{
	long	x;

	if (n >= 16)
		i = ft_puthex2(n / 16, base, i);
	x = (n % 16);
	i += write(1, &base[x], 1);
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char	buff[12];
	int		i;
	long	nb;

	nb = n;
	i = 11;
	buff[i--] = '\0';
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb > 0)
	{
		buff[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ft_strdup(&buff[i + 1]));
}

int	ft_putuns(unsigned int n, int i)
{
	char	x;

	if (n >= 10)
		i = ft_putuns(n / 10, i);
	x = (n % 10) + 48;
	i += write(1, &x, 1);
	return (i);
}

int	modified_spaceadd(t_list *n, char *width, int len)
{
	int		padd;
	int		z;
	int		w;
	char	*str;

	w = ft_atoi(width);
	z = 0;
	padd = 0;
	if (n->type == 'x' || n->type == 'X' || n->type == 'p')
		return (x_tmodified(n, w, len));
	else if (n->type == 'd' || n->type == 'i')
		return (d_tmodified(n, w, len));
	else if (n->type == 'u')
		return (u_tmodified(n, w, len));
	str = *(char **)n->content;
	if (w > len)
		padd += padd_value(str, w, len);
	else
		padd += padd_value(str, w, len);
	while (padd--)
		z += write(1, " ", 1);
	return (z);
}
