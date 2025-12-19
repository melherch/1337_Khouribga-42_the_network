#include "get_next_line.h"

static char	*read_and_raw_line(int fd, char *raw_line)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	char    *buffer = malloc(((size_t)BUFFER_SIZE) + 1);
	while (check_for_newline(raw_line) < 0 && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(raw_line),raw_line = NULL, NULL);
		buffer[bytes] = '\0';
		tmp = ft_strjoin(raw_line, buffer);
		if (!tmp)
			return(free(buffer), free(raw_line), NULL);
		free(raw_line);
		raw_line = tmp;
	}
	return (free(buffer), raw_line);
}

static char	*extract_line(char *raw_line)
{
	size_t	i;
	char	*line;

	if (!raw_line || !raw_line[0]) 
		return (NULL);
	i = 0;
	while (raw_line[i] && raw_line[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (raw_line[i] && raw_line[i] != '\n')
	{
		line[i] = raw_line[i];
		i++;
	}
	if (raw_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_raw_line(char *raw_line)
{
	ssize_t	i;
	size_t	j;
	char	*new;

	i = check_for_newline(raw_line);
	if (i < 0)
		return (free(raw_line), NULL);
	i++;
	new = malloc(ft_strlen(raw_line + i) + 1);
	if (!new)
		return (free(raw_line), NULL);
	j = 0;
	while (raw_line[i])
		new[j++] = raw_line[i++];
	new[j] = '\0';
	free(raw_line);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*raw_line;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (free(raw_line), NULL);
	if (check_for_newline(raw_line) > 0)
	{
		line = extract_line(raw_line);
		if (!line)
		 	return(free(raw_line), raw_line = NULL, NULL);
		raw_line = update_raw_line(raw_line);
		return (line);
	}
	raw_line = read_and_raw_line(fd, raw_line);
	if (!raw_line)
		return (NULL);
	line = extract_line(raw_line);
	if (!line)
		return(free(raw_line), raw_line = NULL, NULL);
	raw_line = update_raw_line(raw_line);
	return (line);
}
