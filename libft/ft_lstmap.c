/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:47:41 by dkhatri           #+#    #+#             */
/*   Updated: 2018/11/22 17:40:29 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ele;
	t_list	*new_list;
	t_list	*head;

	if (!lst || !f)
		return (0);
	ele = f(lst);
	if (!(new_list = ft_lstnew(ele->content, ele->content_size)))
		return (0);
	lst = lst->next;
	head = new_list;
	while (lst)
	{
		ele = f(lst);
		if (!(new_list->next = ft_lstnew(ele->content, ele->content_size)))
			return (0);
		lst = lst->next;
		new_list = new_list->next;
	}
	return (head);
}
