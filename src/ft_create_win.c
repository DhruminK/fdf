/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:53:17 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/13 19:46:15 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx		*ft_mlx_init(int case_size, int z_size)
{
	t_mlx		*ml;

	if (!(ml = (t_mlx*)malloc(sizeof(t_mlx))))
		return (0);
	ml->mlx = mlx_init();
	ml->win = 0;
	ml->img = 0;
	ml->org = 0;
	ml->iso = 0;
	ml->line_size = 0;
	ml->row_size = 0;
	ml->scale = ft_ptnew(case_size, case_size, z_size);
	ml->tr = ft_ptnew(WIN_WIDTH / 5, WIN_HEIGHT / 3, 0);
	ml->o_pos = Top;
	ml->r = 0;
	return (ml);
}

void		ft_create_win(t_mlx *ml, int width_x, int width_y, char *name)
{
	if (!ml || !ml->mlx)
		return ;
	ml->win = mlx_new_window(ml->mlx, width_x, width_y, name);
}

t_img		*ft_create_img(t_mlx *ml, int width, int height)
{
	t_img		*img;

	if (!ml || !ml->mlx || !(img = (t_img*)malloc(sizeof(t_img))))
		return (0);
	if (!(img->img_ptr = mlx_new_image(ml->mlx, width, height)))
		return (0);
	img->img_data = (int*)mlx_get_data_addr(img->img_ptr, &(img->bpp), \
			&(img->size_l), &(img->endian));
	return (img);
}

void		ft_add_img(t_mlx *ml, t_img *img)
{
	if (ml && ml->mlx && ml->img)
	{
		mlx_destroy_image(ml->mlx, ml->img->img_ptr);
		free(ml->img);
	}
	if (ml && ml->mlx && img)
	{
		mlx_put_image_to_window(ml->mlx, ml->win, img->img_ptr, 0, 0);
		ml->img = img;
	}
}
