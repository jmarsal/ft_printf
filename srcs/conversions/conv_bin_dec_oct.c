/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_bin_dec_oct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/28 18:03:43 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_binary(t_result *result, size_t *i)
{
	char	*format;
	int		base;

	format = result->format;
	base = 2;
	if (format[*i] == 'b' && !IS_MODIFIER)
	{
		STR = ft_itoa_base((unsigned int)va_arg(R_AP, int), base);
		get_specifier_and_ajust_width(result, 'b');
	}
}

static void	conv_decimal_u(t_result *result, size_t *i)
{
	char	*format;
	int		base;

	format = result->format;
	base = 10;
	if (format[*i] == 'u' || format[*i] == 'U')
	{
		if (format[*i] == 'U')
		{
			reset_flags_struct(result);
			I_MOD_L = (format[*i] == 'U') ? 1 : I_MOD_L;
		}
		if (I_MOD_HH || I_MOD_H)
		{
			STR = I_MOD_HH ?
				ft_utoa_base((unsigned char)va_arg(R_AP, int), base) :
				ft_utoa_base((unsigned short)va_arg(R_AP, int), base);
		}
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
			STR = ft_utoa_base((unsigned long)va_arg(R_AP, long), base);
		else
			STR = ft_utoa_base((unsigned int)va_arg(R_AP, int), base);
		get_specifier_and_ajust_width(result, 'u');
	}
}

static void	conv_octal(t_result *result, size_t *i)
{
	char	*format;
	int		base;

	format = result->format;
	base = 8;
	if (format[*i] == 'o' || format[*i] == 'O')
	{
		if (format[*i] == 'O')
			reset_flags_struct(result);
		I_MOD_L = (format[*i] == 'O') ? 1 : I_MOD_L;
		if (I_MOD_H || I_MOD_HH)
			STR = (I_MOD_H) ?
				ft_utoa_base((unsigned short)va_arg(R_AP, int), base) :
				ft_utoa_base((unsigned char)va_arg(R_AP, int), base);
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
			STR = ft_utoa_base((unsigned long)va_arg(R_AP, long), base);
		else
			STR = ft_utoa_base((unsigned int)va_arg(R_AP, int), base);
		get_specifier_and_ajust_width(result, 'o');
	}
}

static void	conv_decimal_d(t_result *result, size_t *i)
{
	char	*format;
	int		base;

	format = result->format;
	base = 10;
	if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'D')
	{
		if (format[*i] == 'D')
			reset_flags_struct(result);
		I_MOD_L = (format[*i] == 'D') ? 1 : I_MOD_L;
		if (I_MOD_HH || I_MOD_H)
		{
			if (I_MOD_HH)
				STR = ft_itoa_base((signed char)va_arg(R_AP, int), base);
			else if (I_MOD_H)
				STR = ft_itoa_base((short)va_arg(R_AP, int), base);
		}
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
			STR = ft_itoa_base(va_arg(R_AP, long), base);
		else
			STR = ft_itoa_base(va_arg(R_AP, int), base);
		get_specifier_and_ajust_width(result, 'd');
	}
}

void		conv_bin_dec_oct(t_result *result, size_t *i)
{
	char	*format;

	format = result->format;
	ft_free(STR);
	if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'D')
		conv_decimal_d(result, i);
	else if (format[*i] == 'u' || format[*i] == 'U')
		conv_decimal_u(result, i);
	else if (format[*i] == 'o' || format[*i] == 'O')
		conv_octal(result, i);
	else if (format[*i] == 'b')
		conv_binary(result, i);
}
