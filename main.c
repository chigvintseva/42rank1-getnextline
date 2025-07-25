#include "get_next_line.h"
#include "stdio.h"


int	main(void)
{
	char *line;
	int		fd;
int i = 0;
	fd = open("tests/empty.txt", O_RDONLY);
	printf ("\nrun %d\n", i);
	i++;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("\nrun %d\nline from in prev.run is: %s", i, line);
		write(1, "\n", 1);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
