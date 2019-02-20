/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:33:22 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:53:36 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		n_len;
	size_t	i;

	if (*needle == '\0')
		return ((char*)haystack);
	n_len = ft_strlen(needle);
	i = 0;
	while (*haystack != '\0' && (n_len + i) <= len)
	{
		if (ft_strncmp(haystack, needle, n_len) == 0)
			return ((char*)haystack);
		haystack = haystack + 1;
		i = i + 1;
	}
	return (0);
}
