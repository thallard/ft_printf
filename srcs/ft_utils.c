/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:17:11 by thallard          #+#    #+#             */
/*   Updated: 2020/12/07 01:08:34 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_len(long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0 && len == 0)
		n = n * (-1);
	while (n >= 1 && len++ >= 0)
		n /= 10;
	return (len);
}

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_tolower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
}

char	*ft_strdup(char *src)
{
	char	*str;
	long	i;

	if (!src)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}