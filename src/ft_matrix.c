/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:06:42 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/09 02:11:35 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix		*ft_matrixnew(int row, int column, int isiden)
{
	t_matrix		*ele;
	int				i;
	int				j;

	if (!(ele = (t_matrix*)malloc(sizeof(t_matrix))))
		return (0);
	ele->row = row;
	ele->column = column;
	ele->matrix = 0;
	if (!(ele->matrix = (double**)malloc(sizeof(double*) * (row))))
		return (ele);
	i = -1;
	while (++i < row)
		if (!((ele)->matrix[i] = (double*)malloc(sizeof(double) * (column))))
			return (0);
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < column)
			(ele)->matrix[i][j] = i == j && isiden ? 1 : 0;
	}
	return (ele);
}

void			ft_matrixdel(t_matrix **ele)
{
	int		i;

	if (!ele || !*ele)
		return ;
	if ((*ele)->matrix)
	{
		i = -1;
		while (++i < (*ele)->row)
			if ((*ele)->matrix[i])
				free((*ele)->matrix[i]);
		free((*ele)->matrix);
	}
	(*ele)->row = 0;
	(*ele)->column = 0;
	free(*ele);
	*ele = 0;
}

void			ft_matrixdisp(t_matrix *ele)
{
	int			i;
	int			j;

	if (!ele)
		return ;
	i = -1;
	while (++i < ele->row && (j = -1))
	{
		while (++j < ele->column)
		{
			ft_putnbr((int)floor(ele->matrix[i][j]));
			ft_putstr(" ");
		}
		ft_putendl("");
	}
}
