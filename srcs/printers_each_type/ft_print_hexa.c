/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:30:03 by thallard          #+#    #+#             */
/*   Updated: 2020/12/02 14:04:18 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int		ft_print_integer_hexa(t_flags *f, va_list args, int maj)
{
	int		i;
	char	*res;

	res = ft_calcul_hexa(va_arg(args, unsigned int), maj);
	i = ft_strlen(res);
	if (res[0] == '0' && f->point && !f->width)
		return (0);
	if (f->width && f->zero)
	{
		i = ft_filler_zero_hexa(f, res, i);
		return (i);
	}
	if (f->width && f->minus)
	{
		ft_putstr_len_rev(res);
		while (i < f->width)
			i += ft_putchar_len(' ');
		free(res);
		return (i);
	}
	if (f->width)
		while (i < f->width)
			i += ft_putchar_len(' ');
	ft_putstr_len_rev(res);
	free(res);
	return (i);
}

int		ft_print_hexa_pointer(t_flags *f, va_list args)
{
	int		i;

	(void)f;
	i = 0;
	i += hexa_pointer((unsigned long long)va_arg(args, unsigned int));
	return (i);
}

char	*ft_calcul_hexa(unsigned long long nb, int maj)
{
	unsigned long long	nbr;
	unsigned long long	reste;
	int					j;
	char				*res;

	j = 0;
	nbr = nb;
	if (nb == 0)
		return (ft_strdup("0"));
	if (!(res = malloc(sizeof(20))))
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

int		hexa_pointer(unsigned long long nb)
{
    unsigned long long nbr;
	unsigned long long reste;
    int j;
    char res[100];
	
	j = 0;
    nbr = nb;
	if ((int)nb == -1)
		return (ft_putstr_len("0xffffffffffffffff"));
	if (nb == ULONG_MAX + 1)
		return (ft_putstr_len("0x0"));
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
	while (--j >= 0)
		ft_putchar(res[j]);
	return (ft_strlen(res));
}


// void ft_hexa_parser(char *str, int i, int maj, int hexa)
// {

// 	if (hexa)
// 	{
// 		str[i++] = 'x';
// 		str[i++] = '0';
// 	}
// 	str[i] = '\0';
// 	if (maj)
// 		ft_tolower(str);
// }