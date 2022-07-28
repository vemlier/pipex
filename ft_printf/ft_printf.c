/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:09:11 by chukim            #+#    #+#             */
/*   Updated: 2022/05/11 09:06:44 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_info *info)
{
	info->minus = DISABLE;
	info->zero = DISABLE;
	info->dot_only = DISABLE;
	info->locass = DISABLE;
	info->address = DISABLE;
	info->width = -1;
	info->precision = -1;
	info->num_base = 10;
	info->num_sign = 0;
}

int	ft_parse(const char *format, va_list ap)
{
	t_info	info;
	int		ret;

	ret = 0;
	while (*format != 0)
	{
		init_struct(&info);
		if (*format == '%')
		{
			format++;
			ft_parse_flag(&format, &info);
			ft_parse_width(&format, &info, ap);
			ft_parse_precision(&format, &info, ap);
			ret += ft_parse_type(&info, ap, *format);
		}
		else
			ret += write(1, format, 1);
		format++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_parse(format, ap);
	va_end(ap);
	return (ret);
}
