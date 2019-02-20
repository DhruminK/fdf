/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:57:40 by dkhatri           #+#    #+#             */
/*   Updated: 2018/12/18 16:58:38 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstfindsize(t_list *head)
{
	int count;

	count = 0;
	while (head)
	{
		count = count + 1;
		head = head->next;
	}
	return (count);
}
