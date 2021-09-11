#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main()
{
	int fd;
	int i;
	
	i = 0;
	fd = open("extrait.txt", O_RDONLY);
	while (i<23)
	{		
		get_next_line(fd);
		i++;
	}
}
