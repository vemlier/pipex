/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:07:10 by chukim            #+#    #+#             */
/*   Updated: 2022/04/18 13:17:57 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_info *info, va_list ap)
{
	int		ret;
	char	c;

	ret = 0;
	if (info->minus == DISABLE)
	{
		while (--(info->width) > 0)
			ret += write(1, " ", 1);
	}
	c = (unsigned char)va_arg(ap, int);
	ret += write(1, &c, 1);
	while (--(info->width) > 0)
		ret += write(1, " ", 1);
	return (ret);
}

int	ft_print_percent(t_info *info)
{
	int		ret;

	ret = 0;
	if (info->minus == DISABLE && info->zero == DISABLE)
	{
		while (--(info->width) > 0)
			ret += write(1, " ", 1);
	}
	if (info->minus == DISABLE && info->zero == ENABLE)
	{
		while (--(info->width) > 0)
			ret += write(1, "0", 1);
	}
	ret += write(1, "%", 1);
	while (--(info->width) > 0)
		ret += write(1, " ", 1);
	return (ret);
}
