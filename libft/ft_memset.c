/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 02:10:23 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/15 20:57:06 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	unsigned char	c;
	size_t			i;

	i = 0;
	p = (unsigned char *)ptr;
	c = (unsigned char)value;
	while (i < num)
	{
		p[i] = c;
		i++;
	}
	return (ptr);
}
