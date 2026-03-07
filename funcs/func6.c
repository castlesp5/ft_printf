/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:49:48 by iboujdad          #+#    #+#             */
/*   Updated: 2026/03/07 10:49:48 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	x_tmodified(t_list *n, int w, int len)
{
	int	padd;
	int	z;

	z = 0;
	if (hexlen(*(int *)n->content) > len)
		len = hexlen(*(int *)n->content);
	if (w > len)
		padd = w - len;
	else
		return (z);
	if (n->type == 'p')
	{
		if (padd >= 6)
		{
			if (*(void **)n->content == NULL)
				padd -= 4;
			else
				padd -= 6;
		}
		else
			return (z);
	}
	while (padd--)
		z += write(1, " ", 1);
	return (z);
}

int	d_tmodified(t_list *n, int w, int len)
{
	int	padd;
	int	z;

	z = 0;
	if (ft_strlen(ft_itoa(*(int *)n->content)) > (size_t)len)
		len = ft_strlen(ft_itoa(*(int *)n->content));
	if (w > len)
	{
		padd = w - len;
		while (padd--)
			z += write(1, " ", 1);
		return (z);
	}
	else
		return (z);
}

int	u_tmodified(t_list *n, int w, int len)
{
	int		padd;
	int		z;
	char	*str;

	str = ft_utoa(*(unsigned int *)n->content);
	z = 0;
	if (ft_strlen(str) > (size_t)len)
		len = ft_strlen(str);
	if (w > len)
	{
		padd = w - len;
		while (padd--)
			z += write(1, " ", 1);
	}
	free(str);
	return (z);
}

int	padd_value(char *str, int w, int len)
{
	int	padd;

	padd = 0;
	if ((size_t)len >= ft_strlen(str))
		padd = w - ft_strlen(str);
	else
		padd += w - len;
	return (padd);
}

t_list	*parse(char *s, va_list list)
{
	int		i;
	t_list	*head;

	i = 0;
	head = NULL;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			parsing_elements(&s[i], list, &head);
		}
		i++;
	}
	return (head);
}
