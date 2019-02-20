/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:02:33 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:40:07 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		len;

	len = ft_strlen(dest);
	while (*src != '\0')
	{
		*(dest + len) = *src;
		src = src + 1;
		len = len + 1;
	}
	*(dest + len) = '\0';
	return (dest);
}
