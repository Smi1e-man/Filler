/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:31:57 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/20 17:03:08 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "gnl/libft/includes/libft.h"

# define BUFF_SIZE 1

typedef struct			s_pok
{
	char				*data;
	int					fd_cp;
	unsigned int		n_elm;
	unsigned int		nb;
	struct s_pok		*next;
}						t_apok;

int						get_next_line(const int fd, char **line);

#endif
