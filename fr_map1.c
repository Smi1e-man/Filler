/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_map1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:55:28 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/21 19:34:20 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_int(int maps[15][17], t_quest *elem)
{
	int i;
	int j;

	i = 0;
	while (i < elem->map->xy[0])
	{
		j = 0;
		while (j < elem->map->xy[1])
		{
			ft_printf("%d", maps[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	map1(t_quest *elem)
{
	int		map_1[elem->map->xy[0]][elem->map->xy[1]];
	int		i;
	int		j;

	i = 0;
	while (elem->map->plato[i] != NULL)
	{
		j = 0;
		while (elem->map->plato[i][j] != '\0')
		{
				ft_printf("%c", elem->map->plato[i][j]);
				map_1[i][j] = 0;
			j++;
		}
		ft_printf("\n");
		i++;
	}
	// ft_printf("%d\n", elem->map->xy[0]);
	print_int(map_1, elem);
	// i = 0;
	// while (i < elem->map->xy[0])
	// {
	// 	j = 0;
	// 	while (j < elem->map->xy[1])
	// 	{
	// 		ft_printf("%d", map_1[i][j]);
	// 		j++;
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }
}