/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:50:02 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/18 13:53:18 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	const char	*p;

	i = 0;
	p = (const char *)str;
	while (i < n)
	{
		if (*p == (char)c)
		{
			return ((void *)p);
		}
		p++;
		i++;
	}
	return (NULL);
}
