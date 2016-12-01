#include "get_next_line.h"
#include <fcntl.h>

int main ()
{
	char   *line;
	int   fd = open("test", O_RDONLY);
	int   i;

	while ((i = get_next_line(fd, &line)))
	{
		ft_putendl(line);
		ft_memdel((void**)&line);
	}
	close(fd);
}
