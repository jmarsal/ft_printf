/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:12:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 16:30:52 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_octal_o(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'o')
	{
		// v_args->f_conv[i]->f_width -=
		// 					ft_strlen(ft_itoa(v_args->f_conv[i]->u_nb));
		// is_width_in_format(v_args, i);
		// is_caracters_is_sharp(v_args, i);
		ft_putstr(ft_itoa_base(v_args->f_conv[i]->type->u_nb, 8));
		// is_caracters_is_neg_and_precision(v_args, i);
	}
}

void	print_octal_lo(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'O')
	{
		// v_args->f_conv[i]->f_width -=
		// 					ft_strlen(ft_itoa(v_args->f_conv[i]->u_l_nb));
		// is_width_in_format(v_args, i);
		// is_caracters_is_sharp(v_args, i);
		ft_putstr(ft_litoa_base(v_args->f_conv[i]->type->u_l_nb, 8));
		// is_caracters_is_neg_and_precision(v_args, i);
	}
}
