#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	char *line;

	line = get_next_line(1);
	printf("line extracted is: -%s-", line);
	free(line);

	return (0);
}