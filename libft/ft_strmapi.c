/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:50:35 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/21 09:50:36 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		s_len;
	int		i;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	if (!(result = ft_strnew(s_len)))
		return (NULL);
	i = -1;
	while (++i < s_len)
		result[i] = f(i, s[i]);
	return (result);
}
