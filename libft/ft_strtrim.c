/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:16:41 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:47:02 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_ws(char s)
{
	return (s == ' ' || s == '\t' || s == '\n' ? 1 : 0);
}

static char	*ft_transfer(char const *s, int start, int end)
{
	char	*str;
	size_t	i;

	if (start >= end)
	{
		str = (char*)malloc(sizeof(char) * 1);
		if (!str)
			return (0);
		*str = '\0';
		return (str);
	}
	str = (char*)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	i = 0;
	while (start <= end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			k;
	size_t			len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!len)
		return (ft_transfer(s, 0, 0));
	i = 0;
	k = len - 1;
	while (1 == 1)
	{
		if (!ft_is_ws(s[i]) && !ft_is_ws(s[k]))
			break ;
		i = ft_is_ws(s[i]) ? i + 1 : i;
		k = ft_is_ws(s[k]) ? k - 1 : k;
	}
	return (ft_transfer(s, i, k));
}
