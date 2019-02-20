/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:38:43 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:41:20 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		len_d;
	size_t		i;
	size_t		n;
	const char	*s;

	len_d = ft_strlen(dest);
	if (len_d >= size)
		return (size + ft_strlen(src));
	n = size - len_d;
	i = len_d;
	s = src;
	while (*src != '\0')
	{
		if (n != 1)
		{
			*(dest + i) = *src;
			i = i + 1;
			n = n - 1;
		}
		src = src + 1;
	}
	*(dest + i) = '\0';
	return (len_d + (src - s));
}
