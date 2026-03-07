/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 23:17:53 by iboujdad          #+#    #+#             */
/*   Updated: 2026/03/07 08:06:12 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spacepadd(t_list *n, char *width)
{
	int		padd;
	char	*str;
	int		z;
	int		w;

	w = ft_atoi(width);
	z = 0;
	padd = 0;
	if (n->type == 'd' || n->type == 'i' || n->type == 'c' || n->type == 'u')
		str = chwyapadd(n);
	else if (n->type == 'x' || n->type == 'X' || n->type == 'p')
	{
		z += strin(n, w);
		return (z);
	}
	else
		str = ft_strdup(*(char **)(n)->content);
	if ((size_t)w > ft_strlen(str))
	{
		padd += w - ft_strlen(str);
		while (padd--)
			z += write(1, " ", 1);
	}
	free(str);
	return (z);
}

int	padd(t_list *n, int w)
{
	int		padd;
	char	*str;
	int		z;

	z = 0;
	padd = 0;
	if (n->type == 'u')
		return (u_type(n, w));
	else if (n->type == 'd' || n->type == 'i' || n->type == 'c')
		return (d_type(n, w));
	else if (n->type == 'x' || n->type == 'X' || n->type == 'p')
		return (x_type(n, w));
	else
		return (z);
	if ((size_t)w > ft_strlen(str))
	{
		padd += w - ft_strlen(str);
		while (padd--)
			z += write(1, "0", 1);
	}
	free(str);
	return (z);
}

int	x_tt(t_list *n, int w)
{
	int	padd;
	int	z;

	padd = w - hexlen(*(int *)n->content);
	z = 0;
	if (n->type == 'p')
	{
		if (padd >= 6)
			padd -= returnpoint(n);
		else
			return (z);
	}
	while (padd--)
		z += write(1, " ", 1);
	return (z);
}

int	paddval(int w, char *str, t_list *head)
{
	int	padd;

	if ((size_t)w > ft_strlen(str))
		padd = w - ft_strlen(str);
	else
		padd = ft_strlen(str);
	if (head->type == 'c')
		padd++;
	return (padd);
}

int	zeropadd(t_list *n, char *width)
{
	int		padd;
	char	*str;
	int		z;
	int		w;

	z = 0;
	w = ft_atoi(width);
	if (n->type == 'd' || n->type == 'i' || n->type == 'c')
		str = ft_itoa(*(int *)n->content);
	else if (n->type == 's')
		str = ft_strdup(*(char **)n->content);
	else if (n->type == 'x' || n->type == 'X' || n->type == 'p')
		return (x_tt(n, w));
	else if (n->type == 'u')
		str = ft_utoa(*(unsigned int *)n->content);
	padd = paddval(w, str, n);
	free(str);
	while (padd--)
		z += write(1, " ", 1);
	return (z);
}
