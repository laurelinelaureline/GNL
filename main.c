#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int fd;
	char *line;
	int i = 1;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("L%d >> [%s]", i++, line);
		free(line);
	}

	printf("END (get_next_line returned NULL)\n");
	close(fd);
	return (0);
}

