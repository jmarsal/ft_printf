/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:40:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/07 11:32:59 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"
# include <wchar.h>
# include "./structs.h"
# include "defines.h"

#include <stdio.h> // WARNING !!!!

int				ft_printf(const char *format, ...);
int				treatment(va_list *args, const char *format, t_args *v_args);

/*
** init.c
*/

t_args		*init_t_args(void);

/*
** init_f_conv.c
*/

t_conv		**init_tab_args(t_args *v_args);

/*
** conv_hex.c
*/

void	conv_hex_x(va_list *args, t_args *v_args, const char *format,
					size_t * i);

/*
** conv_char_str.c
*/

void	conv_str_s(va_list *args, t_args *v_args, const char *format,
					size_t * i);

/*
** conv_bin_dec_oct.c
*/

void	conv_bin_dec_oct(va_list *args, t_args *v_args, const char *format,
					size_t *i);

/*
** conv_mem.c
*/

void	conv_mem_p(va_list *args, t_args *v_args, const char *format,
					size_t * i);

/*
** parser_helper.c
*/

void	find_is_color(const char *format, size_t *i, t_args *v_args);
void	get_is_color(const char *format, size_t *i, t_args *v_args);
int		is_conversion_flag(const char *format, size_t *i,
					const char *flags);

/*
** output.c
*/

int		print_format(t_args *v_args);

/*
** output_width_precision_minus.c
*/

void	is_width_precision_and_not_minus(t_args *v_args, size_t i);

/*
** output_width_precision_minus.c
*/

void	is_width_precision_minus(t_args *v_args, size_t i);

/*
** get_content_format.c
*/

void	get_content_format(va_list *args, const char *format,
								t_args *v_args);

/*
** get_content_helper.c
*/

void	get_width_in_format(const char *format, size_t *i, t_args *v_args);

/*
** error.c
*/

int		find_error_in_format(t_args *v_args);

/*
** output_char_str.c
*/

void	print_char_str(t_args *v_args, size_t i, size_t *test_c);

/*
** output_bin_dec_octal.c
*/

void	print_bin_dec_oct(t_args *v_args, size_t i);

/*
** output_hex.c
*/

void 	print_hex_x(t_args *v_args, size_t i);

/*
** output_mem.c
*/

void	print_ptr(t_args *v_args, size_t i);

/*
** conv_helper.c
*/

void	ajust_width_precision_itoa_base(t_args *v_args, int base);
void	ajust_width_precision_litoa_base(t_args *v_args, int base);
void	ajust_width_precision_ulitoa_base(t_args *v_args, int base);
void	get_specifier_and_ajust_width(char specifier, t_args *v_args);

#endif
