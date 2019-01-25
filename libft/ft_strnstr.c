/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:11:55 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:41:56 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nl, size_t len)
{
	size_t	i;
	int		j;
	int		k;

	if (*nl == '\0')
		return ((char *)hs);
	i = -1;
	while (hs[++i] != '\0')
	{
		if (hs[i] == nl[0])
		{
			k = i;
			j = 0;
			while (hs[i] == nl[j] && nl[j] != '\0' && i < len)
			{
				i++;
				j++;
			}
			if (nl[j] == '\0')
				return ((char *)hs + k);
			else
				i = k;
		}
	}
	return (0);
}
