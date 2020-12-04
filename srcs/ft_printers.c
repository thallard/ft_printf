/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:57:57 by thallard          #+#    #+#             */
/*   Updated: 2020/12/03 20:27:47 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr_len(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	return (ft_strlen(str));
}

int		ft_putstr_len_rev(char *str)
{
	int		i;

	i = ft_strlen(str);
	while (i-- > 0)
		ft_putchar(str[i]);
	return (ft_strlen(str));
}

long	ft_printnbr_len(long n)
{
	long int	temp;
	temp = n;
	long res;

	res = ft_get_len(n);
	if (temp < 0)
	{
		temp = -temp;
	}
	if (temp > 9)
	{
		ft_printnbr_len(temp / 10);
		ft_printnbr_len(temp % 10);
	}
	else
		ft_putchar(temp + '0');
	return (res);
}