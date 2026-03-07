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

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_puthex(unsigned int n, char *base, int i);
int		ft_puthex2(unsigned long n, char *base, int i);
int		ft_putptr(void *ptr);
int		ft_putnbr(int nb, int i, int flag);
int		ft_putuns(unsigned int n, int i);
int		hexlen(unsigned int n);
int		padd(t_list *n, int w);
int		spacepadd(t_list *n, char *width);
int		modified_spaceadd(t_list *n, char *width, int len);
int		zeropadd(t_list *n, char *width);
int		precision(t_list *n, char *width);
int		writing(t_list *head);
char	*ft_utoa(unsigned int n);
char	*ft_ltoa(long n);
void	parsing_elements(char *s, va_list list, t_list **head);
t_list	*parse(char *s, va_list list);
int		conversions(char *s, t_list *head);
int		precs(char *s, int i, t_list *head);
int		precint(char *s, int i, t_list *head);
int		machistring(char *s, int i, t_list *head);
int		u_type(t_list *n, int w);
int		d_type(t_list *n, int w);
int		x_type(t_list *n, int w);
int		hexlen(unsigned int n);
int		precision(t_list *n, char *width);
int		strin(t_list *n, int w);
char	*chwyapadd(t_list *n);
int		returnpoint(t_list *n);
int		returnzmachistring(t_list *head, char *s, int i, int z);
int		x_tmodified(t_list *n, int w, int len);
int		d_tmodified(t_list *n, int w, int len);
int		u_tmodified(t_list *n, int w, int len);
int		padd_value(char *str, int w, int len);
#endif
