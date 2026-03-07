/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:50:33 by iboujdad          #+#    #+#             */
/*   Updated: 2026/03/05 22:50:33 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	parse_int(va_list list, t_list ***head, char *s)
{
	void	*val;
	t_list	*node;
	int		i;

	i = 0;
	val = malloc(sizeof(int));
	*(int *)val = va_arg(list, int);
	node = ft_lstnew(val);
	while (s[i] != 'c' && s[i] != 'd' && s[i] != 'i' && s[i] != 'x'
		&& s[i] != 'X')
		i++;
	if (s[i] == 'c')
		node->type = 'c';
	else if (s[i] == 'd' || s[i] == 'i')
		node->type = 'd';
	else if (s[i] == 'x' || s[i] == 'X')
	{
		if (s[i] == 'x')
			node->type = 'x';
		else if (s[i] == 'X')
			node->type = 'X';
	}
	ft_lstadd_back(*head, node);
}

void	parse_string(va_list list, t_list ***head)
{
	void	*val;
	t_list	*node;

	val = malloc(sizeof(char *));
	*(char **)val = va_arg(list, char *);
	node = ft_lstnew(val);
	node->type = 's';
	ft_lstadd_back(*head, node);
}

void	parse_unsigned(va_list list, t_list ***head)
{
	void	*val;
	t_list	*node;

	val = malloc(sizeof(unsigned int));
	*(unsigned int *)val = va_arg(list, unsigned int);
	node = ft_lstnew(val);
	node->type = 'u';
	ft_lstadd_back(*head, node);
}

void	parsing_elements(char *s, va_list list, t_list **head)
{
	int		i;
	void	*val;
	t_list	*node;

	i = 0;
	while (s[i] == '-' || (s[i] >= '0' && s[i] <= '9') || s[i] == '.')
		i++;
	if (s[i] == 'c')
		parse_int(list, &head, s);
	else if (s[i] == 's')
		parse_string(list, &head);
	else if (s[i] == 'p')
	{
		val = malloc(sizeof(void *));
		*(void **)val = va_arg(list, void *);
		node = ft_lstnew(val);
		node->type = 'p';
		ft_lstadd_back(head, node);
	}
	else if (s[i] == 'd' || s[i] == 'i')
		parse_int(list, &head, s);
	else if (s[i] == 'u')
		parse_unsigned(list, &head);
	else if (s[i] == 'x' || s[i] == 'X')
		parse_int(list, &head, s);
}
