/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:36:59 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/25 13:47:29 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

long double	ft_round(long double val, t_printf *elem)
{
	int				i;
	long double		numb;

	numb = 0.1;
	i = 0;
	while (i < elem->precision)
	{
		numb /= 10;
		i++;
	}
	numb *= 5;
	val += val < 0 ? (numb * -1) : numb;
	return (val);
}

void		ft_type_f_prcsn(long double val, char **str, t_printf *elem, long i)
{
	char				*s1;
	char				*s2;

	str[0] = pf_itoa_base_d(i, 10);
	val -= (long)val;
	if (elem->precision > 0)
	{
		s1 = ft_strjoin(str[0], ".");
		free(str[0]);
		while (elem->precision-- != 0)
		{
			val /= 0.1;
			i = val;
			str[0] = pf_itoa_base_d(i, 10);
			s2 = ft_strjoin(s1, str[0]);
			free(str[0]);
			free(s1);
			s1 = s2;
			val -= i;
		}
		str[0] = s1;
	}
}

void		ft_type_f(va_list argstr, t_printf *elem)
{
	char				*str;
	long				i;

	elem->type.val = elem->size == 'L' ? (double)va_arg(argstr, long double) :
							va_arg(argstr, double);
	elem->precision == -1 ? elem->precision = 6 : 0;
	elem->type.t_bits.sign ? elem->sign = '-' : 0;
	elem->type.val = (double)ft_round(MDL(elem->type.val), elem);
	i = elem->type.val;
	ft_type_f_prcsn(MDL(elem->type.val), &str, elem, i);
	if (elem->flg_nul != '0' || elem->flg_min == '-' ||
		elem->width <= (int)ft_strlen(str) ||
		(elem->width > (int)ft_strlen(str) && elem->precision != -1))
		ft_mod_sign(&str, elem, '+');
	if (elem->width != -1 && elem->width > (int)ft_strlen(str))
		ft_mod_width_d(&str, elem);
	else if (elem->flg_spc == ' ' && elem->type.i >= 0 && elem->flg_sum != '+')
		ft_mod_hsh(&str, " ", '1');
	pf_putstr(str);
	free(str);
}
