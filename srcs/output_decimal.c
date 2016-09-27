/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:55:09 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/27 01:50:58 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	print_decimal_d(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'd')
	{
		if (!(MOD_L || MOD_LL))
			RET_STR = ft_strjoin(RET_STR, ft_itoa(I_INT));
		else if (MOD_L || MOD_LL)
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
		if (!(MOD_L || MOD_LL || MOD_H || MOD_HH))
			RET_STR = ft_strjoin(RET_STR, ft_litoa(I_U_INT));
		else if (MOD_L || MOD_LL)
			RET_STR = ft_strjoin(RET_STR, ft_ulitoa(I_U_L_INT));
		else if (MOD_H)
			RET_STR = ft_strjoin(RET_STR, ft_itoa(I_U_INT));
		else if (MOD_HH)
			RET_STR = ft_strjoin(RET_STR, ft_itoa(I_U_INT));
	}
}

void 	print_decimal_lu(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'U')
	{
		RET_STR = ft_strjoin(RET_STR, ft_ulitoa(I_U_L_INT));
	}
}
