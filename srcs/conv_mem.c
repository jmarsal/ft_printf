/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 13:07:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/23 13:10:02 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_mem_p(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && format[*i + 1] == 'p')
	{
		L_CONV = 'p';
		HEX = va_arg(*args, int);
		v_args->ret_ft_printf += ft_strlen(ft_itoa_base(HEX, 16));
	}
}
