/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:52:10 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:33:23 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*s1;
	const unsigned char		*s2;
	size_t					i;

	i = 0;
	s1 = dst;
	s2 = src;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s1[i] == (unsigned char)c)
			return (dst + (i + 1));
		i++;
	}
	return (0);
}
