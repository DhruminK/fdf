/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:50:44 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:44:01 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int n_len;

	if (!*needle)
		return ((char*)haystack);
	n_len = ft_strlen(needle);
	while (*haystack != '\0')
	{
		if (ft_strncmp(needle, haystack, n_len) == 0)
			return ((char*)haystack);
		haystack = haystack + 1;
	}
	return (0);
}
