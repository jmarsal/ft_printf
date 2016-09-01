/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/31 18:01:30 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_decimal_d(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && (format[*i + 1] == 'd' || format[*i + 1] == 'i'))
	{
		L_CONV = 'd';
		INT = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa(INT));
	}
}

void	conv_decimal_ld(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && format[*i + 1] == 'D')
	{
		L_CONV = 'D';
		L_INT = va_arg(*args, long int);
		v_args->ret_ft_printf += ft_strlen(ft_litoa(L_INT));
	}
}

void	conv_u_decimal_u(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && (format[*i + 1] == 'u'))
	{
		L_CONV = 'u';
		U_INT = va_arg(*args, unsigned int);
		v_args->ret_ft_printf += ft_strlen(ft_litoa(U_INT));
	}
}

void	conv_lu_decimal_lu(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && (format[*i + 1] == 'U'))
	{
		L_CONV = 'U';
		U_L_INT = va_arg(*args, unsigned long);
		v_args->ret_ft_printf += ft_strlen(ft_ulitoa(U_L_INT));
	}
}
