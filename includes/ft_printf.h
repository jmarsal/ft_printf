/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:40:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 16:12:59 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "../libft/includes/libft.h"
# include "structs.h"
# include "defines.h"

#include <stdio.h> // WARNING !!!!

int				ft_printf(const char *format, ...);
int				treatment(const char *format, t_result *result);

/*
** init.c
*/

t_result		*init_t_result(va_list ap, const char *format);

/*
** init_f_conv.c
*/

t_conv		**init_tab_ap(t_result *result);

/*
** conv_hex.c
*/

void	conv_hex_x(va_list *ap, t_result *result, const char *format,
					size_t * i);

/*
** conv_char_str.c
*/

void	conv_str_s(va_list *ap, t_result *result, const char *format,
					size_t * i);

/*
** conv_bin_dec_oct.c
*/

void	conv_bin_dec_oct(va_list *ap, t_result *result, const char *format,
					size_t *i);

/*
** conv_mem.c
*/

void	conv_mem_p(va_list *ap, t_result *result, const char *format,
					size_t * i);

/*
** parser_helper.c
*/

void	find_is_color(const char *format, size_t *i, t_result *result);
void	get_is_color(const char *format, size_t *i, t_result *result);
int		is_conversion_flag(const char *format, size_t *i,
					const char *flags);

/*
** output.c
*/

int		print_format(t_result *result);

/*
** output_width_precision_minus.c
*/

void	is_width_precision_and_not_minus(t_result *result, size_t i);

/*
** output_width_precision_minus.c
*/

void	is_width_precision_minus(t_result *result, size_t i);

/*
** get_content_format.c
*/

void	get_content_format(va_list *ap, const char *format,
								t_result *result);

/*
** get_content_helper.c
*/

void	get_width_in_format(const char *format, size_t *i, t_result *result);

/*
** error.c
*/

int		find_error_in_format(t_result *result);

/*
** output_char_str.c
*/

void	print_char_str(t_result *result, size_t i, size_t *test_c);

/*
** output_bin_dec_octal.c
*/

void	print_bin_dec_oct(t_result *result, size_t i);

/*
** output_hex.c
*/

void 	print_hex_x(t_result *result, size_t i);

/*
** output_mem.c
*/

void	print_ptr(t_result *result, size_t i);

/*
** conv_helper.c
*/

void	ajust_width_precision_itoa_base(t_result *result, int base);
void	ajust_width_precision_litoa_base(t_result *result, int base);
void	ajust_width_precision_ulitoa_base(t_result *result, int base);
void	get_specifier_and_ajust_width(char specifier, t_result *result);

#endif
