/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-herc <mel-herc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:20:28 by mel-herc          #+#    #+#             */
/*   Updated: 2025/11/07 14:59:02 by mel-herc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*get_str(char const *str, size_t start, size_t end)
{
	size_t	len;
	size_t	i;
	char	*out;

	i = 0;
	len = end + 1 - start;
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = str[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	if (*set == '\0')
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && is_set(set, s1[start]))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (end > 0 && is_set(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	return (get_str(s1, start, end));
}
