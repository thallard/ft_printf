/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:30:18 by thallard          #+#    #+#             */
/*   Updated: 2020/12/05 02:09:24 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		ft_start_print(const char *str, va_list arg, t_flags *flags, int *count)
{
	int		i;

	i = -1;
	str++;
	while ((str[++i] && ft_is_flag(str[i])))
	{
		if (str[i] == '0' && flags->point == -1 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '*')
			i += ft_set_star_width(str, flags, i, arg);
		if (str[i] == '.')
			i += ft_set_point_width(str, flags, i, arg);
		if (ft_is_digit(str[i]) && flags->point == -1)
			flags->width = flags->width * 10 + str[i] - '0';
		if (str[i] == '-')
			flags->minus = 1;
		if (ft_is_type(str[i]))
		{
			*count += ft_prepare_print(str + i++, flags, arg);
			break ;
		}
	}
	return (i);
}

int		ft_detect_flags(const char *str, va_list arg, t_flags *flags, int count)
{
	int		i;

	i = -1;
	while (str[++i] && i < ft_strlen(str))
	{
		ft_init_struct_flags(flags);
		if (str[i] == '%' && str[i + 1])
			i += ft_start_print((str + i), arg, flags, &count);
		else if (str[i] != '%')
			count += ft_putchar_len(str[i]);
	}
	return (count);
}

int		ft_printf(const char *format, ...)
{
	int			count;
	va_list		arg;
	t_flags		flags;

	count = 0;
	va_start(arg, format);
	count = ft_detect_flags(format, arg, &flags, count);
	va_end(arg);
	return (count);
}
