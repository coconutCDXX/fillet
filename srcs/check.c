/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:56:10 by elopez            #+#    #+#             */
/*   Updated: 2017/04/24 18:31:04 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			ft_amountcheck(char *str)
{
	int nl;
	int dots;
	int hash;
	int i;

	i = 0;
	dots = 0;
	nl = 0;
	hash = 0;
	while (str[i])
	{
		if (str[i] == '.')
			++dots;
		if (str[i] == '\n')
			++nl;
		if (str[i] == '#')
			++hash;
		++i;
	}
	if (dots % 12 || (nl + 1) % 5 || hash % 4 ||
			hash == 0 || (dots / 12 != hash / 4))
		ft_error();
	return (hash / 4);
}

static int	ft_connect(char *s, int i, int connect)
{
	while (s[i] == '#')
	{
		s[i] = '*';
		if (i < 19 && s[i + 1] == '#')
			ft_connect(s, i + 1, connect);
		if (i < 15 && s[i + 5] == '#')
			ft_connect(s, i + 5, connect);
		if (i > 0 && s[i - 1] == '#')
			ft_connect(s, i - 1, connect);
		if (i > 4 && s[i - 5] == '#')
			ft_connect(s, i - 5, connect);
	}
	i = -1;
	while (s[++i])
		if (s[i] == '*')
			++connect;
	return (connect);
}

void		ft_strcheck(char *str)
{
	int		i;
	int		connect;
	char	*cpy;

	connect = 0;
	i = 0;
	cpy = ft_strnew(20);
	ft_strcpy(cpy, str);
	while (cpy[i])
	{
		if (cpy[i] == '\n')
			if ((i + 1) % 5)
				ft_error();
		++i;
	}
	i = 0;
	while (cpy[i] != '#')
		++i;
	connect = ft_connect(cpy, i, connect);
	ft_strdel(&cpy);
	if (connect != 4)
		ft_error();
}
