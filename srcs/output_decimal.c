/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:55:09 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 16:30:32 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	print_decimal_d(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'd')
	{
		// if (v_args->f_conv[i]->caracters->sharp == 1)
		// {
		// 	ft_putstr(ERR_SHARP_D);
		// 	return (-1);
		// }
		// if ((v_args->f_conv[i]->is_width == 1 && v_args->f_conv[i]->is_precision != 1) ||
		// 	(v_args->f_conv[i]->is_width == 0 && v_args->f_conv[i]->is_precision != 0))
		// 	v_args->f_conv[i]->f_width -=
		// 					ft_strlen(ft_itoa(v_args->f_conv[i]->nb));
		// if (v_args->f_conv[i]->caracters->space == 1 &&
		// 	v_args->f_conv[i]->is_width != 0)
		// 	v_args->f_conv[i]->f_width -= 1;
		// if (v_args->f_conv[i]->caracters->plus == 1 &&
		// 	v_args->f_conv[i]->is_width != 0)
		// 	v_args->f_conv[i]->f_width -= 1;
		// is_caracters_is_space(v_args, i);
		// is_caracters_is_positive(v_args, i);
		// is_width_in_format(v_args, i);
		ft_putnbr(v_args->f_conv[i]->type->nb);
		// is_caracters_is_neg_and_precision(v_args, i);
	}
}

void 	print_decimal_ld(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'D')
	{
		// if (v_args->f_conv[i]->caracters->sharp == 1)
		// {
		// 	ft_putstr(ERR_SHARP_LD);
		// 	return (-1);
		// }
		// v_args->f_conv[i]->f_width -=
		// 					ft_strlen(ft_itoa(v_args->f_conv[i]->l_nb));
		// if (v_args->f_conv[i]->caracters->space == 1 &&
		// 	v_args->f_conv[i]->is_width != 0)
		// 	v_args->f_conv[i]->f_width -= 1;
		// if (v_args->f_conv[i]->caracters->plus == 1 &&
		// 	v_args->f_conv[i]->is_width != 0)
		// 	v_args->f_conv[i]->f_width -= 1;
		// is_caracters_is_space(v_args, i);
		// is_caracters_is_positive(v_args, i);
		// is_width_in_format(v_args, i);
		ft_putlnbr(v_args->f_conv[i]->type->l_nb);
		// is_caracters_is_neg_and_precision(v_args, i);
	}
}

void 	print_decimal_u(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'u')
	{
		// if (v_args->f_conv[i]->caracters->sharp == 1)
		// {
		// 	ft_putstr(ERR_SHARP_U);
		// 	return (-1);
		// }
		// v_args->f_conv[i]->f_width -=
		// 					ft_strlen(ft_itoa(v_args->f_conv[i]->u_nb));
		// is_width_in_format(v_args, i);
		ft_putlnbr(v_args->f_conv[i]->type->u_nb);
		// is_caracters_is_neg_and_precision(v_args, i);
	}
}

void 	print_decimal_lu(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'U')
	{
		// if (v_args->f_conv[i]->caracters->sharp == 1)
		// {
		// 	ft_putstr(ERR_SHARP_LU);
		// 	return (-1);
		// }
		// v_args->f_conv[i]->f_width -=
		// 					ft_strlen(ft_ulitoa(v_args->f_conv[i]->u_l_nb));
		// is_width_in_format(v_args, i);
		ft_putstr(ft_ulitoa(v_args->f_conv[i]->type->u_l_nb));
		// is_caracters_is_neg_and_precision(v_args, i);
	}
}
