/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:25:30 by dkhatri           #+#    #+#             */
/*   Updated: 2018/12/18 17:47:08 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list		*ele;

	if (alst && new)
	{
		if (!*alst)
		{
			*alst = new;
			return ;
		}
		ele = *alst;
		while (ele->next)
			ele = ele->next;
		ele->next = new;
	}
}
