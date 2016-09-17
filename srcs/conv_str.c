/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:38:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/17 01:39:11 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_str_s(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 's')
	{
		L_CONV = 's';
		STR = ft_strdup(va_arg(*args, char *));
		v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
												ft_strlen(STR);
		v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
												ft_strlen(STR);
		if (A_PLUS == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		if (A_SPACE == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
	}
}
