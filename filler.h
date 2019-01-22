/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:32:11 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/22 16:27:45 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLER_H
# define __FILLER_H

# include "ft_printf/printf.h"
# include "get_next_line.h"
# include "gnl/libft/includes/libft.h"

/*
**	struct
*/
typedef struct	s_f
{
	char		**plato;
	int			xy[2];

	int			pnt;
	int			numb;

}				t_fllr2;

typedef struct	s_fllr
{
	char		plr;

	t_fllr2		*map;
	t_fllr2		*ttrmn;

}				t_quest;
/*
** filler function
*/
void			map1(t_quest *elem);

#endif