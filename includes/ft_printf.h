/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 00:40:21 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/03 02:53:33 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <libft.h>
# include <wchar.h>
# include "structs.h"
# include "defines.h"

#include <stdio.h> // WARNING !!!!

int				ft_printf(const char *format, ...);
int				treatment(va_list *args, const char *format);

/*
** print_format
*/

void			print_format(t_v_args *v_args);

/*
** init.c
*/

t_v_args		*init_t_v_args(void);
t_conversion	**init_tab_args(t_v_args *v_args);

/*
** conv_hex_bin.c
*/

void	conv_hex_x(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);
void	conv_hex_lx(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);
void	conv_binary_b(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);

/*
** conv_str.c
*/

void	conv_str_s(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);

/*
** conv_char.c
*/

void	conv_char_c(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);

/*
** conv_decimal.c
*/

void	conv_decimal_d(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);
void	conv_decimal_ld(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);
void	conv_u_decimal_u(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);
void	conv_lu_decimal_lu(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);

/*
** conv_octal.c
*/

void	conv_octal_o(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);
void	conv_octal_lo(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);

/*
** conv_mem.c
*/

void	conv_mem_p(va_list *args, t_v_args *v_args, const char *format,
					size_t * i);
#endif
