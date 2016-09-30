/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bin_dec_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:55:09 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/29 02:48:01 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_binaire(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'b')
	{
		if (I_INT == INT_MIN)
			RET_STR = ft_strjoin(RET_STR, "10000000000000000000000000000000");
		else
			RET_STR = ft_strjoin(RET_STR, ft_litoa_base(I_INT, 2));
	}
}

static void	print_octal_o(t_args *v_args, size_t i)
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

static void print_decimal_u(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'u')
	{
		if (!(MOD_L || MOD_LL || MOD_H || MOD_HH))
			RET_STR = ft_strjoin(RET_STR, ft_litoa(I_U_INT));
		else if (MOD_HH || MOD_H)
			RET_STR = ft_strjoin(RET_STR, ft_itoa(I_U_INT));
		else if (MOD_L || MOD_LL)
			RET_STR = ft_strjoin(RET_STR, ft_ulitoa(I_U_L_INT));
	}
}

static void	print_decimal_d(t_args *v_args, size_t i)
{
	if (I_L_CONV == 'd')
	{
		if (!(MOD_L || MOD_LL))
			RET_STR = ft_strjoin(RET_STR, ft_itoa(I_INT));
		else if (MOD_L || MOD_LL)
			RET_STR = ft_strjoin(RET_STR, ft_litoa(I_L_INT));
	}
}

void		print_bin_dec_oct(t_args *v_args, size_t i)
{
	print_decimal_d(v_args, i);
	print_decimal_u(v_args, i);
	print_octal_o(v_args, i);
	print_binaire(v_args, i);
}
