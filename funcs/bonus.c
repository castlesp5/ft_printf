/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 23:17:53 by iboujdad          #+#    #+#             */
/*   Updated: 2026/02/28 23:17:53 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padd(int n, char *width)
{
	int		padd;
	char	*str;
	int		z;
	int		w;

	w = atoi(width);
	z = 0;
	padd = 0;
	if (n < 0)
	{
		z += write(1, "-", 1);
		n = -n;
		padd = -1;
	}
	str = ft_itoa(n);
	if ((size_t)w > ft_strlen(str))
	{
		padd += w - ft_strlen(str);
		while (padd--)
			z += write(1, "0", 1);
		z += write(1, str, ft_strlen(str));
	}
	else
		z += write(1, str, ft_strlen(str));
	return (z);
}
