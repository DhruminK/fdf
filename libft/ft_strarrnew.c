/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:02:41 by dkhatri           #+#    #+#             */
/*   Updated: 2018/12/28 18:55:18 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strarrnew(size_t size)
{
	size_t		i;
	char		**str;

	i = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	while (i < size)
		str[i++] = ft_strnew(size);
	str[i] = 0;
	return (str);
}
