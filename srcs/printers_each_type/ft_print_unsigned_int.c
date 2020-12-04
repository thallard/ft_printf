/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:37:15 by thallard          #+#    #+#             */
/*   Updated: 2020/12/04 17:32:45 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int		ft_print_integer_u(t_flags *f, va_list args)
{
	int				count;
	unsigned int	nb;
	int				size;
	int				zeros;
	int				spaces;

	count = 0;
	nb = va_arg(args, unsigned int);
	size = ft_get_len(nb);
	zeros = f->point - size > 0 ? f->point - size : 0;
	spaces = f->width - (zeros + size) > 0 ?
			f->width - (zeros + size) : 0;
	if ((count = ft_print_integer_first_cases(f, nb, spaces, zeros)) >= 1)
		return (count);
	if (!ft_have_flags(f))
		return ((nb < 0 ? ft_putchar_len('-') : 0) + ft_printnbr_len(nb));
	if (f->zero && f->point == -1)
		return (count + ft_print_integer_nozero_no_point(nb, spaces));
	if (!f->point && nb == 0)
		return (count + ft_print_integer_nopoint(f));
	count += ft_filler_integer_i_d(f, nb, spaces, zeros);
	return (count);
}