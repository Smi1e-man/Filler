/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:52:31 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/24 18:21:24 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check(t_quest *el, int maps[el->map->sz[0]][el->map->sz[1]], int sum)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	while (++i < el->ttrmn->sz[0] && (j = -1) == -1)
	{
		while (++j < el->ttrmn->sz[1])
		{
			if (el->ttrmn->plato[i][j] == '*' &&
				maps[el->xy[0] + i][el->xy[1] + j] == -2)
				return (0);
			if (el->ttrmn->plato[i][j] == '*' &&
			(el->xy[0] + i) < el->map->sz[0] &&
			(el->xy[1] + j) < el->map->sz[1] &&
			maps[el->xy[0] + i][el->xy[1] + j] != -2)
			{
				if (maps[el->xy[0] + i][el->xy[1] + j] == -1)
					k++;
				else if (k > 1)
					return (0);
				else
					sum += maps[el->xy[0] + i][el->xy[1] + j];
			}
		}
	}
	if (k == 1)
		return (sum);
	else
		return (0);
}

void	map2(t_quest *el, int maps[el->map->sz[0]][el->map->sz[1]])
{
	int		i;
	int		j;
	int		sum;
	int		numb;

	i = 0;
	sum = 0;
	el->min_sum_xy[0] = 0;
	el->min_sum_xy[1] = 0;
	while (i <= (el->map->sz[0] - el->ttrmn->sz[0]))
	{
		j = 0;
		while (j <= (el->map->sz[1] - el->ttrmn->sz[1]))
		{
			el->xy[0] = i;
			el->xy[1] = j;
			numb = check(el, maps, 0);
			if (sum == 0 || (numb != 0 && numb < sum))
			{
				sum = numb;
				el->min_sum_xy[0] = i;
				el->min_sum_xy[1] = j;
			}
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", el->min_sum_xy[0], el->min_sum_xy[1]);
}