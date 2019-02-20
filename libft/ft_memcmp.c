/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:15:23 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:38:14 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			i;

	st1 = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*(st1 + i) != *(st2 + i))
			return (*(st1 + i) - *(st2 + i));
		i = i + 1;
	}
	return (0);
}
