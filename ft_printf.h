/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboujdad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:36:33 by iboujdad          #+#    #+#             */
/*   Updated: 2026/02/28 00:36:33 by iboujdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_puthex(unsigned long n, char *base, int i);
int	ft_putptr(void *ptr);
int	ft_putnbr(int nb, int i);
int	ft_putuns(unsigned int n, int i);

#endif
