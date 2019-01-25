/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:03:43 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/31 13:36:47 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	if (n < 0)
	{
		if (n >= -9)
			ft_putchar_fd('-', fd);
		ft_putchar_fd(('0' - (n % 10)), fd);
	}
	else
		ft_putchar_fd(((n % 10) + '0'), fd);
}
