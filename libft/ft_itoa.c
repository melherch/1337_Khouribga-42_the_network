/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-herc <mel-herc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:24:09 by mel-herc          #+#    #+#             */
/*   Updated: 2025/11/07 21:04:03 by mel-herc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_count(long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = num * (-1);
		count++;
	}
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	tmp;
	long	nb;
	char	*num_str;

	nb = n;
	len = digits_count(nb);
	if (n == 0)
		return (ft_strdup("0"));
	num_str = malloc((len + 1) * sizeof(char));
	if (!num_str)
		return (NULL);
	tmp = len - 1;
	if (nb < 0)
	{
		num_str[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		num_str[tmp--] = nb % 10 + 48;
		nb /= 10;
	}
	num_str[len] = '\0';
	return (num_str);
}
