/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:06:34 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:45:15 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	i = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		*(str + i) = f(*(s + i));
		i = i + 1;
	}
	*(str + i) = '\0';
	return (str);
}
