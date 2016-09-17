/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 16:59:20 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/17 01:37:59 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_octal_o(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'o')
	{
		L_CONV = 'o';
		U_INT = va_arg(*args, unsigned int);
		if (A_PLUS == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		if (A_SPACE == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
			ft_strlen(ft_itoa_base(U_INT, 8));
		v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
			ft_strlen(ft_itoa_base(U_INT, 8));
	}
}

void	conv_octal_lo(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'O')
	{
		L_CONV = 'O';
		U_L_INT = va_arg(*args, unsigned long int);
		if (A_PLUS == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		if (A_SPACE == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
			ft_strlen(ft_itoa_base(U_L_INT, 8));
		v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
			ft_strlen(ft_itoa_base(U_L_INT, 8));
	}
}
