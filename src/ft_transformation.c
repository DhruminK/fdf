/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transformation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:07:18 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/12 18:23:10 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix			*ft_translation(t_matrix *pt, int tx, int ty, int tz)
{
	t_matrix		*tr;
	t_matrix		*res;

	if (!(tr = ft_matrixnew(4, 4, 1)))
		return (0);
	tr->matrix[0][3] = tx;
	tr->matrix[1][3] = ty;
	tr->matrix[2][3] = tz;
	res = ft_matrix_mult(tr, pt);
	ft_matrixdel(&tr);
	return (res);
}

t_matrix			*ft_scale(t_matrix *pt, double sx, double sy, double sz)
{
	t_matrix		*sc;
	t_matrix		*res;

	if (!(sc = ft_matrixnew(4, 4, 1)))
		return (0);
	sc->matrix[0][0] = sx;
	sc->matrix[1][1] = sy;
	sc->matrix[2][2] = sz;
	if (!(res = ft_matrix_mult(sc, pt)))
		return (0);
	ft_matrixdel(&sc);
	return (res);
}

t_matrix			*ft_rotatex(t_matrix *pt, double rd)
{
	t_matrix		*rx;
	t_matrix		*res;

	if (!(rx = ft_matrixnew(4, 4, 1)))
		return (0);
	rx->matrix[1][1] = cos(rd);
	rx->matrix[1][2] = (-1) * sin(rd);
	rx->matrix[2][1] = sin(rd);
	rx->matrix[2][2] = cos(rd);
	if (!(res = ft_matrix_mult(rx, pt)))
		return (0);
	ft_matrixdel(&rx);
	return (res);
}

t_matrix			*ft_rotatey(t_matrix *pt, double rd)
{
	t_matrix		*ry;
	t_matrix		*res;

	if (!(ry = ft_matrixnew(4, 4, 1)))
		return (0);
	ry->matrix[0][0] = cos(rd);
	ry->matrix[0][2] = sin(rd);
	ry->matrix[2][0] = (-1) * sin(rd);
	ry->matrix[2][2] = cos(rd);
	if (!(res = ft_matrix_mult(ry, pt)))
		return (0);
	ft_matrixdel(&ry);
	return (res);
}

t_matrix			*ft_rotatez(t_matrix *pt, double rd)
{
	t_matrix		*rz;
	t_matrix		*res;

	if (!(rz = ft_matrixnew(4, 4, 1)))
		return (0);
	rz->matrix[0][0] = cos(rd);
	rz->matrix[0][1] = (-1) * sin(rd);
	rz->matrix[1][0] = sin(rd);
	rz->matrix[1][1] = cos(rd);
	if (!(res = ft_matrix_mult(rz, pt)))
		return (0);
	ft_matrixdel(&rz);
	return (res);
}
