/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:28:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/14 23:41:46 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_hex_x(t_result *result, size_t * i)
{
	char	*format;
	int		base;

	format = result->format;
	base = 16;
	if (format[*i] == 'x' || format[*i] == 'X')
	{
		if (I_MOD_HH || I_MOD_H)
		{
			if (I_MOD_HH)
				STR = ft_utoa_base((unsigned char)va_arg(result->ap, int), base);
			else if (I_MOD_H)
				STR = ft_utoa_base((unsigned short)va_arg(result->ap, int), base);
		}
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
			STR = ft_utoa_base((unsigned long)va_arg(result->ap, long), base);
		else
			STR = ft_utoa_base((unsigned int)va_arg(result->ap, int), base);
		format[*i] == 'x' ? get_specifier_and_ajust_width(result, 'x') :
							get_specifier_and_ajust_width(result, 'X');
	}
}