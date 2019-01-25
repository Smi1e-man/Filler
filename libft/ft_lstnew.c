/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:18:13 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:32:34 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*s;

	if ((s = (t_list *)malloc(sizeof(t_list))))
	{
		s->next = NULL;
		if (content)
		{
			s->content = malloc(content_size);
			s->content = ft_memcpy((s->content), content, content_size);
			s->content_size = content_size;
		}
		else
		{
			s->content = NULL;
			s->content_size = 0;
		}
		return (s);
	}
	else
		return (NULL);
}
