/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 13:07:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/11 17:02:32 by jmarsal          ###   ########.fr       */
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
		if (!(PTR = va_arg(result->ap, int*)))
		{
			L_CONV = 's';
			STR = ft_strdup("0x0");
			STRLEN = 3;
		}
	}
}
