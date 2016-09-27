/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:41:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/27 01:32:13 by jmarsal          ###   ########.fr       */
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
		I_WIDTH_CPY -= ft_strlen(ft_itoa(C));
		I_PRECISION_CPY -= ft_strlen(ft_itoa(C));
		if (A_PLUS == 1)
			I_WIDTH_CPY--;
		if (A_SPACE == 1)
			I_WIDTH_CPY--;
	}
}
