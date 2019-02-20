/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:56:55 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:46:01 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*str;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (!((start > 0 || start == 0) && start + len <= slen))
		return (NULL);
	if (len == 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * 1)))
			return (0);
		*str = '\0';
		return (str);
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
