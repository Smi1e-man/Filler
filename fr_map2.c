/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:52:31 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/25 14:44:28 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check(t_quest *l, int m[l->map->sz[0]][l->map->sz[1]], int sum)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	while (++i < l->tk->sz[0] && (j = -1) == -1)
	{
		while (++j < l->tk->sz[1])
		{
			if (l->tk->pl[i][j] == '*' && m[l->xy[0] + i][l->xy[1] + j] == -2)
				return (0);
			if (l->tk->pl[i][j] == '*' && (l->xy[0] + i) < l->map->sz[0] &&
			(l->xy[1] + j) < l->map->sz[1] && m[l->xy[0] + i][l->xy[1] + j] != -2)
			{
				if (m[l->xy[0] + i][l->xy[1] + j] == -1)
					k++;
				else if (k > 1)
					return (0);
				else
					sum += m[l->xy[0] + i][l->xy[1] + j];
			}
		}
	}
	return (k == 1 ? sum : 0);
}

void	map2(t_quest *el, int m[el->map->sz[0]][el->map->sz[1]])
{
	int		i;
	int		j;
	int		sum;
	int		numb;

	i = -1;
	sum = 0;
	el->min_sum_xy[0] = 0;
	el->min_sum_xy[1] = 0;
	while (++i <= (el->map->sz[0] - el->tk->sz[0]) && (j = -1) == -1)
	{
		while (++j <= (el->map->sz[1] - el->tk->sz[1]))
		{
			el->xy[0] = i;
			el->xy[1] = j;
			numb = check(el, m, 0);
			if (sum == 0 || (numb != 0 && numb < sum))
			{
				sum = numb;
				el->min_sum_xy[0] = i;
				el->min_sum_xy[1] = j;
			}
		}
	}
	ft_printf("%d %d\n", el->min_sum_xy[0], el->min_sum_xy[1]);
}
