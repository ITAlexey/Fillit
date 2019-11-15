/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:10:00 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 15:07:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_words(const char *str, int c)
{
	unsigned char	*tmp;
	unsigned char	ch;
	size_t			count;

	count = 0;
	if (!str)
		return (count);
	ch = (unsigned char)c;
	while (*str)
	{
		if (*str != c)
		{
			tmp = (unsigned char*)str;
			while (*tmp != c && *tmp)
				tmp++;
			count++;
			tmp--;
			str = (char *)tmp;
		}
		str++;
	}
	return (count);
}
