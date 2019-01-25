/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:23:01 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:33:09 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*str;
	unsigned char	*str1;
	size_t			i;

	i = 0;
	str = (void *)malloc(sizeof(void *) * size);
	if (str)
	{
		str1 = (unsigned char *)str;
		while (i < size)
		{
			str1[i] = 0;
			i++;
		}
	}
	return ((void *)str);
}
