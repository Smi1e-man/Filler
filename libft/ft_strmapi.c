/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:34:23 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:40:26 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*s1;
	size_t		i;

	if (s)
	{
		i = 0;
		s1 = (char *)ft_strnew(ft_strlen(s));
		if (s1)
		{
			while (i < ft_strlen(s))
			{
				s1[i] = (char)f(i, s[i]);
				i++;
			}
		}
		return (s1);
	}
	return ((char *)s);
}
