/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:12:35 by iboujdad          #+#    #+#             */
/*   Updated: 2026/03/07 10:36:59 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	writing(t_list *head)
{
	int	z;

	z = 0;
	if (head->type == 'c')
		z += ft_putchar(*(char *)(head)->content);
	else if (head->type == 's')
		z += ft_putstr(*(char **)(head)->content);
	else if (head->type == 'x')
		z += ft_puthex(*(int *)(head)->content, "0123456789abcdef", 0);
	else if (head->type == 'X')
		z += ft_puthex(*(int *)(head)->content, "0123456789ABCDEF", 0);
	else if (head->type == 'p')
		z += ft_putptr(*(void **)(head)->content);
	else if (head->type == 'd' || head->type == 'i')
		z += ft_putnbr(*(int *)(head)->content, 0, 0);
	else if (head->type == 'u')
		z += ft_putuns(*(unsigned int *)(head)->content, 0);
	else if (head->type == '%')
		z += write(1, "%", 1);
	return (z);
}

int	conversions(char *s, t_list *head)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (s[i] == '0')
	{
		if (s[i + 1] == '-')
			z += zeropadd(head, &s[i + 2]);
		else
		{
			z += padd(head, ft_atoi(&s[++i]));
			return (z);
		}
	}
	else if ((s[i] - '0') >= 1 && (s[i] - '0') <= 9)
		z += spacepadd(head, &s[i]);
	else if (s[i] == '-')
	{
		z += writing(head);
		z += zeropadd(head, &s[++i]);
		return (z);
	}
	z += writing(head);
	return (z);
}

int	precs(char *s, int i, t_list *head)
{
	int	z;

	z = 0;
	if (s[0] != '.')
	{
		if (s[0] == '-')
		{
			z += writing(head);
			z += zeropadd(head, &s[1]);
			return (z);
		}
		z += modified_spaceadd(head, &s[0], ft_atoi(&s[++i]));
	}
	if (s[i] == '.')
		i++;
	z += precision(head, &s[i]);
	return (z);
}

int	precint(char *s, int i, t_list *head)
{
	int	z;

	z = 0;
	z += modified_spaceadd(head, &s[0], 1 + ft_atoi(&s[++i]));
	z += padd(head, 1 + ft_atoi(&s[i]));
	return (z);
}

int	machistring(char *s, int i, t_list *head)
{
	int	z;

	z = 0;
	if (s[0] != '.')
	{
		if ((head->type == 'd' || head->type == 'i')
			&& *(int *)head->content < 0)
		{
			z += precint(s, i, head);
			return (z);
		}
		else
		{
			if (s[0] == '-')
				return (returnzmachistring(head, s, i, z));
			z += modified_spaceadd(head, &s[0], ft_atoi(&s[++i]));
		}
	}
	if (s[i] == '.')
		i++;
	z += padd(head, ft_atoi(&s[i]));
	return (z);
}
