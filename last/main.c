#include "get_next_line.h"
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd;
 	fd= open("extrait.txt", O_RDONLY);
	get_next_line(fd);

	return(0);
}
