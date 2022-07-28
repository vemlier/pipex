/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:26:52 by chukim            #+#    #+#             */
/*   Updated: 2022/04/18 13:16:38 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_putchar_len(char c, int *len)
{
	int	i;

	i = 0;
	while ((*len)-- > 0)
		i += write(1, &c, 1);
	return (i);
}

int	num_itoa(t_info *info, char *num_box, unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		num_box[len++] = '0';
	else
	{
		while (num != 0)
		{
			num_box[len++] = (DIGITS[num % info->num_base]) | info->locass;
			num = num / info->num_base;
			if (num < 0 && info->address == ENABLE)
				num *= -1;
		}
	}
	return (len);
}

int	print_sign(t_info *info)
{
	int	ret;

	ret = 0;
	if (info->num_sign == -1)
		ret += write(1, "-", 1);
	if (info->address == ENABLE)
		ret += write(1, "0x", 2);
	return (ret);
}

int	print_num(t_info *info, long long num)
{
	int			len;
	int			gap;
	int			ret;
	long long	tmp_num;
	char		num_box[21];

	ret = 0;
	tmp_num = num;
	len = num_itoa(info, num_box, num);
	if (tmp_num == 0 && (info->precision == 0 || info->dot_only == ENABLE))
		len = 0;
	gap = info->width - get_max(info->precision, len);
	if ((info->minus == DISABLE && gap > 0) && (!(info->zero == ENABLE
				&& info->precision < 0) || info->dot_only == ENABLE))
		ret += ft_putchar_len(' ', &gap);
	info->precision = get_max(info->precision, len);
	ret += print_sign(info);
	if (info->zero == ENABLE)
		ret += ft_putchar_len('0', &gap);
	info->precision -= len;
	ret += ft_putchar_len('0', &info->precision);
	while (len-- > 0)
		ret += write(1, &num_box[len], 1);
	ret += ft_putchar_len(' ', &gap);
	return (ret);
}
