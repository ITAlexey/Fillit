/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <dshala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:03:58 by dshala            #+#    #+#             */
/*   Updated: 2019/11/15 03:16:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			delete_map(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
}

void			print_map(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_putendl(map[i++]);
}

int				get_size_of_map(t_fil *head)
{
	int		size;
	int		i;

	i = 2;
	size = lstcount(head) * 4;
	while (i * i < size)
		i++;
	return (i);
}

char			**get_map(int size)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char*) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = ft_strnew((size_t)size)))
			return (NULL);
		ft_memset(map[i], '.', (size_t)size);
		i++;
	}
	return (map);
}
