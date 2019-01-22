/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:05:06 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/22 14:13:50 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	plato_malloc(t_fllr2 *elem, int fd, char *line, char type)
{
	int		i;

	elem->plato = (char **)malloc(sizeof(char *) * (elem->xy[0] + 1));
	i = 0;
	while(i < elem->xy[0])
	{
		get_next_line(fd, &line);
		if (type == '1')
			elem->plato[i] = ft_strdup(ft_strchr(line, ' ') + 1);
		else
			elem->plato[i] = ft_strdup(line);
		i++;
	}
	elem->plato[i] = NULL;
}

void	save_xy(t_quest	*elem, int fd, char *line, char type)
{
	if (type == '1')
	{
		get_next_line(fd, &line);
		elem->map->xy[0] = ft_atoi(ft_strchr(line, ' '));
		elem->map->xy[1] = ft_atoi(ft_strrchr(line, ' '));
	}
	else
	{
		get_next_line(fd, &line);
		elem->ttrmn->xy[0] = ft_atoi(ft_strchr(line, ' '));
		elem->ttrmn->xy[1] = ft_atoi(ft_strrchr(line, ' '));
	}
}

int		main(void)
{
	int			fd;
	char		*line;
	char		*s1;
	t_quest		*elem;
	char		**map;
	int			i;

	elem = (t_quest*)malloc(sizeof(t_quest));
	elem->map = (t_fllr2*)malloc(sizeof(t_fllr2));
	elem->ttrmn = (t_fllr2*)malloc(sizeof(t_fllr2));
	fd = open("f2", O_RDWR);
	get_next_line(fd, &line);
	if ((ft_strstr(line, "$$$ exec p")))
	{
		elem->plr = line[10];
		ft_printf("%c\n", elem->plr);
		save_xy(elem, fd, line, '1');
		get_next_line(fd, &line);
		plato_malloc(elem->map, fd, line, '1');
		ft_printf("%d\n%d\n", elem->map->xy[0], elem->map->xy[1]);
		i = 0;
		while(i < elem->map->xy[0])
		{
			ft_printf("%s\n", elem->map->plato[i]);
			i++;
		}
		// elem->map->xy[0] -= 1;
		save_xy(elem, fd, line, '0');
		ft_printf("%d\n%d\n", elem->ttrmn->xy[0], elem->ttrmn->xy[1]);
		plato_malloc(elem->ttrmn, fd, line, '0');
		i = 0;
		while(i < elem->ttrmn->xy[0])
		{
			ft_printf("%s\n", elem->ttrmn->plato[i]);
			i++;
		}
		map1(elem);
	}
	else
		ft_printf("no%s", line);
	/* save first text */
	// char	*line;
	// char	*buf;
	// char	*s1;
	// int		fd;

	// buf = ft_strnew(0);
	// fd = open("fl", O_WRONLY, O_RDONLY);
	// while(get_next_line(0, &line) == 1)
	// {
	// 	s1 = ft_strjoin(buf, line);
	// 	free(buf);
	// 	buf = s1;
	// 	s1 = ft_strjoin(buf, "\n");
	// 	free(buf);		
	// 	buf = s1;
	// }
	// 	write(fd, buf, ft_strlen(buf));
	// free(line);
	return(0);
}