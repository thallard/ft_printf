/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:30:44 by thallard          #+#    #+#             */
/*   Updated: 2020/12/05 02:15:02 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_flags
{
	int		zero;
	int		minus;
	int		width;
	int		star;
	int		point;
	int		type;
}				t_flags;

int				ft_start_print(const char *str, va_list a, t_flags *f, int *c);
int				ft_detect_flags(const char *str, va_list a, t_flags *f, int c);
int				ft_printf(const char *format, ...);

int				ft_prepare_print(const char *str, t_flags *f, va_list a);
int				ft_set_point_width(const char *s, t_flags *f, int i, va_list a);
int				ft_set_star_width(const char *s, t_flags *f, int i, va_list a);

int				ft_print_integer_i_d(t_flags *f, va_list a);
int				ft_print_integer_first_cases(t_flags *f, long nb, int s, int i);
int				ft_filler_integer_i_d(t_flags *f, long nb, int s, int z);
int				ft_print_integer_nopoint(t_flags *f);
int				ft_print_integer_zero_no_point(long nb, int spaces);

int				ft_print_integer_u(t_flags *f, va_list a);

int				ft_print_integer_hexadecimal(t_flags *f, va_list a, int maj);
int				ft_print_hexa_first_cases(t_flags *f, char *nb);
char			*ft_calcul_hexa(unsigned int nb, int maj);

int				ft_print_char(t_flags *f, va_list a);
int				ft_print_string(t_flags *f, va_list a);
int				ft_print_percentage(t_flags *f);
int				ft_place_spaces(t_flags *f, char *res, int whitespace);
char			*ft_apply_precision(t_flags *f, char *res, int len);

int				ft_print_hexa_pointer(t_flags *f, va_list a);
char			*hexa_pointer(unsigned long long nb);

int				ft_is_flag(int c);
int				ft_is_spec(int c);
int				ft_is_digit(int character);
int				ft_is_type(char c);

void			ft_putchar(char c);
int				ft_putchar_len(char c);
int				ft_putstr_len(char *str);
int				ft_putstr_len_rev(char *str);
long			ft_printnbr_len(long n);

int				ft_init_struct_flags(t_flags *f);
int				ft_have_flags(t_flags *f);

int				ft_get_len(long n);
int				ft_strlen(const char *s);
void			ft_tolower(char *str);
char			*ft_strdup(char *src);

#endif
