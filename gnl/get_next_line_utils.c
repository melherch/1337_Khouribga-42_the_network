#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*out;

	if (!s)
		return (NULL);
	out = malloc(ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*out;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return(ft_strdup(s2));
	if (!s2)
		return(ft_strdup(s1));
	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		out[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		out[i++] = s2[j++];
	out[i] = '\0';
	return (out);
}

ssize_t	check_for_newline(char *string)
{
	long	i = 0;

	if (!string)
		return (-1);
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
