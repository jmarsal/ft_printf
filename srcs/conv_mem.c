/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 13:07:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/25 00:57:11 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_mem_p(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i + 1] && format[*i + 1] == 'p')
	{
		L_CONV = 'p';
		P = va_arg(*args, int);
	}
}
