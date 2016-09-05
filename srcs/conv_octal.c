/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 16:59:20 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/05 00:47:18 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_octal_o(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'o')
	{
		L_CONV = 'o';
		INT = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa_base(INT, 8));
	}
}

void	conv_octal_lo(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'O')
	{
		L_CONV = 'O';
		L_INT = va_arg(*args, long int);
		v_args->ret_ft_printf += ft_strlen(ft_litoa_base(L_INT, 8));
	}
}
