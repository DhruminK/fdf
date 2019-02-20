/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:40:18 by dkhatri           #+#    #+#             */
/*   Updated: 2019/02/12 18:28:42 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				ft_strarrlen(char **str)
{
	int			len;

	len = 0;
	while (str[len])
		len = len + 1;
	return (len);
}

int				ft_strdarradd(char ****res, char **str)
{
	char		***s;
	int			len;

	if (!res || !str)
		return (0);
	len = 0;
	if (*res)
		while ((*res)[len])
			len = len + 1;
	if (!(s = (char***)malloc(sizeof(char**) * (len + 2))))
		return (0);
	s[len + 1] = 0;
	s[len] = str;
	while (--len >= 0)
		s[len] = (*res)[len];
	if (*res)
		free(*res);
	*res = s;
	return (1);
}

void			ft_strdarrdel(char ****res)
{
	char		***tmp;
	int			i;

	if (!res || !*res)
		return ;
	tmp = *res;
	i = 0;
	while (*tmp)
		ft_strarrdel(tmp++);
	free(*res);
	*res = 0;
}

int				ft_parse_file(char *file, char ****res, int *line_size)
{
	int			fd;
	char		*line;
	int			ret;
	char		**split;

	if (!res)
		return (0);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		split = ft_strsplit(line, ' ');
		*line_size = *line_size <= 0 ? ft_strarrlen(split) : *line_size;
		if (*line_size != ft_strarrlen(split))
			return (-2);
		ft_strdel(&line);
		if (!ft_strdarradd(res, split))
			return (0);
	}
	if (ret == -1)
		return (0);
	return (1);
}
