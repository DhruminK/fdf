/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:52:47 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:38:50 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i = i + 1;
	}
	while (i < len)
	{
		*(dest + i) = '\0';
		i = i + 1;
	}
	return (dest);
}
