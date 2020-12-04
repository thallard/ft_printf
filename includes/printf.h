/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:30:44 by thallard          #+#    #+#             */
/*   Updated: 2020/12/04 16:39:37 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_flags
{
	int 	zero;
	int		minus;
	int		width;
	int		star;
	int		point;
	int		type;
}				t_flags;


// Main file
int		ft_prepare_print(const char *str, t_flags *f, va_list args);
int		ft_printf(const char *format, ...) __attribute__ ((format(printf,1,2)));

// Setters
int		ft_init_struct_flags(t_flags *flags);
int		ft_set_point_width(const char *str, t_flags *flags, int i, va_list arg);
int		ft_set_star_width(const char *str, t_flags *flags, int i, va_list args);
int		ft_have_flags(t_flags *f);


// Checkers
int		ft_is_digit(int character);
int		ft_is_type(char c);
int		ft_is_spec(int c);
int		ft_is_flag(int c);

// Printers
int		ft_putchar_len(char c);
int		ft_putstr_len(char *str);
int		ft_putstr_len_rev(char *str);
void	ft_putchar(char c);
long	ft_printnbr_len(long n);
long	ft_printnbr_len_positive(long n);
int		ft_putstr_len_limit(char *str, int max);

// Printers type
int		ft_print_string(t_flags *flags, va_list args);
int		ft_print_char(t_flags *flags, va_list args);
int		ft_print_integer_i_d(t_flags *flags, va_list args);
int		ft_print_integer_u(t_flags *flags, va_list args);
int		ft_print_integer_hexa(t_flags *flags, va_list args, int maj);
int		ft_print_hexa_pointer(t_flags *flags, va_list args);
int		ft_print_percentage(t_flags *flags, const char *str);
int		ft_print_string_star(t_flags *f, char *res);

// Fillers
int		ft_fill_integer_zero(t_flags *flags, int nb, int size);
int		ft_fill_integer_zero_unsigned(t_flags *flags, int nb, int size);
int		ft_filler_zero_hexa(t_flags *flags, char *res, int size);
int		ft_filler_width(t_flags *flags, int size, int space, char *str);
int		ft_filler_minus_string(t_flags *f, int i, int min, char *res);
int		ft_filler_integer_i_d(t_flags *f, long nb, int spaces, int zeros);
int		ft_filler_integer_i_d_point_zero(t_flags *f);
int		ft_print_integer_nozero_no_point(long nb, int spaces);
int		ft_print_integer_first_cases(t_flags *f, long nb, int spaces, int size);
int		ft_print_integer_nopoint(t_flags *f);

// Calculs
char	*ft_calcul_hexa(unsigned long long nb, int maj);
int		hexa_pointer(unsigned long long nb);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_char(int nb, t_flags *flags);
char	*ft_apply_precision(t_flags *f, char *res, int len);
int		ft_place_spaces(t_flags *f, char *res, int whitespace);
int		ft_apply_zeros(t_flags *flags, long nb, int zeros);
int		ft_apply_spaces(t_flags *flags, long nb, int spaces);

// Utilitaires
int		ft_strlen(const char *str);
int		ft_get_len(long n);
void	ft_tolower(char *str);
char	*ft_strdup(char *src);





















// int		ft_get_type(char c, int nb);
// int		ft_putstr_len(const char *s);
// void	ft_putchar_fd(const char c, int fd);
// void	ft_putnbr_fd(int n, int fd);
// long	printnbr_len(long n);
// int		ft_printf(const char *format, ...) __attribute__
//                     ((format(printf,1,2)));

// void	ft_putnbr_base(long nbr, char *base, int oui);
// int		ft_toupper(int character);
// char	*ft_strchr(const char *string, int c);
// int		ft_strlen(char *str);
// int		ft_get_len(long n);
// void	ft_tolower(char *str);
// int		ft_isdigit(int character);

// int		ft_putchar(char c);
// int 	hexa(long nb, int maj, int hexa);
// int		hexa_pointer(unsigned long long nb);

// int		ft_atoi(const char *str);

// // Fonctions flags (0-*.)
// int		ft_flag_zero(const char *format, int i, int nb);

// int		ft_atoi_base(char *str, char *base);

#endif