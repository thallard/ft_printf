/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:14:07 by thallard          #+#    #+#             */
/*   Updated: 2020/12/03 19:45:26 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

long	ft_printnbr_len_positive(long n)
{
	long int	temp;
	temp = n;
	long res;

	if (temp < 0)
	{
		temp = -temp;
	}
	res = ft_get_len(temp);
	if (temp > 9)
	{
		ft_printnbr_len(temp / 10);
		ft_printnbr_len(temp % 10);
	}
	else
		ft_putchar(temp + '0');
	return (res);
}

int		ft_putstr_len_limit(char *str, int max)
{
	int		i;

	i = -1;
	while (str[++i] && i < max)
		ft_putchar(str[i]);
	return (i);
}