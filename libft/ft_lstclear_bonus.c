/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:11:35 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/23 00:25:35 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*t;

	if (!del || !lst)
		return ;
	p = *lst;
	while (p)
	{
		t = p->next;
		ft_lstdelone(p, del);
		p = t;
	}
	*lst = NULL;
}
