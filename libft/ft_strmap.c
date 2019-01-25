/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:56:59 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:40:14 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				s1[i] = (char)f(s[i]);
				i++;
			}
		}
		return (s1);
	}
	return ((char *)s);
}
