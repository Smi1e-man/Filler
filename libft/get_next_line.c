/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:35:17 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/25 14:04:21 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

void		ft_ss(t_apok *lst, char **line, unsigned int len)
{
	char			*join;
	char			*sub;

	sub = ft_strsub(lst->data, lst->n_elm, len);
	join = ft_strjoin(*line, sub);
	free(sub);
	free(*line);
	*line = join;
}

int			ft_write(t_apok *lst, char **line, int nbread)
{
	unsigned int	i;
	char			*s;

	*line == NULL ? *line = ft_strnew(0) : 0;
	if ((s = ft_strchr((lst->data + lst->n_elm), '\n')) != 0)
	{
		i = s - (lst->data + lst->n_elm);
		ft_ss(lst, line, i);
		lst->n_elm += i + 1;
		lst->nb = nbread;
		return (1);
	}
	else
	{
		ft_ss(lst, line, nbread - lst->n_elm);
		lst->n_elm = 0;
		return (0);
	}
}

int			ft_read(t_apok *lst, char **line)
{
	int				nbread;

	if (ft_write(lst, line, lst->nb) == 1)
		return (1);
	while ((nbread = read(lst->fd_cp, lst->data, BUFF_SIZE)))
	{
		lst->data[nbread] = '\0';
		if (ft_write(lst, line, nbread) == 1)
			return (1);
	}
	free(lst->data);
	lst->data = ft_strnew(0);
	if (**line != '\0')
		return (1);
	else
	{
		free(*line);
		*line = NULL;
		return (0);
	}
}

void		ft_new_lst(t_apok **lst, const int fd)
{
	t_apok			*s1;

	s1 = (t_apok *)malloc(sizeof(t_apok));
	if (s1)
	{
		s1->data = ft_strnew(BUFF_SIZE);
		if (s1->data)
		{
			s1->fd_cp = fd;
			s1->n_elm = 0;
			s1->nb = 0;
			s1->next = *lst;
			*lst = s1;
		}
		else
			free(s1);
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_apok	*lst = NULL;
	t_apok			*s1;

	if (fd < 0 || fd > 4863 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (*line != NULL)
		*line = NULL;
	s1 = lst;
	while (s1)
	{
		if (s1->fd_cp == fd)
			return (ft_read(s1, line));
		s1 = s1->next;
	}
	ft_new_lst(&lst, fd);
	return (ft_read(lst, line));
}
