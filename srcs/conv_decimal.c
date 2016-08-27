/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/27 01:59:25 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_decimal_d(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && (format[*i + 1] == 'd' || format[*i + 1] == 'i'))
	{
		L_CONV = 'd';
		NB = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa(NB));
	}
}

void	conv_octal_o(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && (format[*i + 1] == 'o'))
	{
		L_CONV = 'o';
		OCT = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa_base(OCT, 8));
	}
}
