/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:30:03 by thallard          #+#    #+#             */
/*   Updated: 2020/12/05 01:40:19 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int		ft_print_integer_hexadecimal(t_flags *f, va_list args, int maj)
{
	char	*res;
	int		count;

	count = 0;
	res = ft_strdup(ft_calcul_hexa(va_arg(args, unsigned int), maj));
	if (!res)
		return (0);
	if (!ft_have_flags(f) && f->width == 0)
		count += ft_putstr_len_rev(res);
	else
	{
		if (f->point == 0 && res[0] == '0' && res[1] == '\0')
			while (f->width-- > 0)
				count += ft_putchar_len(' ');
		else if (f->width || f->point)
			count = ft_print_hexa_first_cases(f, res);
		else
			count = ft_putstr_len_rev(res);
	}
	free(res);
	return (count);
}

int		ft_print_hexa_first_cases(t_flags *f, char *nb)
{
	int		count;
	int		spaces;
	int		size;
	int		zeros;

	count = 0;
	size = ft_strlen(nb);
	if (f->zero && f->point == -1)
		zeros = f->width - size > 0 ? f->width - size : 0;
	else
		zeros = f->point - size > 0 ? f->point - size : 0;
	spaces = f->width - (zeros + size);
	spaces = spaces > 0 ? spaces : 0;
	if (!f->minus)
		while (spaces--)
			count += ft_putchar_len(' ');
	while (zeros--)
		count += ft_putchar_len('0');
	count += ft_putstr_len_rev(nb);
	if (f->minus)
		while (spaces--)
			count += ft_putchar_len(' ');
	return (count);
}

char	*ft_calcul_hexa(unsigned int nb, int maj)
{
	unsigned int		nbr;
	unsigned int		reste;
	int					j;
	char				*res;

	j = 0;
	nbr = nb;
	if (nb == 0)
		return (ft_strdup("0"));
	if (!(res = malloc(20)))
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
	res[j] = '\0';
	if (!maj)
		ft_tolower(res);
	return (res);
}
