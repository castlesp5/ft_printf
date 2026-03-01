/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:19:08 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/22 14:48:56 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(char *p, char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		if (i == start)
		{
			while (j < len && s[i + j])
			{
				p[j] = s[i + j];
				j++;
			}
			p[j] = '\0';
			return (p);
		}
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (s[0] == '\0' || start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > (ft_strlen(s) - start))
		p = (char *)malloc(ft_strlen(&s[start]) + 1);
	else
		p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	p = check(p, s, start, len);
	return (p);
}
