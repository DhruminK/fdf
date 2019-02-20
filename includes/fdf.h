/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:52:22 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/14 14:44:05 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "./get_next_line.h"
# include <math.h>
# include <fcntl.h>
# define WIN_WIDTH 1500
# define WIN_HEIGHT 1500

typedef struct		s_matrix
{
	double			**matrix;
	int				row;
	int				column;
}					t_matrix;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef enum		e_ortho { Top, Front, Side
}					t_ortho;

typedef struct		s_img
{
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				size_l;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_matrix		*org;
	t_matrix		*iso;
	int				line_size;
	int				row_size;
	t_point			*scale;
	t_point			*r;
	t_point			*tr;
	t_ortho			o_pos;
}					t_mlx;

/*
** MATRIX MANIPULATION FUNCTIONS
*/
t_matrix			*ft_matrixnew(int row, int column, int isiden);
void				ft_matrixdel(t_matrix **del);
void				ft_matrixdisp(t_matrix *ele);
t_matrix			*ft_matrix_add_sub(t_matrix *m1, t_matrix *m2, int type);
t_matrix			*ft_matrix_mult(t_matrix *m1, t_matrix *m2);

/*
** FUNCTIONS TO MANIPULATE 3D (USED ONLY FOR DRAWING LINE)
*/
t_point				*ft_ptnew(double x, double y, double z);
void				ft_ptdel(t_point **p);
void				ft_ptcpy(t_point *dst, t_point *src, int swap);
void				ft_ptswap(t_point *p1, t_point *p2);

/*
** FUNCTIONS TO DRAW POINTS FROM MATRIX
*/
int					ft_draw_matrix(t_matrix *pts, int row_size, \
		int line_size, t_img *img);

/*
** HOOK FUNCTIONS
*/
void				ft_scale_hook(t_mlx *ml, int up);
void				ft_trans_hook(t_mlx *ml, char dir);
void				ft_ortho_func(t_mlx *ml);
void				ft_iso_func(t_mlx *ml);

/*
** 3D POINT TRANSFORMATION FUNCTIONS
*/
t_matrix			*ft_translation(t_matrix *pt, int tx, int ty, int tz);
t_matrix			*ft_scale(t_matrix *pt, double sx, double sy, double sz);
t_matrix			*ft_rotatex(t_matrix *pt, double rd);
t_matrix			*ft_rotatey(t_matrix *pt, double rd);
t_matrix			*ft_rotatez(t_matrix *pt, double rd);

/*
** FILE PARSING FUNCTIONS
*/
void				ft_strdarrdel(char ****str);
int					ft_strarrlen(char **str);
int					ft_parse_file(char *file, char ****res, int *line_size);
t_matrix			*ft_conv_iso(t_matrix *pt, t_mlx *ml);
int					ft_conv_file_matrix(char *file, t_matrix **ml, \
		int *ln, int *rw);

/*
** MLX INIT FUNCTIONS
*/
t_mlx				*ft_mlx_init(int case_size, int z_size);
void				ft_create_win(t_mlx *ml, int width_x, \
		int width_y, char *name);
t_img				*ft_create_img(t_mlx *ml, int width, int height);
void				ft_add_img(t_mlx *ml, t_img *img);

#endif
