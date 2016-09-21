/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:40:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/20 01:09:05 by jmarsal          ###   ########.fr       */
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
** print_format
*/


/*
** init.c
*/

t_args		*init_t_args(void);

/*
** init_f_conv.c
*/

t_conv		**init_tab_args(t_args *v_args);

/*
** conv_hex_bin.c
*/

void	conv_hex_x(va_list *args, t_args *v_args, const char *format,
					size_t * i);
void	conv_hex_lx(va_list *args, t_args *v_args, const char *format,
					size_t * i);
void	conv_binary_b(va_list *args, t_args *v_args, const char *format,
					size_t * i);

/*
** conv_str.c
*/

void	conv_str_s(va_list *args, t_args *v_args, const char *format,
					size_t * i);

/*
** conv_char.c
*/

void	conv_char_c(va_list *args, t_args *v_args, const char *format,
					size_t * i);

/*
** conv_decimal.c
*/

void	conv_decimal_d(va_list *args, t_args *v_args, const char *format,
					size_t * i);
void	conv_decimal_ld(va_list *args, t_args *v_args, const char *format,
					size_t * i);
void	conv_u_decimal_u(va_list *args, t_args *v_args, const char *format,
					size_t * i);
void	conv_lu_decimal_lu(va_list *args, t_args *v_args, const char *format,
					size_t * i);

/*
** conv_octal.c
*/

void	conv_octal_o(va_list *args, t_args *v_args, const char *format,
					size_t * i);
void	conv_octal_lo(va_list *args, t_args *v_args, const char *format,
					size_t * i);

/*
** conv_mem.c
*/

void	conv_mem_p(va_list *args, t_args *v_args, const char *format,
					size_t * i);

/*
** parser_helper.c
*/

int		is_conversion_flag(const char *format, size_t *i,
					const char *flags);

/*
** output.c
*/

int		print_format(t_args *v_args);
void	is_caracters_is_positive(t_args *v_args, size_t i);
void	is_caracters_is_space(t_args *v_args, size_t i);


/*
** output_f_caracters.c
*/

void	is_caracters_is_neg_and_precision(t_args *v_args, size_t i);
void	is_width_precision_and_not_minus(t_args *v_args, size_t i);
void	is_caracters_is_sharp(t_args *v_args, size_t i);
void	is_width_precision_plus_minus(t_args *v_args, size_t i);

/*
** get_content_format.c
*/

void	get_content_format(va_list *args, const char *format,
								t_args *v_args);

/*
** get_content_helper.c
*/

void	get_width_in_format(const char *format, size_t *i, t_args *v_args);
void	get_precision_in_format(const char *format, size_t *i, t_args *v_args);
void	get_modifier_in_format(const char *format, size_t *i, t_args *v_args);

/*
** error.c
*/

int		find_error_in_format(t_args *v_args);
void 	error_output(int err);

/*
** output_char.c
*/

void	print_char_c(t_args *v_args, size_t i, size_t *test_c);

/*
** output_str.c
*/

void	print_str_s(t_args *v_args, size_t i);

/*
** output_decimal.c
*/

void	print_decimal_d(t_args *v_args, size_t i);
void	print_decimal_ld(t_args *v_args, size_t i);
void	print_decimal_u(t_args *v_args, size_t i);
void	print_decimal_lu(t_args *v_args, size_t i);

/*
** output_hex_bin.c
*/

void 	print_hex_x(t_args *v_args, size_t i);
void 	print_hex_maj_x(t_args *v_args, size_t i);
void 	print_hex_b(t_args *v_args, size_t i);

/*
** output_mem.c
*/

void	print_ptr(t_args *v_args, size_t i);
char	*ft_get_ptr(int *ptr);

/*
** output_octal.c
*/

void	print_octal_o(t_args *v_args, size_t i);
void	print_octal_lo(t_args *v_args, size_t i);

/*
** modifier.c
*/

char	*modifier_x(t_args *v_args, size_t i, size_t len);

#endif
