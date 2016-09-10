/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 16:28:20 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_format(t_args *v_args)
{
	size_t				i;

	i = 0;
	while (v_args->index--)
	{
		print_str_s(v_args, i);
		print_decimal_d(v_args, i);
		print_decimal_ld(v_args, i);
		print_decimal_u(v_args, i);
		print_decimal_lu(v_args, i);
		print_char_c(v_args, i);
		print_hex_x(v_args, i);
		print_hex_lx(v_args, i);
		print_hex_b(v_args, i);
		print_ptr(v_args, i);
		print_octal_o(v_args, i);
		print_octal_lo(v_args, i);
		if (v_args->f_conv[i]->l_conv == '%')
			ft_putstr(v_args->f_conv[i]->type->str);
		i++;
	}
	return (0);
}
