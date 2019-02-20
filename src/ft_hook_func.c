/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:01:49 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/20 15:28:31 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_scale_hook(t_mlx *ml, int up)
{
	double		inc;
	t_img		*img;

	inc = 0.5 * (up ? 1 : -1);
	if (!up && (ml->scale->x <= 1 || ml->scale->y <= 1 || ml->scale->z <= 1))
		return ;
	ml->scale->x = ml->scale->x + inc;
	ml->scale->y = ml->scale->y + inc;
	ml->scale->z = ml->scale->z + inc;
	img = ft_create_img(ml, WIN_WIDTH, WIN_HEIGHT);
	ft_matrixdel(&(ml->iso));
	ml->iso = ft_conv_iso(ml->org, ml);
	ft_draw_matrix(ml->iso, ml->row_size, ml->line_size, img);
	ft_add_img(ml, img);
}

void			ft_trans_hook(t_mlx *ml, char dir)
{
	double		inc;
	t_img		*img;

	inc = 20;
	if (dir == 0b0001)
		ml->tr->x = ml->tr->x + inc;
	if (dir == 0b1000)
		ml->tr->x = ml->tr->x - inc;
	if (dir == 0b0100)
		ml->tr->y = ml->tr->y + inc;
	if (dir == 0b0010)
		ml->tr->y = ml->tr->y - inc;
	img = ft_create_img(ml, WIN_WIDTH, WIN_HEIGHT);
	ft_matrixdel(&(ml->iso));
	ml->iso = ft_conv_iso(ml->org, ml);
	ft_draw_matrix(ml->iso, ml->row_size, ml->line_size, img);
	ft_add_img(ml, img);
}

void			ft_ortho_func(t_mlx *ml)
{
	t_matrix	*res;
	t_matrix	*tmp;
	t_matrix	*tmp1;
	t_img		*img;

	if (!(img = ft_create_img(ml, WIN_WIDTH, WIN_HEIGHT)))
		return ;
	if (ml->o_pos == Top)
		tmp1 = ml->org;
	else if (ml->o_pos == Front)
		tmp1 = ft_rotatex(ml->org, (M_PI / 2));
	else
		tmp1 = ft_rotatey(ml->org, (M_PI / 2));
	tmp = ft_scale(tmp1, ml->scale->x, ml->scale->y, ml->scale->z);
	if (tmp1 != ml->org)
		ft_matrixdel(&tmp1);
	res = ft_translation(tmp, ml->tr->x, ml->tr->y, ml->tr->z);
	ft_matrixdel(&(tmp));
	ft_draw_matrix(res, ml->row_size, ml->line_size, img);
	ft_add_img(ml, img);
	ft_matrixdel(&res);
	ml->o_pos = (ml->o_pos + 1) % 3;
}

void			ft_iso_func(t_mlx *ml)
{
	t_img		*img;

	if (!(img = ft_create_img(ml, WIN_WIDTH, WIN_HEIGHT)))
		return ;
	ft_draw_matrix(ml->iso, ml->row_size, ml->line_size, img);
	ft_add_img(ml, img);
}
