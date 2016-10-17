/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:40:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/17 16:46:36 by jmarsal          ###   ########.fr       */
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

int			ft_printf(const char *format, ...);

/*
** lexer_parser
*/

int			treatment(t_result *result);
void		parser_str(t_result *result, size_t *i);
void		lexer_parser_color(t_result *result, size_t *i);
void		lex_parse_percent(t_result *result, size_t *i);
int			parser_specifier(t_result *result, size_t *i);
void		get_flags(t_result *result, size_t *i);
void		parser_percent_if_flags_betwin(t_result *result, size_t *i);

/*
** memory
*/

t_result	*init_result(va_list ap, const char *format);
void		destroy_result(t_result **result);
t_conv		*tab_conv_init(t_conv *tab_conv);
void		tab_conv_add(t_result *result, size_t tab_index);

/*
** conversions
*/
void		conv_bin_dec_oct(t_result *result, size_t *i);
void		conv_str_s(t_result *result, size_t *i);
void		conv_hex_x(t_result *result, size_t * i);
void		conv_mem_p(t_result *result, size_t * i);

/*
** error
*/

int			find_error_in_format(t_result *result);
int			print_error_specifier(char caracters);

/*
** output.c
*/

int			print_result(t_result *result);
void		print_bin_dec_oct(t_result *result, size_t i);
void		print_char_str(t_result *result, size_t i, size_t *test_c);
void		print_str_if_char_to_zero(t_result *result);
void		print_hex_x(t_result *result, size_t i);
void		print_ptr(t_result *result, size_t i);
void		is_width_precision_minus(t_result *result, size_t i);
void		is_width_precision_and_not_minus(t_result *result, size_t i);
void		add_padding(t_result *result, size_t i, int size, char c);
void		get_specifier_and_ajust_width(t_result *result, char specifier);

#endif
