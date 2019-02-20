/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:28:33 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/14 14:45:40 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int			ft_close(void *param)
{
	t_mlx		*ml;

	if (!param || !(ml = (t_mlx*)param))
		exit(0);
	ft_add_img(ml, 0);
	if (ml->win)
		mlx_clear_window(ml->mlx, ml->win);
	ft_matrixdel(&(ml->org));
	ft_matrixdel(&(ml->iso));
	if (ml->mlx)
		free(ml->mlx);
	free(ml);
	exit(0);
	return (0);
}

int			ft_puterror(t_mlx *ml, char *msg)
{
	ft_putendl(msg);
	if (ml)
		ft_close(ml);
	return (0);
}

int			ft_handle_key(int keycode, void *param)
{
	t_mlx	*ml;

	ml = (t_mlx*)param;
	if (keycode == 53)
		ft_close(ml);
	if (keycode == 6 || keycode == 7)
		ft_scale_hook(ml, keycode == 6);
	if (keycode == 124 || keycode == 123)
		ft_trans_hook(ml, keycode == 124 ? 0b0001 : 0b1000);
	if (keycode == 126 || keycode == 125)
		ft_trans_hook(ml, keycode == 126 ? 0b0010 : 0b0100);
	if (keycode == 35)
		ft_ortho_func(ml);
	if (keycode == 34)
		ft_iso_func(ml);
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx		*ml;
	t_img		*img;
	char		*msg;

	msg = "Usage : ./fdf filename [ case_size z_size ]";
	if (ac != 2 && ac != 4)
		return (ft_puterror(0, msg));
	if (!(ml = ft_mlx_init(ac == 4 ? ft_atoi(av[2]) : 0, \
					ac == 4 ? ft_atoi(av[3]) : 0)))
		return (ft_puterror(0, "Error"));
	if ((ft_conv_file_matrix(av[1], &(ml->org), \
					&(ml->line_size), &(ml->row_size))) <= 0)
		return (ft_puterror(ml, "Error"));
	ml->iso = ft_conv_iso(ml->org, ml);
	ft_create_win(ml, WIN_WIDTH, WIN_HEIGHT, "FDF");
	img = ft_create_img(ml, WIN_WIDTH, WIN_HEIGHT);
	if (!(ft_draw_matrix(ml->iso, ml->row_size, ml->line_size, img)))
		return (ft_puterror(ml, "Error"));
	ft_add_img(ml, img);
	mlx_hook(ml->win, 17, 0, &ft_close, ml);
	mlx_key_hook(ml->win, &ft_handle_key, ml);
	mlx_loop(ml);
	return (0);
}
