/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:49:30 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:39:47 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		k;

	i = ft_strlen(dst);
	k = ft_strlen(src);
	if (dstsize >= (i + 1))
	{
		ft_strncat(dst, src, dstsize - i - 1);
	}
	else
	{
		i = dstsize;
	}
	return (k + i);
}
