#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	char *line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line extracted is: %s", line);
		write(1, "\n", 1);
		free(line);
	}
	close(fd);
	return (0);
}