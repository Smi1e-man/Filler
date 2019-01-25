/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:49:12 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:43:04 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*s1;
	size_t			i;
	unsigned int	start;
	size_t			len;

	if (s)
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] == '\0')
			return (s1 = ft_strnew(1));
		start = i;
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i--;
		len = i - start + 1;
		s1 = (char *)ft_strsub(s, start, len);
		if (s1)
		{
			return (s1);
		}
		return (s1);
	}
	return (NULL);
}
