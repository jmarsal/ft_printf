/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_bin_dec_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/13 15:56:10 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_binary(t_result *result, size_t * i)
{
	char	*format;

	format = result->format;
	if (format[*i] == 'b' && !IS_MODIFIER)
	{
		get_specifier_and_ajust_width(result, 'b');
		INT = va_arg(result->ap, int);
		ajust_width_precision_itoa_base(result, 2);
	}
}

static void	conv_decimal_u(t_result *result, size_t *i)
{
	char	*format;

	format = result->format;
	if (format[*i] == 'u' || format[*i] == 'U')
	{
		I_MOD_L = (format[*i] == 'U') ? 1 : I_MOD_L;
		get_specifier_and_ajust_width(result, 'u');
		if (I_MOD_HH || I_MOD_H)
		{
			U_INT = I_MOD_HH ? (unsigned char)va_arg(result->ap, unsigned int) :
							(unsigned short)va_arg(result->ap, unsigned int);
			ajust_width_precision_itoa_base(result, 10);
		}
		else if (!(I_MOD_LL || I_MOD_L || I_MOD_H || I_MOD_HH || I_MOD_J
					|| I_MOD_Z))
		{
			U_INT = va_arg(result->ap, unsigned int);
			ajust_width_precision_litoa_base(result, 10);
		}
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
		{
			U_L_INT = va_arg(result->ap, unsigned long);
			ajust_width_precision_ulitoa_base(result, 10);
		}
	}
}

static void	conv_octal(t_result *result, size_t * i)
{
	char	*format;

	format = result->format;
	if (format[*i] == 'o' || format[*i] == 'O')
	{
		if (format[*i] == 'O')
			I_MOD_L = 1;
		get_specifier_and_ajust_width(result, 'o');
		if (I_MOD_H || I_MOD_HH)
		{
			INT = (I_MOD_H) ? (unsigned short)va_arg(result->ap, unsigned int) :
								(unsigned char)va_arg(result->ap, unsigned int);
			ajust_width_precision_itoa_base(result, 8);
		}
		else if (!(I_MOD_LL || I_MOD_L || I_MOD_H || I_MOD_HH || I_MOD_J
					|| I_MOD_Z))
		{
			U_INT = va_arg(result->ap, unsigned int);
			ajust_width_precision_litoa_base(result, 8);
		}
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
		{
			U_L_INT = va_arg(result->ap, unsigned long);
			ajust_width_precision_ulitoa_base(result, 8);
		}
	}
}

static void	conv_decimal_d(t_result *result, size_t *i)
{
	char	*format;

	format = result->format;
	if (format[*i] == 'd' || format[*i] == 'i'|| format[*i] == 'D')
	{
		I_MOD_L = (format[*i] == 'D') ? 1 : I_MOD_L;
		get_specifier_and_ajust_width(result, 'd');
		if (L_CONV == 'd' && !(I_MOD_LL || I_MOD_L || I_MOD_J || I_MOD_Z))
		{
			INT = va_arg(result->ap, int);
			ajust_width_precision_itoa_base(result, 10);
		}
		else if (L_CONV == 'd' && (I_MOD_L || I_MOD_LL || I_MOD_J
					|| I_MOD_Z))
		{
			L_INT = va_arg(result->ap, long);
			ajust_width_precision_litoa_base(result, 10);
		}
	}
}

void	conv_bin_dec_oct(t_result *result, size_t *i)
{
	conv_decimal_d(result, i);
	conv_decimal_u(result, i);
	conv_octal(result, i);
	conv_binary(result, i);
}
