/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <iboujdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:22:13 by iboujdad          #+#    #+#             */
/*   Updated: 2025/10/21 01:42:22 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	buff[12];
	int		i;
	long	nb;

	nb = n;
	i = 11;
	buff[i--] = '\0';
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		buff[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		buff[i--] = '-';
	return (ft_strdup(&buff[i + 1]));
}
