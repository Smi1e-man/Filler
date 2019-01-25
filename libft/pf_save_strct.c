/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_save_strct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 12:29:53 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/25 13:13:33 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	ft_save_flag(const char *restrict str, int *count, t_printf *elem)
{
	while (str[count[0]] == '#' || str[count[0]] == '0' ||
		str[count[0]] == '-' || str[count[0]] == '+' || str[count[0]] == ' ')
	{
		if (str[count[0]] == '#')
			elem->flg_hsh = '#';
		else if (str[count[0]] == '0')
			elem->flg_nul = '0';
		else if (str[count[0]] == '-')
			elem->flg_min = '-';
		else if (str[count[0]] == '+')
			elem->flg_sum = '+';
		else if (str[count[0]] == ' ')
			elem->flg_spc = ' ';
		count[0]++;
	}
}

void	ft_sv_w(const char *restrict s, int *cnt, t_printf *el, va_list as)
{
	int		n;

	if (s[cnt[0]] == '*')
	{
		el->width = va_arg(as, int);
		if (el->width < 0)
		{
			el->width *= -1;
			el->flg_min = '-';
		}
		cnt[0]++;
	}
	else if (s[cnt[0]] >= '0' && s[cnt[0]] <= '9')
	{
		n = 0;
		while (s[cnt[0]] >= '0' && s[cnt[0]] <= '9')
		{
			n *= 10;
			n = n + (s[cnt[0]] - '0');
			cnt[0]++;
		}
		el->width = n;
	}
}

void	ft_p(const char *restrict s, int *cnt, t_printf *el, va_list as)
{
	if (s[cnt[0]] == '.')
	{
		cnt[0]++;
		if (s[cnt[0]] == '*')
		{
			el->precision = va_arg(as, int);
			if (el->precision < 0)
				el->precision = -1;
			cnt[0]++;
		}
		else
		{
			el->precision = 0;
			while (s[cnt[0]] >= '0' && s[cnt[0]] <= '9')
			{
				el->precision *= 10;
				el->precision = el->precision + (s[cnt[0]] - '0');
				cnt[0]++;
			}
		}
	}
}

void	ft_save_size(const char *restrict str, int *count, t_printf *elem)
{
	if (str[count[0]] == 'h' || str[count[0]] == 'l' || str[count[0]] == 'L')
	{
		if (str[count[0]] == 'h' && str[count[0] + 1] == 'h')
		{
			elem->size = 1;
			count[0]++;
		}
		else if (str[count[0]] == 'l' && str[count[0] + 1] == 'l')
		{
			elem->size = 2;
			count[0]++;
		}
		else if (str[count[0]] == 'h')
			elem->size = 'h';
		else if (str[count[0]] == 'l')
			elem->size = 'l';
		else if (str[count[0]] == 'L')
			elem->size = 'L';
		count[0]++;
	}
}
