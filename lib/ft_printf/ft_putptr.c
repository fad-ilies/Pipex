/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:00:51 by ifadhli           #+#    #+#             */
/*   Updated: 2024/12/20 02:00:54 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(unsigned long nb)
{
	int		count;

	count = 0;
	if (!nb)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_puthex(nb, 'x');
	return (count);
}
