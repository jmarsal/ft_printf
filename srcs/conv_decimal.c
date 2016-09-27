/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/27 01:50:33 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/21 23:45:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_decimal_d(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'd' || format[*i] == 'i')
	{
		L_CONV = 'd';
		if (!(I_MOD_LL || I_MOD_L))
		{
			INT = va_arg(*args, int);
			I_WIDTH_CPY -= ft_strlen(ft_itoa(INT));
			I_PRECISION_CPY -= ft_strlen(ft_itoa(INT));
		}
		else if (I_MOD_L || I_MOD_LL)
		{
			L_INT = va_arg(*args, long);
			I_WIDTH_CPY -= ft_strlen(ft_litoa(L_INT));
			I_PRECISION_CPY -= ft_strlen(ft_litoa(L_INT));
		}
		if (A_PLUS == 1)
			I_WIDTH_CPY--;
		if (A_SPACE == 1)
			I_WIDTH_CPY--;
	}
}

void	conv_decimal_ld(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'D')
	{
		L_CONV = 'D';
		L_INT = va_arg(*args, long int);
		I_WIDTH_CPY -= ft_strlen(ft_litoa(L_INT));
		I_PRECISION_CPY -= ft_strlen(ft_itoa(L_INT));
		if (A_PLUS == 1)
			I_WIDTH_CPY--;
		if (A_SPACE == 1)
			I_WIDTH_CPY--;
	}
}

void	conv_u_decimal_u(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'u')
	{
		if (!(I_MOD_LL || I_MOD_L || I_MOD_H || I_MOD_HH))
		{
			L_CONV = 'u';
			U_INT = va_arg(*args, unsigned int);
			I_WIDTH_CPY -= ft_strlen(ft_litoa(U_INT));
			I_PRECISION_CPY -= ft_strlen(ft_itoa(U_INT));
			if (A_PLUS == 1)
				I_WIDTH_CPY--;
			if (A_SPACE == 1)
				I_WIDTH_CPY--;
		}
	}
}

void	conv_lu_decimal_lu(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'U' || (format[*i] == 'u' && (I_MOD_L || I_MOD_LL)))
	{
		L_CONV = 'U';
		U_L_INT = va_arg(*args, unsigned long);
		I_WIDTH_CPY -= ft_strlen(ft_ulitoa(U_L_INT));
		I_PRECISION_CPY -= ft_strlen(ft_itoa(U_L_INT));
		if (A_PLUS == 1)
			I_WIDTH_CPY--;
		if (A_SPACE == 1)
			I_WIDTH_CPY--;
	}
}

void	conv_u_decimal_hu(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'u')
	{
		if (I_MOD_H)
		{
			L_CONV = 'u';
			U_INT = (unsigned short)va_arg(*args, unsigned int);
			I_WIDTH_CPY -= ft_strlen(ft_itoa(U_INT));
			I_PRECISION_CPY -= ft_strlen(ft_itoa(U_INT));
			if (A_PLUS == 1)
				I_WIDTH_CPY--;
			if (A_SPACE == 1)
				I_WIDTH_CPY--;
		}
		else if (I_MOD_HH)
		{
			L_CONV = 'u';
			U_INT = (unsigned char)va_arg(*args, unsigned int);
			I_WIDTH_CPY -= ft_strlen(ft_itoa(U_INT));
			I_PRECISION_CPY -= ft_strlen(ft_itoa(U_INT));
			if (A_PLUS == 1)
				I_WIDTH_CPY--;
			if (A_SPACE == 1)
				I_WIDTH_CPY--;
		}
	}
}
