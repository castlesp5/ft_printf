/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 03:08:58 by iboujdad          #+#    #+#             */
/*   Updated: 2026/03/06 02:30:26 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	kaynprec(char *s, int i, t_list *head, int *z)
{
	while (s[i] != '\0' && s[i] != 'c' && s[i] != 's' && s[i] != 'd'
		&& s[i] != 'i' && s[i] != 'x' && s[i] != 'X' && s[i] != 'p'
		&& s[i] != 'u')
	{
		if (s[i] == '.')
		{
			if (head->type == 's')
			{
				*z += precs(s, i, head);
				return (1);
			}
			else if (head->type == 'd' || head->type == 'i' || head->type == 'x'
				|| head->type == 'X' || head->type == 'u')
			{
				*z += machistring(s, i, head);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ihatenorm(char *s, t_list *head, int *parindex)
{
	int	z;
	int	i;

	z = 0;
	i = 0;
	if (kaynprec(s, 0, head, &z))
	{
		while (s[i] == '-' || (s[i] >= '0' && s[i] <= '9') || s[i] == '.')
		{
			(*parindex)++;
			i++;
		}
		return (z);
	}
	z += conversions(s, head);
	while (s[i] == '-' || (s[i] >= '0' && s[i] <= '9') || s[i] == '.')
	{
		(*parindex)++;
		i++;
	}
	return (z);
}

int	checkend(char *s, t_list **head, int *parindex)
{
	t_list	*tmp;
	void	*t;
	int		z;
	int		i;

	z = 0;
	i = 0;
	if (s[i] == '%')
		z += write(1, &s[i], 1);
	else
	{
		z += ihatenorm(&s[i], *head, parindex);
		tmp = *head;
		t = (*head)->content;
		(*head) = (*head)->next;
		free(t);
		free(tmp);
	}
	return (z);
}

int	doz_3la_string(char *s, t_list **head)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				return (z);
			z += checkend(&s[i], head, &i);
		}
		else
			z += write(1, &s[i], 1);
		i++;
	}
	return (z);
}

int	ft_printf(char *s, ...)
{
	int		z;
	va_list	list;
	t_list	*head;

	va_start(list, s);
	z = 0;
	head = parse(s, list);
	z += doz_3la_string(s, &head);
	va_end(list);
	return (z);
}
