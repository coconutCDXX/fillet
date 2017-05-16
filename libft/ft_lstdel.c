/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:36:03 by elopez            #+#    #+#             */
/*   Updated: 2017/04/24 16:36:06 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*lst;

	if (alst == NULL)
		return ;
	lst = *alst;
	while (lst != NULL)
	{
		tmp = lst->next;
		ft_lstdelone(&lst, del);
		lst = tmp;
	}
	*alst = NULL;
}
