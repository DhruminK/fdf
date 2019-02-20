/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:47:41 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/24 20:33:11 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char*)src;
	d = (char*)dst;
	i = 0;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i = i + 1;
	}
	return (dst);
}
