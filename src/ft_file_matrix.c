/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:07:00 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/13 19:41:59 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				ft_strdarrlen(char ***res)
{
	int			len;

	if (!res)
		return (0);
	len = 0;
	while (res[len])
		len = len + 1;
	return (len);
}

t_matrix		*ft_conv_iso(t_matrix *pt, t_mlx *ml)
{
	t_matrix		*res;
	t_matrix		*tmp;
	t_point			*sc;
	t_point			*tr;

	if (!pt || !ml || !(sc = ml->scale) || \
			!(tr = ml->tr))
		return (0);
	if (sc->x < 1 && sc->y < 1)
		sc->x = ml->line_size < 1000 ? 1000 / ml->line_size : 5;
	sc->y = sc->x / 1.5;
	if (sc->z < 1)
		sc->z = sc->x <= 10 ? sc->x : sc->x / 2;
	res = ft_scale(pt, sc->x, sc->y, sc->z);
	tmp = ft_rotatex(res, (M_PI * 35 / 180));
	ft_matrixdel(&res);
	res = ft_rotatey(tmp, (M_PI * 45 / 180));
	ft_matrixdel(&tmp);
	tmp = res;
	res = ft_rotatez(tmp, -(M_PI * 30 / 180));
	ft_matrixdel(&tmp);
	tmp = res;
	res = ft_translation(tmp, tr->x, tr->y, tr->z);
	ft_matrixdel(&tmp);
	return (res);
}

int				ft_conv_file_matrix(char *file, t_matrix **mt, \
		int *ln, int *rw)
{
	char		***res;
	int			k;
	int			i;
	int			j;
	int			ret;

	res = 0;
	ret = 0;
	if (!mt || ((ret = ft_parse_file(file, &res, ln)) <= 0) || \
			!(*rw = ft_strdarrlen(res)) || \
			!(*mt = ft_matrixnew(4, (*ln) * (*rw), 0)))
		return (ret);
	i = -1;
	k = 0;
	while (res[++i] && (j = -1))
	{
		while (res[i][++j] && ((*mt)->matrix[3][k] = 1))
		{
			(*mt)->matrix[0][k] = j;
			(*mt)->matrix[1][k] = i;
			(*mt)->matrix[2][k++] = ft_atoi(res[i][j]);
		}
	}
	ft_strdarrdel(&res);
	return (1);
}
