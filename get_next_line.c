#include "get_next_line.h"

char	*ft_update_buffer(char *chunk, char *buffer)
{
	// 
}

char	*ft_extract_line(char *buffer)
{
	char	*next_line;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	next_line = (char *)malloc(sizeof(char) * i + 1);
	if (!next_line)
		return (NULL);
	while (k < i)
	{
		next_line[k] = buffer[k];
		k++;
	}
	next_line[k] = '\0';
	return (next_line);
}

char	*ft_read(int fd, char *buffer)
{
	char 	*chunk;
	size_t	read_bytes;

	chunk = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	read_bytes = 1; // what if here will be 0 n in while >= 0
	while (read_bytes > 0)
	{
		read_bytes = read(fd, chunk, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(chunk);
			return (NULL);
		}
		chunk[read_bytes] = '\0';
		buffer = ft_strjoin(chunk, buffer);
		if (ft_strchr(chunk, '\n') == 1)
			break; //  at which point we break also when it finishes without new lines??
	}
	free(chunk);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = ft_extract_line(buffer);
	if (!next_line)
		return (NULL); // is needed???
	buffer = ft_update_buffer(buffer);

	return (next_line);
}
