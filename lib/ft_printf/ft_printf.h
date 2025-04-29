/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:20:42 by ifadhli           #+#    #+#             */
/*   Updated: 2024/12/21 03:27:31 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr(int nb);
int	ft_putptr(unsigned long nb);
int	check_format(va_list args, const char symb);
int	ft_putstr(char *str);
int	ft_putunint(unsigned int nb);
int	ft_putchar(char c);
int	ft_puthex(unsigned long nb, const char c);

#endif
