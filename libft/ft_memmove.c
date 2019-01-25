/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:28:11 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:34:36 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst1;
	char		*src1;

	i = -1;
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (src < dst)
	{
		while ((int)len-- > 0)
			*(dst1 + len) = *(src1 + len);
	}
	else
	{
		while (++i < len)
			*(dst1 + i) = *(src1 + i);
	}
	return (dst);
}
