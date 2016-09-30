/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:38:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/29 02:28:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_char_c(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'c')
	{
		get_specifier_and_ajust_width('c', v_args);
		C = (char)va_arg(*args, int);
		ajust_width_precision_itoa_base(v_args, 10);
	}
}

void		conv_str_s(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 's')
	{
		get_specifier_and_ajust_width('s', v_args);
		STR = ft_strdup(va_arg(*args, char *));
		I_WIDTH_CPY -= ft_strlen(STR);
		I_PRECISION_CPY -= ft_strlen(STR);
	}
	conv_char_c(args, v_args, format, i);
}
