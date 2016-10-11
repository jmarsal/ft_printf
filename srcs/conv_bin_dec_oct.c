/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_bin_dec_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 16:03:11 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_binary(va_list *ap, t_result *result, const char *format,
					size_t * i)
{
	if (format[*i] == 'b' && !IS_MODIFIER)
	{
		get_specifier_and_ajust_width('b', result);
		INT = va_arg(*ap, int);
		ajust_width_precision_itoa_base(result, 2);
	}
}

static void	conv_decimal_u(va_list *ap, t_result *result, const char *format,
					size_t *i)
{
	if (format[*i] == 'u' || format[*i] == 'U')
	{
		I_MOD_L = (format[*i] == 'U') ? 1 : I_MOD_L;
		get_specifier_and_ajust_width('u', result);
		if (I_MOD_HH || I_MOD_H)
		{
			 U_INT = I_MOD_HH ? (unsigned char)va_arg(*ap, unsigned int) :
								(unsigned short)va_arg(*ap, unsigned int);
			ajust_width_precision_itoa_base(result, 10);
		}
		else if (!(I_MOD_LL || I_MOD_L || I_MOD_H || I_MOD_HH || I_MOD_J
					|| I_MOD_Z))
		{
			U_INT = va_arg(*ap, unsigned int);
			ajust_width_precision_litoa_base(result, 10);
		}
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
		{
			U_L_INT = va_arg(*ap, unsigned long);
			ajust_width_precision_ulitoa_base(result, 10);
		}
	}
}

static void	conv_octal(va_list *ap, t_result *result, const char *format,
					size_t * i)
{
	if (format[*i] == 'o' || format[*i] == 'O')
	{
		if (format[*i] == 'O')
			I_MOD_L = 1;
		get_specifier_and_ajust_width('o', result);
		if (I_MOD_H || I_MOD_HH)
		{
			INT = (I_MOD_H) ? (unsigned short)va_arg(*ap, unsigned int) :
								(unsigned char)va_arg(*ap, unsigned int);
			ajust_width_precision_itoa_base(result, 8);
		}
		else if (!(I_MOD_LL || I_MOD_L || I_MOD_H || I_MOD_HH || I_MOD_J
					|| I_MOD_Z))
		{
			U_INT = va_arg(*ap, unsigned int);
			ajust_width_precision_litoa_base(result, 8);
		}
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
		{
			U_L_INT = va_arg(*ap, unsigned long);
			ajust_width_precision_ulitoa_base(result, 8);
		}
	}
}

static void	conv_decimal_d(va_list *ap, t_result *result, const char *format,
					size_t *i)
{
	if (format[*i] == 'd' || format[*i] == 'i'|| format[*i] == 'D')
	{
		I_MOD_L = (format[*i] == 'D') ? 1 : I_MOD_L;
		get_specifier_and_ajust_width('d', result);
		if (L_CONV == 'd' && !(I_MOD_LL || I_MOD_L || I_MOD_J || I_MOD_Z))
		{
			INT = va_arg(*ap, int);
			ajust_width_precision_itoa_base(result, 10);
		}
		else if (L_CONV == 'd' && (I_MOD_L || I_MOD_LL || I_MOD_J
					|| I_MOD_Z))
		{
			L_INT = va_arg(*ap, long);
			ajust_width_precision_litoa_base(result, 10);
		}
	}
}

void	conv_bin_dec_oct(va_list *ap, t_result *result, const char *format,
					size_t *i)
{
	conv_decimal_d(ap, result, format, i);
	conv_decimal_u(ap, result, format, i);
	conv_octal(ap, result, format, i);
	conv_binary(ap, result, format, i);
}
