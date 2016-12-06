/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:22:01 by nbouchin          #+#    #+#             */
/*   Updated: 2016/12/06 11:45:09 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
#include <fcntl.h>
# define BUFF_SIZE 321

int				get_next_line(const int fd, char **line);

typedef struct	s_sbuff
{
	const int	fd;
	char		*static_buff;
}				t_sbuff;

#endif
