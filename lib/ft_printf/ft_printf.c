/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 02:13:13 by ifadhli           #+#    #+#             */
/*   Updated: 2024/12/21 02:59:11 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check_format(va_list args, const char symb)
{
	int	count;

	count = 0;
	if (symb == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (symb == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (symb == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (symb == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (symb == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (symb == 'u')
		count += ft_putunint(va_arg(args, unsigned int));
	else if (symb == 'x' || symb == 'X')
		count += ft_puthex(va_arg(args, unsigned int), symb);
	else if (symb == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += check_format(args, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
