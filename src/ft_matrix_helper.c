/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:16:46 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/07 17:34:19 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix		*ft_matrix_add_sub(t_matrix *m1, t_matrix *m2, int type)
{
	t_matrix		*res;
	int				i;
	int				j;
	int				ret;

	if (m1->row != m2->row || m1->column != m2->column)
		return (0);
	if (!(res = ft_matrixnew(m1->row, m1->column, 0)))
		return (0);
	i = -1;
	while (++i < m1->row)
	{
		j = -1;
		while (++j < m1->column)
		{
			ret = m2->matrix[i][j];
			if (type)
				ret = ret * -1;
			res->matrix[i][j] = m1->matrix[i][j] + ret;
		}
	}
	return (res);
}

t_matrix		*ft_matrix_mult(t_matrix *m1, t_matrix *m2)
{
	t_matrix		*res;
	int				i;
	int				j;
	int				k;

	if (m1->column != m2->row)
		return (0);
	if (!(res = ft_matrixnew(m1->row, m2->column, 0)))
		return (0);
	i = -1;
	while (++i < m1->row)
	{
		j = -1;
		while (++j < m2->column)
		{
			k = -1;
			while (++k < m1->column)
				res->matrix[i][j] += \
									(m1->matrix[i][k] * m2->matrix[k][j]);
		}
	}
	return (res);
}
