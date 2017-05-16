/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:10:45 by elopez            #+#    #+#             */
/*   Updated: 2017/04/24 16:55:18 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

static int	ft_gridsize(t_tet *tetrimino)
{
	int	size;
	int	i;

	i = 0;
	size = 2;
	while (tetrimino->next)
	{
		++i;
		tetrimino = tetrimino->next;
	}
	while (size * size < i * 4)
		++size;
	return (size);
}

char		*ft_read_file(char *file)
{
	int		fd;
	int		bytes_read;
	char	tmp[545];
	char	buffer[1];
	int		i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while ((bytes_read = read(fd, buffer, 1)))
		tmp[i++] = buffer[0];
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_error();
	return (ft_strdup(tmp));
}

t_tet		*ft_store_strings(char *long_str)
{
	t_tet	*tmp;
	t_tet	*tetrimino;
	int		i;
	int		j;
	char	ltr;

	ltr = 64;
	j = 0;
	i = ft_amountcheck(long_str);
	if (!(tetrimino = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	tmp = tetrimino;
	while (--i >= 0)
	{
		tmp->str = ft_strncpy(ft_strnew(20), &long_str[j], 20);
		ft_strcheck(tmp->str);
		tmp->letter = ++ltr;
		j += 21;
		if (!(tmp->next = (t_tet*)malloc(sizeof(t_tet))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	ft_strdel(&long_str);
	return (tetrimino);
}

int			main(int argc, char **argv)
{
	t_tet	*tetrimino;
	char	*long_str;
	char	**tetris;

	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (-1);
	}
	long_str = ft_read_file(argv[1]);
	tetrimino = ft_store_strings(long_str);
	tetrimino = ft_set_xy(tetrimino);
	tetris = ft_solve(tetrimino, ft_gridsize(tetrimino));
	free(tetrimino);
	while (*tetris)
		ft_putendl(*tetris++);
	return (0);
}
