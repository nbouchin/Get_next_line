/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:48:52 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/26 14:53:38 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Prend en paramètre l’adresse d’une chaine de caractères qui doit être
**	libérée avec free(3) et son pointeur mis à NULL.
*/

void	ft_strdel(char **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}
