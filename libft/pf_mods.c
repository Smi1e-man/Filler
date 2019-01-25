/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_mods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:51:05 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/25 13:13:33 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void		ft_mod_mem_join(char **str, int numb, char smv, int check)
{
	char	*s1;
	char	*s2;

	s2 = ft_memset(ft_strnew(numb - ft_strlen(str[0])),
						smv, numb - ft_strlen(str[0]));
	if (check == 1)
		s1 = ft_strjoin(s2, str[0]);
	else
		s1 = ft_strjoin(str[0], s2);
	free(s2);
	free(*str);
	str[0] = s1;
}

void		ft_mod_hsh(char **str, char *s, char type)
{
	char	*s2;

	if (type == 'X')
		s2 = ft_strjoin("0X", str[0]);
	else if (type == 'x')
		s2 = ft_strjoin("0x", str[0]);
	else
		s2 = ft_strjoin(s, str[0]);
	free(str[0]);
	str[0] = s2;
}

void		ft_mod_width_d(char **str, t_printf *elem)
{
	if (elem->flg_min == '-')
	{
		elem->flg_spc == ' ' ? ft_mod_hsh(&str[0], " ", '1') : 0;
		ft_mod_mem_join(&str[0], elem->width, ' ', 2);
	}
	else if (elem->flg_nul == '0' && elem->precision == -1)
	{
		elem->sign == '-' || elem->flg_sum == '+' || elem->flg_spc == ' ' ?
		ft_mod_mem_join(&str[0], elem->width - 1, '0', 1) :
		ft_mod_mem_join(&str[0], elem->width, '0', 1);
		ft_mod_sign(&str[0], elem, ' ');
	}
	else
		ft_mod_mem_join(&str[0], elem->width, ' ', 1);
}

void		ft_mod_width_x(char **str, t_printf *elem, char type, char chr)
{
	if ((elem->flg_min != '-' && elem->flg_nul != '0') ||
		(elem->flg_min != '-' && elem->flg_nul == '0' &&
		elem->precision != -1))
	{
		elem->flg_hsh == '#' ? elem->width -= 2 : 0;
		pf_put_n_char(' ', elem->width - ft_strlen(str[0]));
	}
	else if (elem->flg_min != '-' && elem->precision == -1 &&
			elem->flg_nul == '0')
	{
		if (elem->flg_hsh == '#' && elem->precision != 0)
			ft_mod_mem_join(&str[0], elem->width - 2, '0', 1);
		else
			ft_mod_mem_join(&str[0], elem->width, '0', 1);
	}
	if (elem->flg_hsh == '#' && elem->precision != 0 && chr != '0')
		ft_mod_hsh(&str[0], "0", type);
	pf_putstr(str[0]);
	if (elem->flg_min == '-')
		pf_put_n_char(' ', elem->width - ft_strlen(str[0]));
}

void		ft_mod_sign(char **str, t_printf *elem, char type)
{
	if (elem->sign == '-')
		ft_mod_hsh(&str[0], "-", '1');
	else if (elem->flg_sum == '+')
		ft_mod_hsh(&str[0], "+", '1');
	else if (elem->flg_spc == ' ' && type == ' ')
		ft_mod_hsh(&str[0], " ", '1');
}
