/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:21:55 by nbouchin          #+#    #+#             */
/*   Updated: 2016/12/01 11:59:36 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char static		*sb;
	int i;

	i = 0;
	*line = ft_strnew(1);
	if (!line)
		return (-1);
	while (!ft_strchr(buff, '\n'))
	{
		if (!(read(fd, &buff, BUFF_SIZE) > 0))
			return (0);
		if (!ft_strchr(buff, '\n'))
			*line = ft_strjoin(*line, buff);
		if (ft_strchr(buff, '\n'))
		{
			while (buff[i - 1] != '\n')
				i++;
			*line = ft_strjoin(sb, *line);
			*line = ft_strjoin(*line, buff);
			sb = ft_strsub(buff,i , ft_strlen(*line));
		}
	}
	*line = ft_strsub(*line, 0, ft_linelen(*line));
	return (1);
}
