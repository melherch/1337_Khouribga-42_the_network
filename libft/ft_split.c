/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-herc <mel-herc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 05:01:24 by mel-herc          #+#    #+#             */
/*   Updated: 2025/11/06 08:51:19 by mel-herc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char sep)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
		{
			count++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (count);
}

static char	*get_word(char const *str, char sep, int *ndx)
{
	char	*out;
	int		len;
	int		i;

	i = *ndx;
	while (str[i] && str[i] == sep)
		i++;
	(*ndx) = i;
	while (str[i] && str[i] != sep)
		i++;
	len = i - (*ndx);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	len = 0;
	while ((*ndx) < i)
		out[len++] = str[(*ndx)++];
	out[len] = '\0';
	return (out);
}

static void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;
	int		ndx;
	int		i;

	ndx = 0;
	if (!s)
		return (NULL);
	words = word_count(s, c);
	strs = malloc ((words + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < words)
	{	
		strs[i] = get_word(s, c, &ndx);
		if (!strs[i])
		{
			ft_free(strs);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
