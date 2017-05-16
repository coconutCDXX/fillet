/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:17:41 by elopez            #+#    #+#             */
/*   Updated: 2017/04/24 17:01:03 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static char	**ft_dots(char **tetris, int size)
{
	int	x;
	int	y;

	y = 0;
	if (!(tetris = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		tetris[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			tetris[y][x] = '.';
			++x;
		}
		++y;
	}
	tetris[y] = NULL;
	return (tetris);
}

static char	**ft_save(int size, char **tetris, t_tet *tetrimino)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetrimino->x[i] == x && tetrimino->y[i] == y)
			{
				tetris[y][x] = tetrimino->letter;
				++i;
			}
			++x;
		}
		tetris[y][x] = '\0';
		++y;
	}
	return (tetris);
}

static int	ft_checkspot(int size, char **tetris, t_tet *tetrimino)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetrimino->x[i] == x && tetrimino->y[i] == y &&
					tetris[y][x] == '.')
				++i;
			if (i == 4)
				return (1);
			++x;
		}
		++y;
	}
	return (0);
}

static char	**ft_putpieces(char **tetris, t_tet *tetrimino, int size)
{
	int		x;
	int		y;
	char	**tmp;

	y = -1;
	if (!tetrimino->next)
		return (tetris);
	tmp = NULL;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			tetrimino = ft_adjustxy(x, y, tetrimino);
			if (ft_checkspot(size, tetris, tetrimino))
			{
				tetris = ft_save(size, tetris, tetrimino);
				tmp = ft_putpieces(tetris, tetrimino->next, size);
			}
			if (tmp)
				return (tmp);
			tetris = ft_delete(tetris, tetrimino, size);
		}
	}
	return (NULL);
}

char		**ft_solve(t_tet *tetrimino, int size)
{
	char	**tetris;

	tetris = NULL;
	while (!tetris)
	{
		tetris = ft_dots(tetris, size);
		tetris = ft_putpieces(tetris, tetrimino, size);
		++size;
	}
	return (tetris);
}
