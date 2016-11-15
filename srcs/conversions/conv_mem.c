/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 13:07:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/15 15:21:18 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_mem_p(t_result *result, size_t * i)
{
	char	*format;

	format = result->format;
	if (format[*i] == 'p')
	{
		L_CONV = 'p';
		if (!(STR = ft_itoa_base((long)va_arg(result->ap, int*), 16)))
		{
			L_CONV = 's';
			STR = ft_strdup("0");
			STRLEN = 3;
		}
		else
			STRLEN = ft_strlen(STR);
	}
}
