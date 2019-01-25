/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:22:12 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/25 13:13:33 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

char	*pf_itoa_base(unsigned long long val, int base)
{
	char					*str;
	unsigned int			i;
	unsigned long long		v1;

	i = 0;
	v1 = val;
	while (v1 != 0)
	{
		v1 /= base;
		i++;
	}
	if (val == 0)
		i++;
	str = ft_strnew(i);
	while (i-- != 0)
	{
		if ((val % base) > 9)
			v1 = (val % base) - 10 + 'a';
		else
			v1 = (val % base) + '0';
		str[i] = v1;
		val /= base;
	}
	return (str);
}

char	*pf_itoa_base_d(long long val, int base)
{
	char					*str;
	unsigned int			i;
	long long				v1;

	i = 0;
	v1 = val;
	while (v1 != 0)
	{
		v1 /= base;
		i++;
	}
	if (val == 0)
		i++;
	str = ft_strnew(i);
	while (i-- != 0)
	{
		if (MDL(val % base) > 9)
			v1 = MDL(val % base) - 10 + 'a';
		else
			v1 = MDL(val % base) + '0';
		str[i] = v1;
		val /= base;
	}
	return (str);
}
