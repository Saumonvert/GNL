#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int i;
	char *line;
	int ret;
	int fd;
	line = NULL;
	i = 1;
	while(i < ac)
	{
		fd = open(av[i], O_RDONLY);
		while((ret = get_next_line(fd, &line)) > 0)
		{	
			printf("[%d] %s\n", ret, line);
			free(line);
		}
		printf("[%d] %s\n", ret, line);
		i++;
		close(fd);
	}
	return (0);
}