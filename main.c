#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int     main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		rep;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((rep = get_next_line(1, &line)) > 0)
			printf("rep: %d %s\n", rep, line);
	}
}
