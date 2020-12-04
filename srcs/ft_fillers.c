/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:46:16 by thallard          #+#    #+#             */
/*   Updated: 2020/12/03 15:52:04 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_filler_zero_hexa(t_flags *flags, char *res, int size)
{
	int		i;

	i = size;
	while (i < flags->width)
		i += ft_putchar_len('0');
	ft_putstr_len(res);
	return (i);
}

int		ft_filler_width(t_flags *f, int size, int space, char *res)
{
	int		i;
	char	character;

	character = '0';
	if (space)
		character = ' ';
	i = size;
	//printf("size %d et width %d", size, f->width);
	if (f->minus && f->width)
	{
		ft_putstr_len(res);
		while (i < f->width)
			i += ft_putchar_len(character);
		return (i);
	}
	while (i < f->width)
		i += ft_putchar_len(character);
	ft_putstr_len(res);
	return (i);
}

int		ft_filler_minus_string(t_flags *f, int i, int min, char *res)
{
	int		j;

	j = 0;
	while (j < min)
		j += ft_putchar_len(res[j]);
	i = j;
	j = 0;
	while (j < ft_max(f->width - min, 0))
		j += ft_putchar_len(' ');
	return (i + j);
}