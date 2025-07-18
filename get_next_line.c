#include "get_next_line.h"

char	*ft_update_buffer(char *buffer)
{
	char	*temp_buffer;
	size_t	i;
	size_t	k;

	i = 0;
	temp_buffer = NULL;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0') // when it is the last line
		return (free(buffer), NULL);
	temp_buffer = (char *)malloc((ft_strlen(buffer + i)) + 1);
	if (!temp_buffer)
		return (free(buffer), NULL); // how to catch it n do i need to?
	k = 0;
	i++; //skip the /n itselfclear
	while (buffer[i] != '\0')
		temp_buffer[k++] = buffer[i++];
	temp_buffer[k] = '\0';
	free(buffer);
	buffer = temp_buffer;
	return (buffer);
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
	char	*temp_buffer;
	int		read_bytes;

	chunk = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{

		read_bytes = read(fd, chunk, BUFFER_SIZE);
		printf("num read bytes:'%d'\n", read_bytes);
		printf("inside ft_read, chunk after read:'%s'\n", chunk);
		if (read_bytes < 0)
			return (free(chunk), NULL);
		chunk[read_bytes] = '\0';
		temp_buffer = NULL;
		printf("inside ft_read, buffer 2:'%s'\n", buffer);
		printf("inside ft_read, temp buffer 2:'%s'\n", temp_buffer);
		temp_buffer = ft_strjoin(buffer, chunk);
		if (!temp_buffer)
			return (free(chunk), free(buffer), NULL);
		free(buffer);
		buffer = NULL;
		buffer = temp_buffer;
		printf("inside ft_read, buffer 3:'%s'\n", buffer);
		if (ft_strchr(chunk, (int)'\n') != NULL)
			break;
		printf("inside ft_read, chunk 4:'%s'\n", chunk);
		printf("inside ft_read, buffer4:'%s'\n", buffer);
	}
	return (free(chunk), buffer);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	printf("initial buffer:'%s'\n", buffer);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	if (buffer[0] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	next_line = NULL;
	next_line = ft_extract_line(buffer);
	if (!next_line)
		return (NULL);
	buffer = ft_update_buffer(buffer);
	return (next_line);
}
