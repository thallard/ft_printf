/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:01:53 by thallard          #+#    #+#             */
/*   Updated: 2020/12/05 01:57:25 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_prepare_print(const char *str, t_flags *f, va_list args)
{
	int count;

	f->type = *str;
	count = 0;
	if (*str == 's')
		count += ft_print_string(f, args);
	if (*str == 'c')
		count += ft_print_char(f, args);
	if (*str == 'i' || *str == 'd')
		count += ft_print_integer_i_d(f, args);
	if (*str == 'u')
		count += ft_print_integer_u(f, args);
	if (*str == 'x')
		count += ft_print_integer_hexadecimal(f, args, 0);
	if (*str == 'X')
		count += ft_print_integer_hexadecimal(f, args, 1);
	if (*str == 'p')
		count += ft_print_hexa_pointer(f, args);
	if (*str == '%')
		count += ft_print_percentage(f);
	return (count);
}

int		ft_set_point_width(const char *str, t_flags *f, int i, va_list arg)
{
	int		condi;

	i++;
	condi = 0;
	f->point = 0;
	if (str[i] == '*')
		f->point = va_arg(arg, int);
	else
		while (ft_is_digit(str[i]))
		{
			f->point = f->point * 10 + str[i++] - '0';
			condi = 1;
		}
	if (f->point == -1 && condi == 0)
		f->point = 0;
	return (1);
}

int		ft_set_star_width(const char *str, t_flags *f, int i, va_list args)
{
	int nb;

	if (str[i] == '*' && f->zero && f->width == 0 && f->point == -1)
	{
		f->width = va_arg(args, int);
		f->star = 1;
	}
	else if (str[i] == '*' && f->width == 0 && f->point == -1)
	{
		nb = va_arg(args, int);
		if (nb < 0 && (nb = -nb))
			f->minus = 1;
		f->width = nb;
		f->star = 1;
	}
	if (str[i] == '*' && f->point == 0 && f->width != 0)
	{
		nb = va_arg(args, int);
		if (nb < 0 && (nb = -nb))
			f->minus = 1;
		f->point = nb;
		f->star = 1;
	}
	return (1);
}
