#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	char *line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open failed");
		return (5);  // <- you are likely returning this exit code
	}
	line = get_next_line(fd);
	printf("line extracted is: %s\n", line);
	free(line);

	return (0);
}