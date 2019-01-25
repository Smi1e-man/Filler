/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:01:20 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:29:18 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_check(char *s1, int k, int n)
{
	int				l;
	unsigned int	numb;

	l = 0;
	if (n < 0)
	{
		numb = n * (-1);
		l++;
	}
	else
		numb = n;
	while (--k >= 0)
	{
		s1[k] = ((numb % 10) + '0');
		numb = numb / 10;
	}
	if (l > 0)
		s1[0] = '-';
	return (s1);
}

char			*ft_itoa(int n)
{
	char	*s1;
	int		k;
	int		q;

	k = 0;
	q = n;
	while (q != 0)
	{
		q = q / 10;
		k++;
	}
	if (n <= 0)
		k++;
	s1 = ft_strnew(k);
	if (s1)
	{
		if (n == 0)
		{
			s1[0] = '0';
			return (s1);
		}
		return (ft_check(s1, k, n));
	}
	return (NULL);
}
