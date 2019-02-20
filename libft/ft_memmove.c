/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:23:31 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:32:23 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	direction;
	size_t	i;
	char	*d;
	char	*s;

	s = (char*)src;
	d = (char*)dst;
	direction = 1;
	if (s < d && (s + len) > d)
	{
		direction = -1;
		s = s + len - 1;
		d = d + len - 1;
	}
	i = 0;
	while (i < len)
	{
		*d = *s;
		s = s + direction;
		d = d + direction;
		i = i + 1;
	}
	return (dst);
}
