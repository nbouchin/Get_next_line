/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:45:06 by nbouchin          #+#    #+#             */
/*   Updated: 2016/11/10 13:08:28 by nbouchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*new_list;

	tmp = *alst;
	while (tmp)
	{
		new_list = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = new_list;
	}
	*alst = NULL;
}
