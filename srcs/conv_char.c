/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:41:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 02:11:55 by jmarsal          ###   ########.fr       */
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
		// v_args->ret_ft_printf++;
	}
}
