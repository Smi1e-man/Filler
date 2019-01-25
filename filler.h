/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:32:11 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/25 14:41:44 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLER_H
# define __FILLER_H

# include "libft/includes/libft.h"

/*
**	struct
*/
typedef struct	s_f
{
	char		**pl;
	int			sz[2];

	int			nb;

}				t_fllr2;

typedef struct	s_fllr
{
	char		plr;

	t_fllr2		*map;
	t_fllr2		*tk;

	int			xy[2];

	int			min_sum_xy[2];

}				t_quest;
/*
** filler function
*/
void			map1(t_quest *el);
void			hitmap(t_quest *el, int m[el->map->sz[0]][el->map->sz[1]]);
void			place_coord_x(t_quest *el,
							int m[el->map->sz[0]][el->map->sz[1]]);
void			place_coord_y(t_quest *el,
							int m[el->map->sz[0]][el->map->sz[1]]);
void			print_int(t_quest *el,
				int m[el->map->sz[0]][el->map->sz[1]]);

void			map2(t_quest *el, int m[el->map->sz[0]][el->map->sz[1]]);

#endif
