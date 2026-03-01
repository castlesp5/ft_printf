/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:56:22 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/17 11:09:18 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*p;

	p = (char *)str + (ft_strlen(str));
	while (p >= str)
	{
		if (*p == (char)c)
		{
			return (p);
		}
		p--;
	}
	return (NULL);
}
