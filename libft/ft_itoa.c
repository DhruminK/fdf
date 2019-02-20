/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:01:04 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/19 17:18:37 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_getnbrlen(int n)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len = len + 1;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	int		rem;
	int		nbrlen;
	char	*str;

	nbrlen = ft_getnbrlen(n);
	len = nbrlen;
	if (n < 0)
		len = len + 1;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	while (nbrlen-- > 0)
	{
		rem = n % 10;
		rem = rem < 0 ? rem * -1 : rem;
		str[len--] = (rem + '0');
		n = n / 10;
	}
	str[len] = len == 0 ? '-' : str[len];
	return (str);
}
