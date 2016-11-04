/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 13:07:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/04 14:16:51 by jmarsal          ###   ########.fr       */
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
			STR = ft_strdup("(null)");
	}
}
