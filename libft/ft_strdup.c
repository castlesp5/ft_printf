/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:07:46 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/23 00:10:34 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	l;
	char	*p;

	l = ft_strlen(src) + 1;
	p = malloc(l);
	if (p != NULL)
	{
		ft_memcpy(p, src, l);
	}
	return (p);
}
