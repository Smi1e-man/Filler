/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:18:23 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:42:29 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_word(char *s, char c)
{
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			b++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (b);
}

static char		**ft_word_print(char **s1, char *s, char c, int j)
{
	int		k;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[k] != c && s[k] != '\0')
			k++;
		if ((j + 1) < ft_nb_word((char *)s, c))
			s1[++j] = ft_strsub(s, i, (k - i));
		if (j != -1 && s1[j] == NULL)
			ft_strdel(s1);
		i = k;
	}
	s1[j + 1] = NULL;
	return (s1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**s1;
	int		j;
	int		len;

	if (s)
	{
		len = ft_nb_word((char *)s, c);
		s1 = (char **)malloc(sizeof(char *) * (len + 1));
		if (s1)
		{
			j = -1;
			return (ft_word_print(s1, (char *)s, c, j));
		}
		return (s1);
	}
	return (NULL);
}
