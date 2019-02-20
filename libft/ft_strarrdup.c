/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:23:14 by dkhatri           #+#    #+#             */
/*   Updated: 2018/12/20 20:18:35 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		**ft_strarrdup(char **str, size_t size)
{
	char	**dup;
	size_t	i;

	if (!str || !*str)
		return (0);
	if (!(dup = malloc(sizeof(char*) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		dup[i] = ft_strndup(str[i], size);
		i = i + 1;
	}
	dup[i] = 0;
	return (dup);
}
