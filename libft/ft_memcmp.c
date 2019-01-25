/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:53:51 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:33:56 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s11;
	const unsigned char		*s22;
	size_t					i;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
	{
		if (*(s11 + i) != *(s22 + i))
			return (*(s11 + i) - *(s22 + i));
	}
	return (0);
}
