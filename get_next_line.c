/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:16:49 by nbouchin          #+#    #+#             */
/*   Updated: 2016/12/06 11:39:39 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_realloc(char *buff, int size)
{
	char	*swap;

	swap = ft_strnew(ft_strlen(buff));
	ft_strcpy(swap, buff);
	ft_strdel(&buff);
	buff = ft_strnew(ft_strlen(swap) + size);
	ft_strcpy(buff, swap);
	ft_strdel(&swap);
	return (buff);
}

static int	function(char **sb, char *buff, char **line)
{
	*line = ft_strdup(buff);
	if (*line[0] != '\0')
	{
		*sb = NULL;
		ft_strdel(&buff);
		return (1);
	}
	else
	{
		*sb = NULL;
		ft_strdel(&buff);
		return (0);
	}
}

int			get_next_line(const int fd, char **line)
{
	char			*buff;
	char static		*sb;
	int				i;

	i = 0;
	if (!line || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (sb)
		buff = ft_strdup(sb);
	else
		buff = ft_strnew(0);
	buff = ft_realloc(buff, BUFF_SIZE);
	while (!ft_strchr(buff, '\n'))
	{
		if (read(fd, buff + ft_strlen(buff), BUFF_SIZE) <= 0)
			break ;
		buff = ft_realloc(buff, BUFF_SIZE);
	}
	i = ft_strchr(buff, '\n') ? ft_strchr(buff, '\n') - buff : -1;
	if (i < 0)
		return (function(&sb, buff, line));
	*line = ft_strsub(buff, 0, i);
	sb = ft_strsub(buff, i + 1, ft_strlen(buff) + i);
	ft_strdel(&buff);
	return (1);
}
