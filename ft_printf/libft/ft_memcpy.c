/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:24:19 by chukim            #+#    #+#             */
/*   Updated: 2021/12/14 17:02:47 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if ((unsigned char *)dst == (unsigned char *)src)
		return (dst);
	while (count < n)
	{
		((unsigned char *)dst)[count] = ((unsigned char *)src)[count];
		count++;
	}
	return (dst);
}
