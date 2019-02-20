/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:13:33 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/24 19:24:25 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*head;
	void	*dup;

	head = (t_list*)malloc(sizeof(t_list) * 1);
	if (!head)
		return (0);
	if (!content)
	{
		head->content = 0;
		head->content_size = 0;
		head->next = NULL;
		return (head);
	}
	dup = malloc(content_size);
	if (!dup)
		return (0);
	ft_memcpy(dup, (void*)content, content_size);
	head->content = dup;
	head->content_size = content_size;
	head->next = NULL;
	return (head);
}
