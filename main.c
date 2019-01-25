/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:05:06 by seshevch          #+#    #+#             */
/*   Updated: 2019/01/24 18:18:53 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	plato_malloc(t_fllr2 *el, int fd, char *line, char type)
{
	int		i;

	el->plato = (char **)malloc(sizeof(char *) * el->sz[0] + 1);
	i = 0;
	while(i < el->sz[0])
	{
		get_next_line(fd, &line);
		if (type == '1')
		{
			el->plato[i] = ft_strdup(ft_strchr(line, ' ') + 1);
			free(line);
		}
		else if (type == '0')
		{
			el->plato[i] = ft_strdup(line);
			free(line);
		}
		i++;
	}
	el->plato[i] = NULL;
}

void	save_size(t_quest	*el, char *s1, char type)
{
	if (type == '1')
	{
		el->map->sz[0] = ft_atoi(ft_strchr(s1, ' '));
		el->map->sz[1] = ft_atoi(ft_strrchr(s1, ' '));
	}
	else
	{
		el->ttrmn->sz[0] = ft_atoi(ft_strchr(s1, ' '));
		el->ttrmn->sz[1] = ft_atoi(ft_strrchr(s1, ' '));
	}
}

void	struct_free(t_quest	*el)
{
	int		i;

	i = -1;
	while (++i < el->map->sz[0])
		free(el->map->plato[i]);
	i = -1;
	while (++i < el->ttrmn->sz[0])
		free(el->ttrmn->plato[i]);
	free(el->ttrmn->plato);
	free(el->map->plato);
	free(el->map);
	free(el->ttrmn);
	el->xy[0] = 0;
	el->xy[1] = 0;
	el->min_sum_xy[0] = 0;
	el->min_sum_xy[1] = 0;
}

int		main(void)
{
	char		*line;
	t_quest		*el;
	int			k;

	el = (t_quest*)malloc(sizeof(t_quest));
	get_next_line(0, &line);
	if ((ft_strstr(line, "$$$ exec p")))
	{
		el->plr = line[10] - '0';
		k = 1;
		free(line);
		while (k == 1)
		{
			el->map = (t_fllr2*)malloc(sizeof(t_fllr2));
			el->ttrmn = (t_fllr2*)malloc(sizeof(t_fllr2));
			k = get_next_line(0, &line);
			if (k != 1)
				return (0);
			save_size(el, line, '1');
			free(line);
			get_next_line(0, &line);
			free(line);
			plato_malloc(el->map, 0, line, '1');
			get_next_line(0, &line);
			save_size(el, line, '0');
			free(line);
			plato_malloc(el->ttrmn, 0, line, '0');
			map1(el);
			struct_free(el);
		}
			free(line);
	}
	else
		ft_printf("error");
	return(0);
}