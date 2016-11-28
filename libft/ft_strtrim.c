/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:52:02 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/21 09:52:05 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	unsigned int	west;
	unsigned int	east;

	if (!s)
		return ("");
	east = ft_strlen(s) - 1;
	west = 0;
	while (isspace(s[west]))
		west++;
	if (!s[west])
		return (ft_strnew(1));
	while (isspace(s[east]))
		east--;
	east = (ft_strlen(s) - 1) - east;
	return (ft_strsub(s, west, (size_t)(ft_strlen(s) - (west + east))));
}
