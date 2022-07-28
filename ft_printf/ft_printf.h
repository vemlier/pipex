/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:31:27 by chukim            #+#    #+#             */
/*   Updated: 2022/04/18 13:20:16 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define ENABLE 1
# define DISABLE 0
# define SMALL 32

# define DIGITS "0123456789ABCDEF"

typedef struct s_info
{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			dot_only;
	int			locass;
	int			num_base;
	int			num_sign;
	int			address;
}				t_info;

void	init_struct(t_info *info);
int		ft_parse_symbols(const char *format, va_list ap);
int		ft_printf(const char *format, ...);

int		skip_atoi(const char **s);
void	ft_parse_flag(const char **format, t_info *info);
void	ft_parse_width(const char **format, t_info *info, va_list ap);
void	ft_parse_precision(const char **format, t_info *info, va_list ap);
int		ft_parse_type(t_info *info, va_list ap, const char type);

int		ft_print_char(t_info *info, va_list ap);
int		ft_print_percent(t_info *info);
int		ft_print_string(t_info *info, va_list ap);
int		ft_print_di(t_info *info, va_list ap);
int		ft_print_u(t_info *info, va_list ap);
int		ft_print_xx(t_info *info, va_list ap, char type);
int		ft_print_p(t_info *info, va_list ap);
int		ft_print_num(t_info *info, va_list ap, const char type);
int		get_max(int a, int b);
int		ft_putchar_len(char c, int *len);
int		num_itoa(t_info *info, char *num_box, unsigned long long num);
int		print_sign(t_info *info);
int		print_num(t_info *info, long long num);

#endif