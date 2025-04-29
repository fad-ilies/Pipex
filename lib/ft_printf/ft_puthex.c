/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:38:30 by ifadhli           #+#    #+#             */
/*   Updated: 2024/12/21 01:38:35 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned long nb, const char c)
{
	char	*hexx;
	int		count;

	count = 0;
	if (c == 'x')
		hexx = "0123456789abcdef";
	else if (c == 'X')
		hexx = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_puthex(nb / 16, c);
		count += ft_puthex(nb % 16, c);
	}
	else
		count += ft_putchar(hexx[nb]);
	return (count);
}
