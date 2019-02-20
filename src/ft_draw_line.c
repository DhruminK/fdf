/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:59:36 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/14 14:46:56 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void				ft_plot(t_point p, t_img *img)
{
	if (!img || p.x < 0 || p.y < 0 || p.x > WIN_WIDTH || p.y > WIN_HEIGHT || \
			(p.y * img->size_l / 4) + p.x >= WIN_WIDTH * WIN_HEIGHT)
		return ;
	img->img_data[(((int)floor(p.y)) * (img->size_l / 4)) + \
		((int)floor(p.x))] = 0xFFFFFF;
}

static void				ft_draw_line(t_point *p1, t_point *p2, t_img *img)
{
	t_point		tmp;
	t_point		t1;
	double		gradient;
	int			steep;

	steep = fabs(p2->y - p1->y) > fabs(p2->x - p1->x);
	if (steep)
	{
		ft_ptcpy(p1, p1, 1);
		ft_ptcpy(p2, p2, 1);
	}
	if (p2->x < p1->x)
		ft_ptswap(p1, p2);
	ft_ptcpy(&tmp, p1, 0);
	gradient = p2->x - p1->x == 0 ? 1 : (p2->y - p1->y) / (p2->x - p1->x);
	while (tmp.x <= p2->x)
	{
		ft_ptcpy(&t1, &tmp, steep);
		t1.y = t1.y + 1;
		ft_plot(t1, img);
		tmp.y = tmp.y + gradient;
		tmp.x = tmp.x + 1;
	}
}

static int				ft_to_point(double **pts, int i, int j, t_img *img)
{
	t_point		*p1;
	t_point		*p2;

	if (!img || !pts || !(p1 = ft_ptnew(pts[0][i], pts[1][i], pts[2][i])) ||
			!(p2 = ft_ptnew(pts[0][j], pts[1][j], pts[2][j])))
		return (0);
	ft_draw_line(p1, p2, img);
	ft_ptdel(&p1);
	ft_ptdel(&p2);
	return (1);
}

int						ft_draw_matrix(t_matrix *pts, int row_size, \
		int line_size, t_img *img)
{
	long int		i;

	i = -1;
	if (!img)
		return (0);
	while (++i < pts->column)
	{
		if (i % line_size != line_size - 1)
			if (!(ft_to_point(pts->matrix, i, i + 1, img)))
				return (0);
		if (i / line_size < row_size - 1)
			if (!(ft_to_point(pts->matrix, i, i + line_size, img)))
				return (0);
	}
	return (1);
}
