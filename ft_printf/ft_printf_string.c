/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:28:02 by chukim            #+#    #+#             */
/*   Updated: 2022/04/18 12:30:09 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(t_info *info, va_list ap)
{
	int			len;
	int			ret;
	const char	*s;

	ret = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (info->precision < len && info->precision > 0)
		len = info->precision;
	else if (info->precision == 0 || info->dot_only == ENABLE)
		len = 0;
	if (info->minus == DISABLE)
		while (len < (info->width)--)
			ret += write(1, " ", 1);
	ret += write(1, s, len);
	while (len < (info->width)--)
		ret += write(1, " ", 1);
	return (ret);
}
