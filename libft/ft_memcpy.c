/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:05:57 by elopez            #+#    #+#             */
/*   Updated: 2017/03/21 19:35:49 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *pre_dst;

	pre_dst = (unsigned char*)dst;
	while (n > 0)
	{
		*pre_dst++ = *(unsigned char*)src++;
		n--;
	}
	return (dst);
}
