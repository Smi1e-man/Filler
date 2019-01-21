/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshevch <seshevch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:08:17 by seshevch          #+#    #+#             */
/*   Updated: 2018/10/26 14:19:52 by seshevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *hs, const char *nl)
{
	int		i;
	int		j;
	int		k;

	if (*nl == '\0')
		return ((char *)hs);
	i = -1;
	while (hs[++i] != '\0')
	{
		if (hs[i] == nl[0])
		{
			k = i;
			j = 0;
			while (hs[i] == nl[j] && nl[j] != '\0')
			{
				i++;
				j++;
			}
			if (nl[j] == '\0')
				return ((char *)hs + k);
			else
				i = k;
		}
	}
	return (0);
}
