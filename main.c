#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;
	int count = 0;

	fd = open("test1.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		printf("%d. Line: %s", count, line);
		free(line);
	}
	close(fd);
	return (0);
}
