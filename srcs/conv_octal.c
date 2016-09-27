/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 16:59:20 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/27 02:11:02 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_octal_o(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'o')
	{
		if (!(I_MOD_LL || I_MOD_L || I_MOD_H || I_MOD_HH))
		{
			L_CONV = 'o';
			U_INT = va_arg(*args, unsigned int);
			if (A_PLUS == 1)
				I_WIDTH_CPY--;
			if (A_SPACE == 1)
				I_WIDTH_CPY--;
			I_WIDTH_CPY -=
				ft_strlen(ft_litoa_base(U_INT, 8));
			I_PRECISION_CPY -=
				ft_strlen(ft_litoa_base(U_INT, 8));
	}
	}
}

void	conv_octal_lo(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if ((format[*i] == 'O' || ((format[*i] == 'o') && (I_MOD_L || I_MOD_LL))))
	{
		L_CONV = 'O';
		U_L_INT = va_arg(*args, unsigned long);
		if (A_PLUS == 1)
			I_WIDTH_CPY--;
		if (A_SPACE == 1)
			I_WIDTH_CPY--;
		I_WIDTH_CPY -=
			ft_strlen(ft_ulitoa_base(U_L_INT, 8));
		I_PRECISION_CPY -=
			ft_strlen(ft_ulitoa_base(U_L_INT, 8));
	}
}

void	conv_octal_ho(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'o')
	{
		if (I_MOD_H || I_MOD_HH)
		{
			L_CONV = 'o';
			if (I_MOD_H)
				INT = (unsigned short)va_arg(*args, unsigned int);
			else if (I_MOD_HH)
				INT = (unsigned char)va_arg(*args, unsigned int);
			I_WIDTH_CPY -= ft_strlen(ft_itoa_base(INT, 8));
			I_PRECISION_CPY -= ft_strlen(ft_itoa_base(INT, 8));
			if (A_PLUS == 1)
				I_WIDTH_CPY--;
			if (A_SPACE == 1)
				I_WIDTH_CPY--;
		}
	}
}
