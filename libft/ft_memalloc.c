/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:51:28 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:06:38 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (size == (size_t)-1 || size == 0)
		return (NULL);
	if (!(tmp = (void*)malloc(size)))
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
