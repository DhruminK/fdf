/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:56:07 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/26 12:48:26 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_all_delimit(char const *str, char del)
{
	int		word;
	int		was_del;
	int		temp;

	word = 0;
	was_del = 1;
	while (*str != '\0')
	{
		temp = (*str == del);
		if (temp == 1 && was_del == 0)
		{
			word = word + 1;
			was_del = 1;
		}
		else if (temp == 0)
			was_del = 0;
		else if (temp == 1)
			was_del = 1;
		str = str + 1;
	}
	if (was_del == 0)
		word = word + 1;
	return (word);
}

static char		*ft_dup(char const *start, char const *end)
{
	char	*s;
	int		i;

	if (!(s = malloc(sizeof(char) * (end - start + 1))))
		return (0);
	i = 0;
	while (start != end)
	{
		*(s + i) = *start;
		start = start + 1;
		i = i + 1;
	}
	*(s + i) = '\0';
	return (s);
}

static int		ft_transfer(char **arr, char const *str, char c)
{
	char const	*start;
	int			len;
	int			i;

	start = str;
	len = 0;
	i = 0;
	while (*str != '\0')
	{
		if (*(str++) == c)
		{
			if (!(arr[i++] = ft_dup(start, --str)))
				return (0);
			while (*str != '\0' && *(str) == c)
				str = str + 1;
			if (*str == '\0' && (len = 1) == 1)
				break ;
			start = str;
		}
	}
	if (len == 0)
		if (!(arr[i++] = ft_dup(start, str)))
			return (0);
	arr[i] = 0;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		len;

	if (!s)
		return (0);
	while (*s == c)
		s = s + 1;
	len = ft_find_all_delimit(s, c);
	arr = malloc(sizeof(char*) * (len + 1));
	if (!arr)
		return (0);
	if (len == 0)
		*arr = 0;
	else
	{
		if (!(ft_transfer(arr, s, c)))
			return (0);
	}
	return (arr);
}
