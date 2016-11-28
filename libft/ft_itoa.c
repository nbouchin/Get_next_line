/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:45:16 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/21 09:45:17 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	n_len(long int n)
{
	long int len;

	len = 0;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char		*result;
	long int	len;
	long int	nb;

	nb = (long int)n;
	if (n < 0)
		nb = -nb;
	len = n_len(nb) + (n < 0);
	if (!(result = ft_strnew(len + 1)))
		return (NULL);
	if (!nb)
		result[0] = '0';
	while (nb)
	{
		result[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
