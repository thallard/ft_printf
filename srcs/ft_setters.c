/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:21:29 by thallard          #+#    #+#             */
/*   Updated: 2020/12/06 13:38:22 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_init_struct_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->point = -1;
	flags->star = 0;
	flags->width = 0;
	flags->type = 0;
	return (1);
}

int		ft_have_flags(t_flags *f)
{
	return (f->point > -1 || f->star || f->minus || f->zero);
}
