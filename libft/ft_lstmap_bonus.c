/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:31:29 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/23 00:53:16 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	void	*nc;

	p = NULL;
	if (!lst || !f || !del)
		return (p);
	while (lst)
	{
		nc = f(lst->content);
		if (nc == NULL)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, ft_lstnew(nc));
		lst = lst->next;
	}
	return (p);
}
