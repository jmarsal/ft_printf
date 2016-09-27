/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:05:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/23 01:36:09 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_hex_x(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'x')
	{
		if (!v_args->f_conv[i]->is_modifier)
			RET_STR = ft_strjoin(RET_STR,
				ft_strtolower(ft_itoa_base(I_INT, 16)));
		else if (MOD_HH == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 2));
		else if (MOD_H == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 4));
		else if (MOD_L == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 16));
		else if (MOD_LL == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 64));

	}
}

void	print_hex_maj_x(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'X')
	{
		if (!v_args->f_conv[i]->is_modifier)
			RET_STR = ft_strjoin(RET_STR,
							ft_itoa_base(I_INT, 16));
		else if (MOD_HH == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 2));
		else if (MOD_H == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 4));
		else if (MOD_L == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 16));
		else if (MOD_LL == 1)
			RET_STR = ft_strjoin(RET_STR, modifier_x(v_args, i, 64));
	}
}

void	print_hex_b(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'b')
	{
		if (I_INT == INT_MIN)
			RET_STR = ft_strjoin(RET_STR, "10000000000000000000000000000000");
		else
			RET_STR = ft_strjoin(RET_STR, ft_itoa_base(I_INT, 2));
	}
}
