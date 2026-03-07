/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 08:11:15 by iboujdad          #+#    #+#             */
/*   Updated: 2026/03/07 08:11:15 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	u_type(t_list *n, int w)
{
	char	*str;
	int		padd;
	int		z;

	str = ft_utoa(*(unsigned int *)n->content);
	z = 0;
	if ((size_t)w < ft_strlen(str))
		z += writing(n);
	else
	{
		padd = w - ft_strlen(str);
		while (padd--)
			z += write(1, "0", 1);
		z += writing(n);
	}
	free(str);
	return (z);
}

int	d_type(t_list *n, int w)
{
	char	*str;
	long	nb;
	int		z;
	int		padd;

	nb = *(int *)n->content;
	padd = 0;
	z = 0;
	if (*(int *)n->content < 0)
	{
		z += write(1, "-", 1);
		nb *= -1;
		padd--;
	}
	str = ft_utoa(nb);
	if ((size_t)w > ft_strlen(str))
	{
		padd += w - ft_strlen(str);
		while (padd--)
			z += write(1, "0", 1);
	}
	z += ft_putnbr(nb, 0, 1);
	free(str);
	return (z);
}

int	returnpoint(t_list *n)
{
	if (*(void **)n->content == NULL)
		return (4);
	else
		return (6);
}

int	x_type(t_list *n, int w)
{
	int	padd;
	int	z;

	z = 0;
	padd = 0;
	if (w < hexlen(*(int *)n->content))
	{
		z += writing(n);
		return (z);
	}
	else
		padd = w - hexlen(*(int *)n->content);
	if (n->type == 'p')
	{
		if (padd >= 6)
			padd -= returnpoint(n);
		else
			return (z);
	}
	while (padd--)
		z += write(1, "0", 1);
	z += writing(n);
	return (z);
}
