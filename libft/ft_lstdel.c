/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:00:09 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:30:08 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*s;

	if (*alst)
	{
		while (*alst)
		{
			s = *alst;
			del((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
			free(s);
		}
		*alst = NULL;
	}
}
