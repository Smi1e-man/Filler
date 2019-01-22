/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_map1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:55:28 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/22 19:35:07 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_int(t_quest *elem, int maps[elem->map->xy[0]][elem->map->xy[1]])
{
	int i;
	int j;

	i = 0;
	ft_printf("%d\n%d\n", elem->map->xy[0], elem->map->xy[1]);
	while (i < elem->map->xy[0])
	{
		j = 0;
		while (j < elem->map->xy[1])
		{
			ft_printf("%3d", maps[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

// int		place_coords(t_quest *elem, int maps[elem->map->xy[0]][elem->map->xy[1]], int i, int j)
// {
// 	int		c[4];
// 	int		a;
// 	int		b;
// 	int		k;

// 	k = 0;
// 	c[0] = 0;
// 	c[1] = 0;
// 	c[2] = 1;
// 	c[3] = -1;
// 	a = 0;
// 	b = 3;
// 	while (a < 4)
// 	{
// 		if ((i + c[a]) < elem->map->xy[0] && (j + c[b]) < elem->map->xy[1])
// 		{
// 			if (maps[i + c[a]][j + c[b]] == 0)
// 			{
// 				maps[i + c[a]][j + c[b]] = elem->map->numb;
// 				k++;
// 			}
// 		}
// 		a++;
// 		b--;
// 	}
// 	c[0] = 1;
// 	c[1] = -1;
// 	c[2] = 1;
// 	c[3] = -1;
// 	a = 0;
// 	b = 0;
// 	while (a < 4)
// 	{
// 		if ((i + c[a]) < elem->map->xy[0] && (j + c[b]) < elem->map->xy[1])
// 		if (maps[i + c[a]][j + c[b]] == 0)
// 		{
// 			maps[i + c[a]][j + c[b]] = elem->map->numb;
// 			k++;
// 		}
// 		a++;
// 		if (a == 2)
// 			b++;
// 	}
// 	// print_int(elem, maps);
// 	return(k);
// }

int		place_coords(t_quest *elem, int maps[elem->map->xy[0]][elem->map->xy[1]], int i, int j)
{
	int		x;
	int		y;
	int		k;

	k = 0;
	y = elem->map->numb * (-1);
	while (y <= elem->map->numb)
	{
		if (maps[i - elem->map->numb][j + y] == 0 && (i - elem->map->numb) < elem->map->xy[0] && (i - elem->map->numb) >= 0 && (j + y) < elem->map->xy[1] && (j + y) >= 0)
			maps[i - elem->map->numb][j + y] = elem->map->numb;
		if (maps[i + elem->map->numb][j + y] == 0 && (i + elem->map->numb) < elem->map->xy[0] && (i + elem->map->numb) >= 0 && (j + y) < elem->map->xy[1] && (j + y) >= 0)
			maps[i + elem->map->numb][j + y] = elem->map->numb;
		y++;
	}
	x = elem->map->numb * (-1);
	while (x <= elem->map->numb)
	{
		if (maps[i + x][j - elem->map->numb] == 0 && (i + x) < elem->map->xy[0] && (i + x) >= 0 && (j - elem->map->numb) < elem->map->xy[1] && (j - elem->map->numb) >= 0)
			maps[i + x][j - elem->map->numb] = elem->map->numb;
		if (maps[i + x][j + elem->map->numb] == 0 && (i + x) < elem->map->xy[0] && (i + x) >= 0 && (j + elem->map->numb) < elem->map->xy[1] && (j + elem->map->numb) >= 0)
			maps[i + x][j + elem->map->numb] = elem->map->numb;
		x++;
	}
	return (k);
}

void	hitmap(t_quest *elem, int maps[elem->map->xy[0]][elem->map->xy[1]])
{
	int		i;
	int		j;
	int		flag;

	elem->map->numb = 1;
	i = 0;
	flag = 0;
	while (flag < (elem->map->xy[0] - 1))
	{
		i = 0;
		while (i < elem->map->xy[0])
		{
			j = 0;
			while (j < elem->map->xy[1])
			{
				if (maps[i][j] == -2)
				{
					place_coords(elem, maps, i, j);
				}
				j++;
			}
			i++;
		}
		elem->map->numb += 1;
		flag++;
		// print_int(elem, maps);
	}
	// while (i < elem->map->xy[0])
	// {
	// 	j = 0;
	// 	while (j < elem->map->xy[1])
	// 	{
	// 		if (maps[i][j] == -2)
	// 			place_coords(elem, maps, i, j);
	// 		j++;
	// 	}
	// 	i++;
	// }

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
				if (elem->map->plato[i][j] == '.')
					map_1[i][j] = 0;
				else if (elem->map->plato[i][j] == 'O')
					map_1[i][j] = -1;
				else if (elem->map->plato[i][j] == 'X')
					map_1[i][j] = -2;
			j++;
		}
		ft_printf("\n");
		i++;
	}
	// ft_printf("%d\n", elem->map->xy[0]);
	hitmap(elem, map_1);
	print_int(elem, map_1);
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