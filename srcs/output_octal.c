/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:12:52 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/27 01:55:34 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_octal_o(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'o')
	{
		if (!(MOD_L || MOD_LL || MOD_H || MOD_HH))
			RET_STR = ft_strjoin(RET_STR, ft_litoa_base(I_U_INT, 8));
		else if (MOD_L || MOD_LL)
			RET_STR = ft_strjoin(RET_STR, ft_ulitoa_base(I_U_L_INT, 8));
		else if (MOD_H || MOD_HH)
			RET_STR = ft_strjoin(RET_STR, ft_itoa_base(I_INT, 8));
	}
}

void	print_octal_lo(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'O')
	{
		RET_STR = ft_strjoin(RET_STR, ft_ulitoa_base(I_U_L_INT, 8));
	}
}
