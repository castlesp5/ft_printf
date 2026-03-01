/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:19:45 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/17 09:55:33 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;
	unsigned int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0')
		y++;
	if (size <= x)
		return (size + y);
	i = x;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (x + y);
}
