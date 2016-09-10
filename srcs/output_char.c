/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:44:22 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 15:54:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_char_c(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'c')
	{
		// if (v_args->f_conv[i]->caracters->sharp == 1)
		// 	ft_putstr(ERR_SHARP_C);
		ft_putchar(v_args->f_conv[i]->type->c);
	}
}
