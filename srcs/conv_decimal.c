/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/05 00:44:23 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_decimal_d(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'd' || format[*i] == 'i')
	{
		L_CONV = 'd';
		INT = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa(INT));
	}
}

void	conv_decimal_ld(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'D')
	{
		L_CONV = 'D';
		L_INT = va_arg(*args, long int);
		v_args->ret_ft_printf += ft_strlen(ft_litoa(L_INT));
	}
}

void	conv_u_decimal_u(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'u')
	{
		L_CONV = 'u';
		U_INT = va_arg(*args, unsigned int);
		v_args->ret_ft_printf += ft_strlen(ft_litoa(U_INT));
	}
}

void	conv_lu_decimal_lu(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'U')
	{
		L_CONV = 'U';
		U_L_INT = va_arg(*args, unsigned long);
		v_args->ret_ft_printf += ft_strlen(ft_ulitoa(U_L_INT));
	}
}
