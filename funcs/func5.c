/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 08:15:07 by iboujdad          #+#    #+#             */
/*   Updated: 2026/03/07 08:15:07 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	hexlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	precision(t_list *n, char *width)
{
	int	z;
	int	w;

	w = ft_atoi(width);
	z = 0;
	if (n->type == 's')
	{
		if ((size_t)w > ft_strlen(*(char **)n->content))
			z += write(1, *(char **)n->content,
					ft_strlen(*(char **)n->content));
		else
			z += write(1, *(char **)n->content, w);
	}
	return (z);
}

int	strin(t_list *n, int w)
{
	int	padd;
	int	z;

	padd = w - hexlen(*(int *)n->content);
	z = 0;
	if (n->type == 'p')
	{
		if (padd >= 6)
		{
			if (*(void **)n->content == NULL)
				padd = w - 5;
			else
				padd = w - 14;
		}
		else
			return (z);
	}
	while (padd--)
		z += write(1, " ", 1);
	return (z);
}

char	*chwyapadd(t_list *n)
{
	char	*str;

	if (n->type == 'd' || n->type == 'i')
		str = ft_itoa(*(int *)(n)->content);
	else if (n->type == 'c')
		str = (char *)n->content;
	else if (n->type == 'u')
		str = ft_utoa(*(unsigned int *)n->content);
	return (str);
}

int	returnzmachistring(t_list *head, char *s, int i, int z)
{
	z += padd(head, ft_atoi(&s[i + 1]));
	z += modified_spaceadd(head, &s[1], ft_atoi(&s[i + 1]));
	return (z);
}
