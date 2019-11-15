/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_addlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:57:13 by dshala            #+#    #+#             */
/*   Updated: 2019/10/03 16:04:08 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*gnl_addlist(t_gnl **head, t_gnl *new, int const fd)
{
	new->fd_gnl = fd;
	new->str = NULL;
	new->next = *head;
	*head = new;
	return (*head);
}
