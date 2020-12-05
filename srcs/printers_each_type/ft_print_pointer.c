/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:04:23 by thallard          #+#    #+#             */
/*   Updated: 2020/12/05 01:15:23 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int		ft_print_hexa_pointer(t_flags *f, va_list args)
{
	int		count;
	char	*nb;
	int		spaces;

	nb = ft_strdup(hexa_pointer(va_arg(args, unsigned long long)));
	spaces = f->width - ft_strlen(nb) > 0 ? f->width - ft_strlen(nb) : 0;
	count = 0;
	if (!(ft_have_flags(f)) && f->width == 0)
		return (ft_putstr_len_rev(nb));
	if (!f->minus)
		while (spaces--)
			count += ft_putchar_len(' ');
	count += ft_putstr_len_rev(nb);
	if (f->minus)
		while (spaces--)
			count += ft_putchar_len(' ');
	return (count);
}

char	*hexa_pointer(unsigned long long nb)
{
	unsigned long long		nbr;
	unsigned long long		reste;
	int						j;
	char					*res;

	j = 0;
	nbr = nb;
	if (nb == ULONG_MAX + 1)
		return (ft_strdup("0x0"));
	if (!(res = malloc(sizeof(char) * 25)))
		return (NULL);
	while (nbr != 0)
	{
		reste = nbr % 16;
		if (reste < 10)
			res[j++] = 48 + reste;
		else
			res[j++] = 55 + reste;
		nbr = nbr / 16;
	}
	res[j++] = 'x';
	res[j++] = '0';
	res[j] = '\0';
	ft_tolower(res);
	return (res);
}
