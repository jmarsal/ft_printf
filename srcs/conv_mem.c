/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 13:07:46 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/27 00:06:00 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_mem_p(va_list *args, t_v_args *v_args, const char *format,
					size_t * i)
{
	int	tmp;

	if (format[*i + 1] && format[*i + 1] == 'p')
	{
		L_CONV = 'p';
		// printf("L_CONV = %c\n", L_CONV);
		// printf("v_args->f_conv[i]->l_conv = %c\n", v_args->f_conv[v_args->i_args]->l_conv);
		tmp = va_arg(*args, int);
		// printf("%p\n", tmp);
		PTR = &tmp;
	}
}
