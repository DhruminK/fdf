/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:15:27 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/29 11:36:56 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (0);
	len1 = s1 ? ft_strlen(s1) : 0;
	len2 = s2 ? ft_strlen(s2) : 0;
	i = 0;
	j = 0;
	s = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (0);
	while (i < len1)
		*(s + j++) = *(s1 + i++);
	i = 0;
	while (i < len2)
		*(s + j++) = *(s2 + i++);
	*(s + j) = '\0';
	return (s);
}
