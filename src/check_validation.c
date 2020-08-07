/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <dshala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:57:45 by dshala            #+#    #+#             */
/*   Updated: 2019/10/29 15:59:45 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_valid_string(char buf[], int read_bytes)
{
	ssize_t		i;
	int			hash;
	int			hash_links;

	i = 0;
	hash = 0;
	hash_links = 0;
	while (i < read_bytes && (buf[i] == 10 || buf[i] == 46 || buf[i] == 35))
	{
		if (buf[i] == 35)
		{
			hash++;
			hash_links += get_valid_tetramino(buf, i);
		}
		else if (buf[i] == 10)
		{
			if (i == 0 || check_nline_position(buf, i, read_bytes) == 0)
				return (0);
		}
		i++;
	}
	if (i != read_bytes || hash != 4 || (hash_links != 6 && hash_links != 8))
		return (0);
	return (1);
}

int		check_nline_position(char buf[], ssize_t i, ssize_t read_bytes)
{
	if (read_bytes == 21)
	{
		if ((i + 1) % 5 != 0 && buf[read_bytes - 1] != 10)
			return (0);
	}
	else
	{
		if ((i + 1) % 5 != 0)
			return (0);
	}
	return (1);
}

int		get_valid_tetramino(char buf[], ssize_t i)
{
	int	hash_links;

	hash_links = 0;
	if (i < 16 && buf[i + 1] == 35 && buf[i + 5] == 35)
		hash_links += 2;
	else if ((i < 18 && buf[i + 1] == 35) || (i < 14 && buf[i + 5] == 35))
		hash_links++;
	if (i > 4 && buf[i - 1] == 35 && buf[i - 5] == 35)
		hash_links += 2;
	else if ((i > 0 && buf[i - 1] == 35) || (i > 4 && buf[i - 5] == 35))
		hash_links++;
	return (hash_links);
}
