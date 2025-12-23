/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-herc <mel-herc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:29:20 by mel-herc          #+#    #+#             */
/*   Updated: 2025/12/23 15:32:21 by mel-herc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char format)
{
	int		counter;
	char	*base;

	counter = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		counter += ft_puthexa(n / 16, format);
	counter += ft_putchar(base[n % 16]);
	return (counter);
}

int	ft_putaddress(void *ptr)
{
	int	counter;

	counter = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	counter += ft_putstr("0x");
	counter += ft_puthexa((unsigned long)ptr, 'x');
	return (counter);
}
