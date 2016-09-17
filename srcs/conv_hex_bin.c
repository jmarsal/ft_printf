/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:28:06 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/17 01:35:57 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_hex_x(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'x')
	{
		L_CONV = 'x';
		INT = va_arg(*args, int);
		v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
												ft_strlen(ft_itoa_base(INT, 16));
		v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
												ft_strlen(ft_itoa_base(INT, 16));
		if (A_PLUS == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		if (A_SPACE == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
	}
}

void	conv_hex_lx(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'X')
	{
		L_CONV = 'X';
		INT = va_arg(*args, int);
		v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
												ft_strlen(ft_itoa_base(INT, 16));
		v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
												ft_strlen(ft_itoa_base(INT, 16));
		if (A_PLUS == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		if (A_SPACE == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
	}
}

void	conv_binary_b(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'b')
	{
		L_CONV = 'b';
		INT = va_arg(*args, int);
		v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
			ft_strlen(ft_itoa_base(INT, 2));
		v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
											ft_strlen(ft_itoa_base(INT, 2));
		if (A_PLUS == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		if (A_SPACE == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
	}
}
