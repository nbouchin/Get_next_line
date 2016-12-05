#include "get_next_line.h"
#include <fcntl.h>

int main ()
{
	/*gnl7_2.txt*/
	char		*line;
	int			fd = open("gnl7_2.txt", O_RDONLY);
	static int	i;

	while ((i = get_next_line(fd, &line)))
	{

		//ft_putnbr(i);
		ft_putendl(line);
		ft_memdel((void**)&line);
	}
	close(fd);
	/*

	   char *line;

	   get_next_line(0, &line);
	   ft_putstr(line);
	   */
}
