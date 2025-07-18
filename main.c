#include "get_next_line.h"
#include "stdio.h"


int	main(void)
{
	char *line;
	int		fd;
int i = 0;
	fd = open("test.txt", O_RDONLY);
	printf ("\n\nrun %d\n\n", i);
	i++;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("\n\nrun %d\nline from in prev.run is: %s", i, line);
		write(1, "\n", 1);
		free(line);
		printf("\n");
		i++;
	}
	close(fd);
	return (0);
}