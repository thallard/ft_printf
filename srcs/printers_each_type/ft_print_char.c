/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:42:37 by thallard          #+#    #+#             */
/*   Updated: 2020/12/06 16:35:42 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_print_char(t_flags *f, va_list args)
{
	int		i;

	i = 0;
	if (f->width && f->minus)
	{
		i += ft_putchar_len(va_arg(args, int));
		while (i < f->width)
			i += ft_putchar_len(' ');
		return (i);
	}
	while (i < f->width - 1)
		i += ft_putchar_len(' ');
	i += ft_putchar_len(va_arg(args, int));
	return (i);
}

int		ft_print_string(t_flags *f, va_list args)
{
	int		len;
	char	*res;
	int		whitespace;
	int		count;

	count = 0;
	res = ft_strdup(va_arg(args, char *));
	len = ft_strlen(res);
	if (f->point >= 0)
		res = ft_apply_precision(f, res, len);
	whitespace = f->width - ft_strlen(res);
	if (whitespace >= 0)
		count += ft_place_spaces(f, res, whitespace);
	if (!f->width || f->width < ft_strlen(res))
		count += ft_putstr_len(res);
	free(res);
	return (count);
}

int		ft_print_percentage(t_flags *f)
{
	int		i;

	i = 1;
	if (f->minus)
	{
		ft_putchar_len('%');
		while (i < f->width)
			i += ft_putchar_len(' ');
		return (i);
	}
	if (f->zero)
	{
		while (i < f->width)
			i += ft_putchar_len('0');
	}
	while (i < f->width)
		i += ft_putchar_len(' ');
	ft_putchar_len('%');
	return (i);
}

int		ft_place_spaces(t_flags *f, char *res, int whitespace)
{
	int		i;

	i = 0;
	if (!f->minus)
		while (i < whitespace)
			i += ft_putchar_len(' ');
	i += ft_putstr_len(res);
	if (f->minus)
		while (i < whitespace + ft_strlen(res))
			i += ft_putchar_len(' ');
	return (i);
}

char	*ft_apply_precision(t_flags *f, char *res, int len)
{
	int		i;

	i = 0;
	while (i < f->point && i < len)
		i++;
	res[i] = '\0';
	return (res);
}
