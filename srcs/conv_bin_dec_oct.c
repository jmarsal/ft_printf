/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_bin_dec_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/02 23:05:22 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_binary(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'b' && !IS_MODIFIER)
	{
		get_specifier_and_ajust_width('b', v_args);
		INT = va_arg(*args, int);
		ajust_width_precision_itoa_base(v_args, 2);
	}
}

static void	conv_decimal_u(va_list *args, t_args *v_args, const char *format,
					size_t *i)
{
	if (format[*i] == 'u' || format[*i] == 'U')
	{
		I_MOD_L = (format[*i] == 'U') ? 1 : I_MOD_L;
		get_specifier_and_ajust_width('u', v_args);
		if (I_MOD_HH || I_MOD_H)
		{
			 U_INT = I_MOD_HH ? (unsigned char)va_arg(*args, unsigned int) :
								(unsigned short)va_arg(*args, unsigned int);
			ajust_width_precision_itoa_base(v_args, 10);
		}
		else if (!(I_MOD_LL || I_MOD_L || I_MOD_H || I_MOD_HH || I_MOD_J
					|| I_MOD_Z))
		{
			U_INT = va_arg(*args, unsigned int);
			ajust_width_precision_litoa_base(v_args, 10);
		}
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
		{
			U_L_INT = va_arg(*args, unsigned long);
			ajust_width_precision_ulitoa_base(v_args, 10);
		}
	}
}

static void	conv_octal(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'o' || format[*i] == 'O')
	{
		if (format[*i] == 'O')
			I_MOD_L = 1;
		get_specifier_and_ajust_width('o', v_args);
		if (I_MOD_H || I_MOD_HH)
		{
			INT = (I_MOD_H) ? (unsigned short)va_arg(*args, unsigned int) :
								(unsigned char)va_arg(*args, unsigned int);
			ajust_width_precision_itoa_base(v_args, 8);
		}
		else if (!(I_MOD_LL || I_MOD_L || I_MOD_H || I_MOD_HH || I_MOD_J
					|| I_MOD_Z))
		{
			U_INT = va_arg(*args, unsigned int);
			ajust_width_precision_litoa_base(v_args, 8);
		}
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
		{
			U_L_INT = va_arg(*args, unsigned long);
			ajust_width_precision_ulitoa_base(v_args, 8);
		}
	}
}

static void	conv_decimal_d(va_list *args, t_args *v_args, const char *format,
					size_t *i)
{
	if (format[*i] == 'd' || format[*i] == 'i'|| format[*i] == 'D')
	{
		I_MOD_L = (format[*i] == 'D') ? 1 : I_MOD_L;
		get_specifier_and_ajust_width('d', v_args);
		if (L_CONV == 'd' && !(I_MOD_LL || I_MOD_L || I_MOD_J || I_MOD_Z))
		{
			INT = va_arg(*args, int);
			ajust_width_precision_itoa_base(v_args, 10);
		}
		else if (L_CONV == 'd' && (I_MOD_L || I_MOD_LL || I_MOD_J
					|| I_MOD_Z))
		{
			L_INT = va_arg(*args, long);
			ajust_width_precision_litoa_base(v_args, 10);
		}
	}
}

void	conv_bin_dec_oct(va_list *args, t_args *v_args, const char *format,
					size_t *i)
{
	conv_decimal_d(args, v_args, format, i);
	conv_decimal_u(args, v_args, format, i);
	conv_octal(args, v_args, format, i);
	conv_binary(args, v_args, format, i);
}
