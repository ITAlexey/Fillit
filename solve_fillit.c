/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <dshala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:00:54 by dshala            #+#    #+#             */
/*   Updated: 2019/11/15 03:20:52 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_boundaries(int size, t_fil *lst, char ch)
{
	if (ch == 'x')
		return (lst->block_x[0] + lst->x_offset >= size ||
				lst->block_x[1] + lst->x_offset >= size ||
				lst->block_x[2] + lst->x_offset >= size ||
				lst->block_x[3] + lst->x_offset >= size);
	else
		return (lst->block_y[0] + lst->y_offset >= size ||
				lst->block_y[1] + lst->y_offset >= size ||
				lst->block_y[2] + lst->y_offset >= size ||
				lst->block_y[3] + lst->y_offset >= size);
}

int		check_overlap(t_fil *lst, char **map)
{
	int x;
	int y;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		x = lst->block_x[i] + lst->x_offset;
		y = lst->block_y[i] + lst->y_offset;
		if (map[y][x] == '.')
			j++;
		i++;
	}
	return (j == 4);
}

void	fill_map(t_fil *lst, char **map, char ch)
{
	int	i;
	int x;
	int y;

	i = 0;
	while (i < 4)
	{
		x = lst->block_x[i] + lst->x_offset;
		y = lst->block_y[i] + lst->y_offset;
		map[y][x] = ch;
		i++;
	}
}

int		solve_map(t_fil *list, int size, char **map)
{
	if (list == NULL)
		return (1);
	list->x_offset = 0;
	list->y_offset = 0;
	while (check_boundaries(size, list, 'y') == 0)
	{
		while (check_boundaries(size, list, 'x') == 0)
		{
			if (check_overlap(list, map) == 1)
			{
				fill_map(list, map, list->latter);
				if (solve_map(list->next, size, map) == 1)
					return (1);
				else
					fill_map(list, map, '.');
			}
			list->x_offset++;
		}
		list->x_offset = 0;
		list->y_offset++;
	}
	return (0);
}

void	get_least_square(t_fil *head)
{
	char	**map;
	int		size;

	size = get_size_of_map(head);
	map = get_map(size);
	while (solve_map(head, size, map) == 0)
	{
		delete_map(map, size);
		size++;
		map = get_map(size);
	}
	print_map(map, size);
	delete_map(map, size);
	lstclr(head);
}
