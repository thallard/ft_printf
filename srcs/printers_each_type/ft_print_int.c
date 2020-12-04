/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:10:07 by thallard          #+#    #+#             */
/*   Updated: 2020/12/04 02:21:44 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int		ft_print_integer_i_d(t_flags *f, va_list args)
{
	int		count;
	long		nb;
	int		size;
	int		zeros;
	int		spaces;

	count = 0;
	nb = va_arg(args, int);
	size = ft_get_len(nb);
	//dprintf(1, "Longueur de nb : %d\n", size);
	zeros = f->point - size > 0 ? f->point - size : 0;
	spaces = f->width - (zeros + size) - (nb < 0) > 0 ?
			 f->width - (zeros + size) - (nb < 0) : 0;
	// dprintf(1, "Nombre de zeros : %d\n", zeros);
	// dprintf(1, "Nombre d'espaces : %d\n", spaces);
	if (f->zero && f->width < 0)
	{
		count += ft_printnbr_len(nb);
		f->width += ft_get_len(nb);
		while (f->width++)
			count += ft_putchar_len(' ');
		return (count);
	}
	 if (f->width > size && f->width > 0 && !f->minus && !f->zero && f->point == -1)
	{
		while (spaces--)
			count += ft_putchar_len(' ');
		if (nb < 0)
			count += ft_putchar_len('-');
		count += ft_printnbr_len(nb);
		return (count);
	}
	if (!ft_have_flags(f))
		return ((nb < 0 ? ft_putchar_len('-') : 0) + ft_printnbr_len(nb));
	
	if (f->zero && f->point == -1)
	{
		if (nb < 0)
			count += ft_putchar_len('-');
		while (spaces--)
			count += ft_putchar_len('0');
		return (count + ft_printnbr_len(nb));
	}
	if (!f->point && nb == 0)
	{
		while (f->width--)
			count += ft_putchar_len(' ');
		return (count);
	}
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

int		ft_apply_spaces(t_flags *f, long nb, int spaces)
{
	int		i;
	int		is_negative;
	int 	count;
	(void)f;
	count = 0;
	is_negative = 0;
	i = 0;
		if (nb < 0)
	{
		is_negative = 1;
		nb = -nb;
	}
	if (!f->minus)
		while (count < spaces - is_negative)
			count += ft_putchar_len(' ');
	if (is_negative)
		count += ft_putchar_len('-');
	if (f->minus)
	{
		i += ft_printnbr_len(nb);
		while (i <= spaces - is_negative)
			i += ft_putchar_len(' ');
	}
	return (i + count);
}

int		ft_apply_zeros(t_flags *f, long nb, int zeros)
{
	int		i;
	int		is_negative;
	int		count;
	(void)f;
	count = 0;
	is_negative = 0;
	i = 0;
	if (nb < 0)
	{
		is_negative = 1;
		nb = -nb;
	}
	if (is_negative)
		count += ft_putchar_len('-');
	while (i < zeros)
		i += ft_putchar_len('0');
	return (i + count);
}

int		ft_char(int nb, t_flags *f)
{
	(void)nb;
	if (f->point == -1)
		return ('0');
	return (' ');
}































// int		ft_print_integer_i_d(t_flags *f, va_list args)
// {
// 	int		i;
// 	int		nb;
	
// 	nb = va_arg(args, int);
// 	i = ft_get_len(nb);
// 	if (f->width && f->zero && !f->minus)
// 		return (ft_fill_integer_zero(f, nb, i));
// 	if ((f->width && f->point) || (!f->width && f->point))
// 		return (ft_fill_integer_zero(f, nb, i));
// 	if (f->width && f->minus)
// 	{
// 			ft_printnbr_len(nb);
// 		while (i < f->width)
// 			i += ft_putchar_len(' ');
// 	return (i);
// 	}
// 	if (f->width)
// 		while (i < f->width)
// 			i += ft_putchar_len(' ');
// 	ft_printnbr_len(nb);
// 	return (i);
// }

int		ft_print_integer_u(t_flags *f, va_list args)
{
	int				i;
	unsigned int	nb;
	
	nb = va_arg(args, unsigned int);
	i = ft_get_len(nb);
	if (f->width && f->zero && !f->minus)
		return (ft_fill_integer_zero_unsigned(f, (unsigned int)nb, i));
	if ((f->width && f->point) || (!f->width && f->point))
		return (ft_fill_integer_zero_unsigned(f, (unsigned int)nb, i));
	if (f->width && f->minus)
	{
		ft_printnbr_len(nb);
		while (i < f->width)
			i += ft_putchar_len(' ');
		return (i);
	}
	if (f->width)
	while (i < f->width)
		i += ft_putchar_len(' ');
	if (nb != 0 && f->point)
		return (i += ft_printnbr_len(nb));
	ft_printnbr_len(nb);
	return (i);
}

int		ft_fill_integer_zero(t_flags *f, int nb, int size)
{
	int		i;

	i = size;
	if (nb <= -1)
		f->width += ft_putchar_len('-');
	if ((f->width && f->point) || (!f->width && f->point) || (f->width && f->zero))
		printf("%d", i);
		while (i < f->width)
			i += ft_putchar_len('0');
	if (nb != 0 && f->point)
		ft_printnbr_len_positive((long)nb);
	return (i);
}

int		ft_fill_integer_zero_unsigned(t_flags *f, int nb, int size)
{
	int		i;

	i = size;
	if (nb < -1)
		ft_putchar_len('-');
	while (i < f->width)
		i += ft_putchar_len('0');
	if (nb == 0 && f->point)
		return (0);
	ft_printnbr_len_positive((unsigned int)nb);
	return (i);
}