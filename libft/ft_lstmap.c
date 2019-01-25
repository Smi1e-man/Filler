/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:43:29 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:32:06 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*s1;
	t_list	*s2;

	s1 = NULL;
	if ((s1 = (t_list *)malloc(sizeof(t_list))) && lst)
	{
		s1 = f(lst);
		s2 = s1;
		lst = lst->next;
		while (lst)
		{
			if ((s2->next = (t_list *)malloc(sizeof(t_list))))
			{
				s2->next = f(lst);
				lst = lst->next;
				s2 = s2->next;
			}
		}
	}
	return (s1);
}
