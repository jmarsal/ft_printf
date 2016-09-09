/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:28:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/05 00:46:23 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_hex_x(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'x')
	{
		L_CONV = 'x';
		INT = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa_base(INT, 16));
	}
}

void	conv_hex_lx(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'X')
	{
		L_CONV = 'X';
		INT = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa_base(INT, 16));
	}
}

void	conv_binary_b(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'b')
	{
		L_CONV = 'b';
		INT = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa_base(INT, 2));
	}
}
