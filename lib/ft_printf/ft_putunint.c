/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:22:58 by ifadhli           #+#    #+#             */
/*   Updated: 2024/12/20 01:23:00 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunint(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
	{
		count += ft_putunint(nb / 10);
		count += ft_putunint(nb % 10);
	}
	else
	{
		count += ft_putchar(nb + '0');
	}
	return (count);
}
