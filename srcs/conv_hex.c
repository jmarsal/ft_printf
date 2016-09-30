/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:28:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/29 15:57:09 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_hex_x(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'x' || format[*i] == 'X')
	{
		format[*i] == 'x' ? get_specifier_and_ajust_width('x', v_args) :
							get_specifier_and_ajust_width('X', v_args);
		if (!(I_MOD_LL || I_MOD_L))
		{
			INT = va_arg(*args, int);
			ajust_width_precision_itoa_base(v_args, 16);
		}
		else if (I_MOD_L || I_MOD_LL)
		{
			U_L_INT = va_arg(*args, unsigned long);
			ajust_width_precision_litoa_base(v_args, 16);
		}
	}
}
