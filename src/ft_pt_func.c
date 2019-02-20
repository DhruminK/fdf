/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pt_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:54:53 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/13 17:46:05 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		*ft_ptnew(double x, double y, double z)
{
	t_point		*p;

	if (!(p = (t_point*)malloc(sizeof(t_point))))
		return (0);
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

void		ft_ptdel(t_point **p)
{
	if (!p || !*p)
		return ;
	(*p)->x = 0;
	(*p)->y = 0;
	(*p)->z = 0;
	free(*p);
	*p = 0;
}

void		ft_ptcpy(t_point *dst, t_point *src, int swap)
{
	t_point		tmp;

	if (!dst || !src)
		return ;
	tmp.x = swap ? src->y : src->x;
	tmp.y = swap ? src->x : src->y;
	dst->x = tmp.x;
	dst->y = tmp.y;
}

void		ft_ptswap(t_point *p1, t_point *p2)
{
	t_point tmp;

	if (!p1 || !p2)
		return ;
	ft_ptcpy(&tmp, p1, 0);
	ft_ptcpy(p1, p2, 0);
	ft_ptcpy(p2, &tmp, 0);
}
