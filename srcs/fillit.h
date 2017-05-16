/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:02:25 by elopez            #+#    #+#             */
/*   Updated: 2017/04/24 16:49:40 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

typedef struct	s_tet
{
	int				x[4];
	int				y[4];
	char			*str;
	char			letter;
	struct s_tet	*next;
}				t_tet;

void			ft_error(void);
char			*ft_read_file(char *file);
t_tet			*ft_store_strings(char *long_str);
int				ft_amountcheck(char *str);
void			ft_strcheck(char *str);
t_tet			*ft_set_xy(t_tet *tetrimino);
char			**ft_solve(t_tet *tetrimino, int size);
t_tet			*ft_adjustxy(int x, int y, t_tet *tetrimino);
char			**ft_delete(char **tetris, t_tet *tetrimino, int size);

#endif
