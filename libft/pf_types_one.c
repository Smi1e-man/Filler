/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_types_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:53:20 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/25 13:45:54 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void		ft_type_c(va_list argstr, t_printf *elem)
{
	char	c;

	c = va_arg(argstr, int);
	if (elem->width > 1)
	{
		if (elem->flg_min != '-' && elem->flg_nul != '0')
			pf_put_n_char(' ', elem->width - 1);
		else if (elem->flg_min != '-' && elem->flg_nul == '0')
			pf_put_n_char('0', elem->width - 1);
		pf_put_n_char(c, 1);
		if (elem->flg_min == '-')
			pf_put_n_char(' ', elem->width - 1);
	}
	else
		pf_put_n_char(c, 1);
}

void		ft_type_s(va_list argstr, t_printf *elem)
{
	char	*str;
	char	*s1;

	str = elem->precision != 0 ? va_arg(argstr, char *) : 0;
	str = str == NULL ? ft_strdup("(null)") : ft_strdup(str);
	if (elem->precision != -1 && elem->precision < (int)ft_strlen(str))
	{
		s1 = ft_strsub(str, 0, elem->precision);
		free(str);
		str = s1;
	}
	if (elem->width != -1 && elem->width > (int)ft_strlen(str))
	{
		if (elem->flg_min != '-' && elem->flg_nul != '0')
			ft_mod_mem_join(&str, elem->width, ' ', 1);
		else if (elem->flg_min != '-' && elem->flg_nul == '0')
			ft_mod_mem_join(&str, elem->width, '0', 1);
		if (elem->flg_min == '-')
			ft_mod_mem_join(&str, elem->width, ' ', 2);
		pf_putstr(str);
	}
	else
		pf_putstr(str);
	free(str);
}

void		ft_type_p_width(char **str, t_printf *elem)
{
	elem->precision == -1 && elem->flg_nul == '0' ? pf_putstr("0x") : 0;
	if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
		(elem->flg_min != '-' && elem->flg_nul == '0' &&
		elem->precision != -1))
		pf_put_n_char(' ', elem->width - ft_strlen(str[0]) - 2);
	else if (elem->flg_min != '-' && elem->precision == -1 &&
			elem->flg_nul == '0')
		pf_put_n_char('0', elem->width - ft_strlen(str[0]) - 2);
	if ((elem->precision != -1 && elem->flg_nul != '0') ||
		(elem->precision != -1 && elem->flg_nul == '0') ||
		(elem->precision == -1 && elem->flg_nul != '0'))
		pf_putstr("0x");
	pf_putstr(str[0]);
	if (elem->flg_min == '-')
		pf_put_n_char(' ', elem->width - ft_strlen(str[0]) - 2);
}

void		ft_type_p(va_list argstr, t_printf *elem)
{
	unsigned long long	i;
	char				*str;

	i = va_arg(argstr, unsigned long long);
	str = pf_itoa_base(i, 16);
	elem->precision == 0 && str[0] == '0' ? str[0] = '\0' : 0;
	if (elem->precision != -1 && elem->precision > (int)ft_strlen(str))
		ft_mod_mem_join(&str, elem->precision, '0', 1);
	if (elem->width != -1 && elem->width > (int)(ft_strlen(str) + 2))
		ft_type_p_width(&str, elem);
	else
	{
		pf_putstr("0x");
		pf_putstr(str);
	}
	free(str);
}

void		ft_type_non(char c, t_printf *elem)
{
	if (elem->width > 1)
	{
		if (elem->flg_min != '-' && elem->flg_nul != '0')
			pf_put_n_char(' ', elem->width - 1);
		else if (elem->flg_min != '-' && elem->flg_nul == '0')
			pf_put_n_char('0', elem->width - 1);
		pf_put_n_char(c, 1);
		if (elem->flg_min == '-')
			pf_put_n_char(' ', elem->width - 1);
	}
	else
		pf_put_n_char(c, 1);
}
