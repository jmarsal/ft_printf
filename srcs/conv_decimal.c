/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/29 22:35:55 by jmarsal          ###   ########.fr       */
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

void	conv_decimal_ld(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && format[*i + 1] == 'D')
	{
		L_CONV = 'D';
		L_NB = va_arg(*args, long int);
		v_args->ret_ft_printf += ft_strlen(ft_litoa(L_NB));
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

void	conv_octal_lo(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && (format[*i + 1] == 'O'))
	{
		L_CONV = 'O';
		L_OCT = va_arg(*args, long int);
		v_args->ret_ft_printf += ft_strlen(ft_litoa_base(L_OCT, 8));
	}
}
