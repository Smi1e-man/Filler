/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_types_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:47:06 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/25 13:46:56 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void		ft_type_o(t_printf *elem)
{
	char				*str;

	str = pf_itoa_base(elem->type.ui, 8);
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	elem->flg_hsh == '#' && str[0] != '0' ? ft_mod_hsh(&str, "0", '1') : 0;
	if (elem->precision != -1 && elem->precision > (int)ft_strlen(str))
		ft_mod_mem_join(&str, elem->precision, '0', 1);
	if (elem->width != -1 && elem->width > (int)ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			pf_put_n_char(' ', elem->width - (int)ft_strlen(str));
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			pf_put_n_char('0', elem->width - (int)ft_strlen(str));
		pf_putstr(str);
		if (elem->flg_min == '-')
			pf_put_n_char(' ', elem->width - (int)ft_strlen(str));
	}
	else
		pf_putstr(str);
	free(str);
}

void		ft_type_u(t_printf *elem)
{
	char				*str;

	str = pf_itoa_base(elem->type.ui, 10);
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	elem->flg_hsh == '#' && str[0] != '0' ? ft_mod_hsh(&str, "0", '1') : 0;
	if (elem->precision != -1 && elem->precision > (int)ft_strlen(str))
		ft_mod_mem_join(&str, elem->precision, '0', 1);
	if (elem->width != -1 && elem->width > (int)ft_strlen(str))
	{
		if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
			(elem->flg_min != '-' && elem->flg_nul == '0' &&
			elem->precision != -1))
			pf_put_n_char(' ', elem->width - (int)ft_strlen(str));
		else if (elem->flg_min != '-' && elem->precision == -1 &&
				elem->flg_nul == '0')
			pf_put_n_char('0', elem->width - (int)ft_strlen(str));
		pf_putstr(str);
		if (elem->flg_min == '-')
			pf_put_n_char(' ', elem->width - (int)ft_strlen(str));
	}
	else
		pf_putstr(str);
	free(str);
}

void		ft_type_x(t_printf *elem, char type)
{
	char			*str;
	char			chr;

	str = pf_itoa_base(elem->type.ui, 16);
	type == 'X' ? pf_toupper_prf(&str) : 0;
	str[0] == '0' ? chr = '0' : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > (int)ft_strlen(str))
		ft_mod_mem_join(&str, elem->precision, '0', 1);
	if (elem->flg_hsh == '#' && elem->precision != 0 &&
		elem->width == -1 && str[1] != '\0')
		ft_mod_hsh(&str, "0", type);
	if (elem->width != -1 && elem->width > (int)ft_strlen(str))
		ft_mod_width_x(&str, elem, type, chr);
	else
		pf_putstr(str);
	free(str);
}

void		ft_type_d(t_printf *elem)
{
	char	*str;

	str = pf_itoa_base_d(elem->type.i, 10);
	elem->type.i < 0 ? elem->sign = '-' : 0;
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	elem->precision > (int)ft_strlen(str) ?
	ft_mod_mem_join(&str, elem->precision, '0', 1) : 0;
	if (elem->flg_nul != '0' || elem->flg_min == '-' ||
		elem->width <= (int)ft_strlen(str) ||
		(elem->width > (int)ft_strlen(str) && elem->precision != -1))
		ft_mod_sign(&str, elem, '+');
	if (elem->width > (int)ft_strlen(str))
		ft_mod_width_d(&str, elem);
	else if (elem->flg_spc == ' ' && elem->sign != '-' &&
			elem->flg_sum != '+')
		ft_mod_hsh(&str, " ", '1');
	pf_putstr(str);
	free(str);
}
