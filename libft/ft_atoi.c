/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-herc <mel-herc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:35:03 by mel-herc          #+#    #+#             */
/*   Updated: 2025/11/07 21:07:36 by mel-herc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	ret;

	ret = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		if (sign == -1 && (ret > (LONG_MAX / 10)
				|| ((ret == LONG_MAX / 10) && (*nptr - 48) > 8)))
			return (0);
		if (sign == 1 && (ret > (LONG_MAX / 10)
				|| ((ret == LONG_MAX / 10) && (*nptr - 48) > 7)))
			return (-1);
		ret = (ret * 10) + (*nptr - 48);
		nptr++;
	}
	return (ret * sign);
}
