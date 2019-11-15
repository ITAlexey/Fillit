/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <dshala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:58:29 by dshala            #+#    #+#             */
/*   Updated: 2019/11/15 02:42:44 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUF 21

void		record_position(t_fil *cpy, char buf[], ssize_t read_bytes)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	while (i < (int)read_bytes)
	{
		if (buf[i] == 35)
		{
			cpy->block_x[x++] = (i < 5) ? i : i % 5;
			cpy->block_y[y++] = i / 5;
		}
		i++;
	}
}

int			read_file(char buf[], int fd, t_fil **head)
{
	ssize_t	read_bytes;
	char	latter;
	int		count;
	ssize_t	tmp;

	count = 0;
	tmp = 0;
	latter = 'A';
	while ((read_bytes = read(fd, buf, BUF)) > 0)
	{
		count++;
		if (read_bytes < 20 || count > 26 ||
		get_valid_string(buf, read_bytes) == 0)
		{
			if (count > 1)
				lstclr(*head);
			return (0);
		}
		create_list(head, buf, latter++, read_bytes);
		tmp = read_bytes;
	}
	return ((count != 0) ? (int)tmp : 0);
}

int			display_error(void)
{
	ft_putendl("error");
	return (0);
}

int			main(int ac, char *av[])
{
	int			fd;
	char		buf[BUF];
	t_fil		*head;
	ssize_t		bytes;

	head = NULL;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			return (display_error());
		if ((bytes = read_file(buf, fd, &head)) > 0)
		{
			if (bytes == 21)
				return (display_error());
			get_least_square(head);
			close(fd);
		}
		else
			return (display_error());
	}
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}
