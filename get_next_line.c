/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:16:49 by nbouchin          #+#    #+#             */
/*   Updated: 2016/12/03 12:54:20 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *buff, int size)
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

int		get_next_line(const int fd, char **line)
{
	char			*buff;
	char static		*sb;
	int				ret;

	if (!line || fd < 0 || read(fd, 0, 0))
		return (-1);
	buff = ft_strnew(BUFF_SIZE + 1);
	*line = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(buff, '\n'))
	{
		if (!((ret = read(fd, buff, BUFF_SIZE)) > 0))
		{
			if (buff[0] == '\0')
			{
				ft_strdel(&buff);
				ft_strdel(&sb);
				ft_strdel(line);
				return (0);
			}
			else
			{
				ft_strdel(&buff);
				return (1);
			}
		}
		buff[ret] = 0;
		if (!ft_strchr(buff, '\n'))
		{
			*line = ft_realloc(*line, BUFF_SIZE);
			ft_strcat(*line, buff);
		}
		if (ft_strchr(buff, '\n'))
		{
			if (sb)
			{
				*line = ft_realloc(*line, ft_strlen(sb));
				ft_strcat(*line, sb);
			}
			*line = ft_realloc(*line, BUFF_SIZE);
			ft_strcat(*line, buff);
			sb = ft_strsub(buff,ft_linelen(buff) , ft_strlen(*line));
			ft_strdel(&sb);
		}
	}
	ft_strdel(&buff);
	*line = ft_strsub(*line, 0, ft_linelen(*line));
	return (1);
}
