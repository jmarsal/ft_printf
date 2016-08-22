/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:28:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/22 15:58:54 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_hex_x(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && format[*i + 1] == 'x')
	{
		L_CONV = 'x';
		HEX = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa_base(HEX, 16));
	}
}

void	conv_hex_lx(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && format[*i + 1] == 'X')
	{
		L_CONV = 'X';
		HEX = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa_base(HEX, 16));
	}
}

void	conv_binary_b(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && format[*i + 1] == 'b')
	{
		L_CONV = 'b';
		BINARY = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa_base(HEX, 2));
	}
}
