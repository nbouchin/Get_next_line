/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:21:55 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/28 18:01:27 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];

	while (!ft_strchr(buff, '\n'))
	{
		read(fd, &buff, BUFF_SIZE);
		ft_strcat(*line = ft_strdup(buff), buff);
	}
	return (1);
}

int main (int argc, char **argv)
{
	char *test;

	get_next_line(0, &test);
	ft_putstr("====== line ======");
	ft_putchar('\n');
	ft_putstr(test);
	ft_putchar('\n');
	ft_putstr("====== End of Line ======");
	ft_putchar('\n');
}
