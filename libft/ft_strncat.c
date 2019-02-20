/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:05:05 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:40:20 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;

	len = ft_strlen(dest);
	while (*src != '\0' && n > 0)
	{
		*(dest + len) = *src;
		src = src + 1;
		len = len + 1;
		n = n - 1;
	}
	*(dest + len) = '\0';
	return (dest);
}
