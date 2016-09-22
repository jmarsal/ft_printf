/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:55:09 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/22 14:25:09 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	print_decimal_d(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'd')
	{
		if (!(v_args->f_conv[i]->modifier->l ||
				v_args->f_conv[i]->modifier->ll))
			RET_STR = ft_strjoin(RET_STR, ft_itoa(I_INT));
		else if (v_args->f_conv[i]->modifier->l ||
				v_args->f_conv[i]->modifier->ll)
			RET_STR = ft_strjoin(RET_STR, ft_litoa(I_L_INT));
	}
}

void 	print_decimal_ld(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'D')
	{
		RET_STR = ft_strjoin(RET_STR, ft_litoa(I_L_INT));
	}
}

void 	print_decimal_u(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'u')
	{
		if (!(v_args->f_conv[i]->modifier->l ||
				v_args->f_conv[i]->modifier->ll ||
				v_args->f_conv[i]->modifier->h))
			RET_STR = ft_strjoin(RET_STR, ft_litoa(I_U_INT));
		else if (v_args->f_conv[i]->modifier->l ||
				v_args->f_conv[i]->modifier->ll)
			RET_STR = ft_strjoin(RET_STR, ft_ulitoa(I_U_L_INT));
		else if (v_args->f_conv[i]->modifier->h)
			RET_STR = ft_strjoin(RET_STR, ft_itoa(I_U_SHORT));
	}
}

void 	print_decimal_lu(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'U')
	{
		RET_STR = ft_strjoin(RET_STR, ft_ulitoa(I_U_L_INT));
	}
}
