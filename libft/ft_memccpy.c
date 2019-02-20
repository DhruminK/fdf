/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:28:18 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:31:52 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dest;
	char	*sr;
	size_t	i;

	dest = (char*)dst;
	sr = (char*)src;
	i = 0;
	while (i < n)
	{
		*(dest + i) = *(sr + i);
		if (*(dest + i) == (char)c)
			return (dest + i + 1);
		i = i + 1;
	}
	return (0);
}
