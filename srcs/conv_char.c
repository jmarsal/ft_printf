/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:41:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/17 01:33:06 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_char_c(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'c')
	{
		L_CONV = 'c';
		C = va_arg(*args, int);
		v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
												ft_strlen(ft_itoa(C));
		v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
												ft_strlen(ft_itoa(C));
		if (A_PLUS == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		if (A_SPACE == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
	}
}
