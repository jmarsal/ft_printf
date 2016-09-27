/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:38:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/27 01:56:07 by jmarsal          ###   ########.fr       */
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
		I_WIDTH_CPY -= ft_strlen(STR);
		I_PRECISION_CPY -= ft_strlen(STR);
		if (A_PLUS == 1)
			I_WIDTH_CPY--;
		if (A_SPACE == 1)
			I_WIDTH_CPY--;
	}
}
