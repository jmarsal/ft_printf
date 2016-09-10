/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:05:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 16:30:08 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_hex_x(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'x')
	{
		// v_args->f_conv[i]->f_width -=
		// 					ft_strlen(ft_itoa(v_args->f_conv[i]->nb));
		// if (v_args->f_conv[i]->caracters->sharp == 1)
		// 	v_args->f_conv[i]->f_width -= 1;
		// if (v_args->f_conv[i]->is_width == 1)
		// 	v_args->f_conv[i]->f_width -= 1;
		// is_width_in_format(v_args, i);
		// is_caracters_is_sharp(v_args, i);
		ft_putstr(ft_strtolower(ft_itoa_base(v_args->f_conv[i]->type->nb, 16)));
		// is_caracters_is_neg_and_precision(v_args, i);
	}
}

void	print_hex_lx(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'X')
	{
		// v_args->f_conv[i]->f_width -=
		// 					ft_strlen(ft_itoa(v_args->f_conv[i]->nb));
		// is_width_in_format(v_args, i);
		// is_caracters_is_sharp(v_args, i);
		ft_putstr(ft_itoa_base(v_args->f_conv[i]->type->nb, 16));
		// is_caracters_is_neg_and_precision(v_args, i);
	}
}

void	print_hex_b(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'b')
	{
		// if (v_args->f_conv[i]->caracters->sharp == 1)
		// {
		// 	ft_putstr(ERR_SHARP_B);
		// 	return (-1);
		// }
		ft_putstr(ft_itoa_base(v_args->f_conv[i]->type->nb, 2));
	}
}
