/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:06:46 by dkhatri           #+#    #+#             */
/*   Updated: 2018/12/20 18:32:36 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strndup(char *str, size_t size)
{
	char	*dup;
	size_t	i;

	if (!(dup = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		dup[i] = str[i];
		i = i + 1;
	}
	dup[i] = '\0';
	return (dup);
}
