/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:28:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/27 01:52:29 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_hex_x(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'x')
	{
		L_CONV = 'x';
		if (!(I_MOD_LL || I_MOD_L))
		{
			INT = va_arg(*args, int);
			I_WIDTH_CPY -= ft_strlen(ft_itoa_base(INT, 16));
			I_PRECISION_CPY -= ft_strlen(ft_itoa_base(INT, 16));
		}
		else if (I_MOD_L ||
				I_MOD_LL)
		{
			U_L_INT = va_arg(*args, unsigned long);
			I_WIDTH_CPY -= ft_strlen(ft_litoa_base(U_L_INT, 16));
			I_PRECISION_CPY -= ft_strlen(ft_litoa_base(U_L_INT, 16));
		}
		if (A_PLUS == 1)
			I_WIDTH_CPY--;
		if (A_SPACE == 1)
			I_WIDTH_CPY--;
	}
}

void	conv_hex_lx(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'X')
	{
		L_CONV = 'X';
		if (!(I_MOD_LL || I_MOD_L))
		{
			INT = va_arg(*args, int);
			I_WIDTH_CPY -= ft_strlen(ft_itoa_base(INT, 16));
			I_PRECISION_CPY -= ft_strlen(ft_itoa_base(INT, 16));
		}
		else if (I_MOD_L || I_MOD_LL)
		{
			U_L_INT = va_arg(*args, unsigned long);
			I_WIDTH_CPY -= ft_strlen(ft_litoa_base(U_L_INT, 16));
			I_PRECISION_CPY -= ft_strlen(ft_litoa_base(U_L_INT, 16));
		}
		if (A_PLUS == 1)
			I_WIDTH_CPY--;
		if (A_SPACE == 1)
			I_WIDTH_CPY--;
	}
}

void	conv_binary_b(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'b')
	{
		L_CONV = 'b';
		INT = va_arg(*args, int);
		I_WIDTH_CPY -= ft_strlen(ft_itoa_base(INT, 2));
		I_PRECISION_CPY -= ft_strlen(ft_itoa_base(INT, 2));
		if (A_PLUS == 1)
			I_WIDTH_CPY--;
		if (A_SPACE == 1)
			I_WIDTH_CPY--;
	}
}
