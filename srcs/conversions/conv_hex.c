/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:28:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/18 23:18:13 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_hex_h_hh(t_result *result, int base)
{
	if (I_MOD_HH)
	{
		if (!(STR = ft_utoa_base((unsigned char)va_arg(R_AP, int), base)))
			STR = ft_strdup("(null)");
	}
	else if (I_MOD_H)
	{
		if (!(STR = ft_utoa_base((unsigned short)va_arg(R_AP, int), base)))
			STR = ft_strdup("(null)");
	}
}

void	conv_hex_x(t_result *result, size_t * i)
{
	char	*format;
	int		base;

	format = result->format;
	base = 16;
	if (format[*i] == 'x' || format[*i] == 'X')
	{
		if (I_MOD_HH || I_MOD_H)
			conv_hex_h_hh(result, base);
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
		{
			if (!(STR = ft_utoa_base((unsigned long)va_arg(R_AP, long), base)))
				STR = ft_strdup("(null)");
		}
		else
		{
			if (!(STR = ft_utoa_base((unsigned int)va_arg(R_AP, int), base)))
				STR = ft_strdup("(null)");
		}
		format[*i] == 'x' ? get_specifier_and_ajust_width(result, 'x') :
							get_specifier_and_ajust_width(result, 'X');
	}
}
