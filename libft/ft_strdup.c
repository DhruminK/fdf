/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:54:17 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:38:35 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dup;
	int		i;

	len = ft_strlen(src);
	dup = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!dup)
		return (0);
	while (*(src + i) != '\0')
	{
		*(dup + i) = *(src + i);
		i = i + 1;
	}
	*(dup + i) = '\0';
	return (dup);
}
