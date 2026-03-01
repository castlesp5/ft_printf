/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:04:34 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/25 15:06:54 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(char const *s1, char *s2, size_t i, size_t j)
{
	size_t	z;

	z = 0;
	while (i <= j)
	{
		s2[z] = s1[i];
		i++;
		z++;
	}
	s2[z] = '\0';
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*s2;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strrchr(set, s1[j]))
		j--;
	l = j - i + 1;
	if (l == 1 && !s1[i])
		return (ft_calloc(1, 1));
	s2 = malloc(l + 1);
	if (!s2)
		return (NULL);
	s2 = check(s1, s2, i, j);
	return (s2);
}
