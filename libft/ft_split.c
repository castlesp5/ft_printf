/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 02:17:17 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/20 02:30:40 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			l++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
	}
	return (l);
}

static void	*ft_free(char **x, int j)
{
	while (j >= 0)
	{
		free(x[j]);
		j--;
	}
	free(x);
	return (NULL);
}

static char	**fill(char **x, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		x[j] = ft_substr(s, start, (i - start));
		if (!x[j])
			return (ft_free(x, j - 1));
		j++;
	}
	x[j] = NULL;
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	**x;

	x = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!x)
		return (NULL);
	x = fill(x, s, c);
	return (x);
}
