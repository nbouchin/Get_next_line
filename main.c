#include <stdio.h>
#include "get_next_line.h"
int             main(int argc, char **argv)
{
	int     fd;
	int     fd1;
	int     res;
	char    *str;
	res = 0;
	fd1 = 0;
	if (!(fd = open(argv[argc - 1], O_RDONLY)))
		return (1);
	//read(fd, str1 + (ft_strlen(str1) - 1), BUFF_SIZE);
	//printf("str1 vaut donc %s\n", str1);
	while ((res = get_next_line(fd, &str)) > 0)
	{
		ft_putendl(str);
		//printf("res de gnl vaut %d \n", res);
		ft_strdel(&str);
	}
	if (!(close(fd1)))
		return (1);
	if (!(close(fd)))
		return (1);
	return (0);
}
