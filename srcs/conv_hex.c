/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:28:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 16:02:55 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_hex_x(va_list *ap, t_result *result, const char *format,
					size_t * i)
{
	if (format[*i] == 'x' || format[*i] == 'X')
	{
		format[*i] == 'x' ? get_specifier_and_ajust_width('x', result) :
							get_specifier_and_ajust_width('X', result);
		if (!(I_MOD_LL || I_MOD_L || I_MOD_J || I_MOD_Z))
		{
			INT = va_arg(*ap, int);
			ajust_width_precision_itoa_base(result, 16);
		}
		else if (I_MOD_L || I_MOD_LL || I_MOD_J || I_MOD_Z)
		{
			U_L_INT = va_arg(*ap, unsigned long);
			ajust_width_precision_litoa_base(result, 16);
		}
	}
}
