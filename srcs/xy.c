/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:25:52 by elopez            #+#    #+#             */
/*   Updated: 2017/04/24 16:32:02 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static t_tet	*ft_findxy(t_tet *tetrimino)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	j = -1;
	x = -1;
	y = 0;
	while (tetrimino->str[++i])
	{
		++x;
		if (tetrimino->str[i] == '\n')
		{
			x = -1;
			++y;
		}
		if (tetrimino->str[i] == '#')
		{
			tetrimino->x[++j] = x;
			tetrimino->y[j] = y;
		}
	}
	return (tetrimino);
}

t_tet			*ft_set_xy(t_tet *tetrimino)
{
	t_tet	*tmp;

	tmp = tetrimino;
	while (tmp->next)
	{
		tmp = ft_findxy(tmp);
		ft_strdel(&tmp->str);
		tmp = tmp->next;
	}
	return (tetrimino);
}

t_tet			*ft_adjustxy(int x, int y, t_tet *tetrimino)
{
	int	i;
	int	xmin;
	int	ymin;

	xmin = 200;
	ymin = 200;
	i = 0;
	while (i < 4)
	{
		if (tetrimino->x[i] < xmin)
			xmin = tetrimino->x[i];
		if (tetrimino->y[i] < ymin)
			ymin = tetrimino->y[i];
		++i;
	}
	while (--i >= 0)
	{
		tetrimino->x[i] = tetrimino->x[i] - xmin + x;
		tetrimino->y[i] = tetrimino->y[i] - ymin + y;
	}
	return (tetrimino);
}

char			**ft_delete(char **tetris, t_tet *tetrimino, int size)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (tetris[y][x] == tetrimino->letter)
				tetris[y][x] = '.';
		}
	}
	return (tetris);
}
