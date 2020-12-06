/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:10:07 by thallard          #+#    #+#             */
/*   Updated: 2020/12/06 16:51:57 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_print_integer_i_d(t_flags *f, va_list args)
{
	int		count;
	long	nb;
	int		size;
	int		zeros;
	int		spaces;

	count = 0;
	nb = va_arg(args, int);
	size = ft_get_len(nb);
	f->minus = f->width < 0 ? 1 : f->minus;
	f->width = f->width < 0 ? f->width * -1 : f->width;
	f->zero = f->minus ? 0 : f->zero;
	zeros = f->point - size > 0 ? f->point - size : 0;
	spaces = f->width - (zeros + size) - (nb < 0) > 0 ?
			f->width - (zeros + size) - (nb < 0) : 0;
	if ((count = ft_print_integer_first_cases(f, nb, spaces, zeros)) >= 1)
		return (count);
	if (!ft_have_flags(f))
		return ((nb < 0 ? ft_putchar_len('-') : 0) + ft_printnbr_len(nb));
	if (f->zero && f->point == -1)
		return (count + ft_print_integer_zero_no_point(nb, spaces));
	if (!f->point && nb == 0)
		return (count + ft_print_integer_nopoint(f));
	count += ft_filler_integer_i_d(f, nb, spaces, zeros);
	return (count);
}

int		ft_print_integer_first_cases(t_flags *f, long nb, int spaces, int size)
{
	int		count;

	count = 0;
	if (f->zero && f->width < 0)
	{
		count += ft_printnbr_len(nb);
		f->width += ft_get_len(nb);
		while (f->width++)
			count += ft_putchar_len(' ');
		return (count);
	}
	if (f->width > size && f->width > 0 && !f->minus && !f->zero
		&& f->point == -1)
	{
		while (spaces--)
			count += ft_putchar_len(' ');
		if (nb < 0)
			count += ft_putchar_len('-');
		return (count + ft_printnbr_len(nb));
	}
	return (0);
}

int		ft_filler_integer_i_d(t_flags *f, long nb, int spaces, int zeros)
{
	int		count;

	count = 0;
	if (!f->minus)
		while (spaces--)
			count += ft_putchar_len(' ');
	if (nb < 0)
		count += ft_putchar_len('-');
	while (zeros--)
		count += ft_putchar_len('0');
	count += ft_printnbr_len(nb);
	if (f->width < 0 && f->star)
		while (f->width++ < 0)
			count += ft_putchar_len(' ');
	if (f->minus)
		while (spaces--)
			count += ft_putchar_len(' ');
	return (count);
}

int		ft_print_integer_nopoint(t_flags *f)
{
	int		count;

	count = 0;
	while (f->width--)
		count += ft_putchar_len(' ');
	return (count);
}

int		ft_print_integer_zero_no_point(long nb, int spaces)
{
	int		count;

	count = 0;
	if (nb < 0)
		count += ft_putchar_len('-');
	while (spaces--)
		count += ft_putchar_len('0');
	return (count + ft_printnbr_len(nb));
}
