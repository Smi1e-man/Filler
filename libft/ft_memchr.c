/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:10:33 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:33:39 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*s1;
	size_t					i;

	s1 = (unsigned char *)s;
	i = -1;
	while (++i < n)
	{
		if (s1[i] == (unsigned char)c)
			return ((unsigned char *)(s + i));
	}
	return (0);
}
