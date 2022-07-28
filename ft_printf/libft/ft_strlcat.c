/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:07:39 by chukim            #+#    #+#             */
/*   Updated: 2021/12/14 17:08:04 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	count;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	count = 0;
	if (size < dst_len + 1)
		return (size + src_len);
	if (size > dst_len + 1)
	{
		while (src[count] && dst_len + count + 1 < size)
		{
			dst[dst_len + count] = src[count];
			count++;
		}
	}
	dst[dst_len + count] = '\0';
	return (dst_len + src_len);
}
