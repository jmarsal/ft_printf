/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:38:50 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/12 00:46:26 by jmarsal          ###   ########.fr       */
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
	}
}
