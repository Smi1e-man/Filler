/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_map1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:55:28 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/24 18:12:58 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	place_coord_y(t_quest *el, int maps[el->map->sz[0]][el->map->sz[1]])
{
	int		y;

	y = el->map->nb * (-1);
	while (y <= el->map->nb)
	{
		if ((el->xy[0] - el->map->nb) < el->map->sz[0] &&
			(el->xy[1] + y) < el->map->sz[1] && (el->xy[1] + y) >= 0 &&
			(el->xy[0] - el->map->nb) >= 0 &&
			maps[el->xy[0] - el->map->nb][el->xy[1] + y] == 0)
			maps[el->xy[0] - el->map->nb][el->xy[1] + y] = el->map->nb;
		if ((el->xy[0] + el->map->nb) < el->map->sz[0] &&
			(el->xy[1] + y) < el->map->sz[1] &&
			(el->xy[0] + el->map->nb) >= 0 && (el->xy[1] + y) >= 0 &&
			maps[el->xy[0] + el->map->nb][el->xy[1] + y] == 0)
			maps[el->xy[0] + el->map->nb][el->xy[1] + y] = el->map->nb;
		y++;
	}
}

void	place_coord_x(t_quest *el, int maps[el->map->sz[0]][el->map->sz[1]])
{
	int		x;

	x = el->map->nb * (-1);
	while (x <= el->map->nb)
	{
		if ((el->xy[1] - el->map->nb) < el->map->sz[1] &&
			(el->xy[0] + x) < el->map->sz[0] && (el->xy[0] + x) >= 0 &&
			(el->xy[1] - el->map->nb) >= 0 &&
			maps[el->xy[0] + x][el->xy[1] - el->map->nb] == 0)
			maps[el->xy[0] + x][el->xy[1] - el->map->nb] = el->map->nb;
		if ((el->xy[1] + el->map->nb) < el->map->sz[1] &&
			(el->xy[0] + x) < el->map->sz[0] && (el->xy[0] + x) >= 0 &&
			(el->xy[1] + el->map->nb) >= 0 &&
			maps[el->xy[0] + x][el->xy[1] + el->map->nb] == 0)
			maps[el->xy[0] + x][el->xy[1] + el->map->nb] = el->map->nb;
		x++;
	}
}

void	hitmap(t_quest *el, int maps[el->map->sz[0]][el->map->sz[1]])
{
	int		i;
	int		j;
	int		flag;

	el->map->nb = 1;
	flag = 0;
	while (flag < (el->map->sz[1] < el->map->sz[0] ? el->map->sz[0] :
			el->map->sz[1] - 1) && (i = -1) == -1) 
	{
		while (++i < el->map->sz[0] && (j = -1) == -1)
			while (++j < el->map->sz[1])
				if (maps[i][j] == -2)
				{
					el->xy[0] = i;
					el->xy[1] = j;
					place_coord_y(el, maps);
					place_coord_x(el, maps);
				}
		el->map->nb += 1;
		flag++;
	}
}

void	map1(t_quest *el)
{
	int		map_1[el->map->sz[0]][el->map->sz[1]];
	int		i;
	int		j;

	i = 0;
	while (i < el->map->sz[0])
	{
		j = 0;
		while (j < el->map->sz[1])
		{
			if (el->map->plato[i][j] == '.')
				map_1[i][j] = 0;
			else if (el->map->plato[i][j] == 'O' ||
					el->map->plato[i][j] == 'o')
				map_1[i][j] = el->plr == 1 ? -1 : -2;
			else if (el->map->plato[i][j] == 'X' ||
					el->map->plato[i][j] == 'x')
				map_1[i][j] = el->plr == 2 ? -1 : -2;
			j++;
		}
		i++;
	}
	hitmap(el, map_1);
	map2(el, map_1);
}