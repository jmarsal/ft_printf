/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:55:09 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/14 02:20:42 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	print_decimal_d(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'd')
	{
		RET_STR = ft_strcat(RET_STR, ft_itoa(v_args->f_conv[i]->type->nb));
	}
}

void 	print_decimal_ld(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'D')
	{
		RET_STR = ft_strcat(RET_STR, ft_litoa(v_args->f_conv[i]->type->l_nb));
	}
}

void 	print_decimal_u(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'u')
	{
		RET_STR = ft_strcat(RET_STR, ft_litoa(v_args->f_conv[i]->type->u_nb));
	}
}

void 	print_decimal_lu(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'U')
	{
		RET_STR = ft_strcat(RET_STR, ft_ulitoa(v_args->f_conv[i]->type->u_l_nb));
	}
}
