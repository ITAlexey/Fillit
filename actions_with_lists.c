/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_with_lists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <dshala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:13:55 by dshala            #+#    #+#             */
/*   Updated: 2019/11/15 03:13:30 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		lstcount(t_fil *head)
{
	int		i;
	t_fil	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	align_tetramine(t_fil *list)
{
	while (list->block_x[0] != 0 && list->block_x[1] != 0
	&& list->block_x[2] != 0 && list->block_x[3] != 0)
	{
		list->block_x[0] -= 1;
		list->block_x[1] -= 1;
		list->block_x[2] -= 1;
		list->block_x[3] -= 1;
	}
	while (list->block_y[0] != 0 && list->block_y[1] != 0
	&& list->block_y[2] != 0 && list->block_y[3] != 0)
	{
		list->block_y[0] -= 1;
		list->block_y[1] -= 1;
		list->block_y[2] -= 1;
		list->block_y[3] -= 1;
	}
}

void	pushback(t_fil **head, t_fil *new)
{
	t_fil	*tmp;

	tmp = *head;
	if (*head != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*head = new;
}

void	lstclr(t_fil *head)
{
	t_fil	*del;

	while (head)
	{
		del = head->next;
		free(head);
		head = del;
	}
}

void	create_list(t_fil **head, char buf[], char latter, ssize_t read_bytes)
{
	t_fil	*cpy;

	cpy = (t_fil*)malloc(sizeof(t_fil));
	record_position(cpy, buf, read_bytes);
	cpy->latter = latter;
	cpy->next = NULL;
	align_tetramine(cpy);
	pushback(head, cpy);
}
