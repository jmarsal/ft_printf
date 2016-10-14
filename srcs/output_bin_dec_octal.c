/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bin_dec_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:55:09 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/14 15:19:54 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_binaire(t_result *result, size_t i)
{
	if (I_L_CONV == 'b')
	{
		if (ft_atoi(I_STR) == INT_MIN)
			RET_STR = ft_strjoin(RET_STR, "10000000000000000000000000000000");
		else
			RET_STR = ft_strjoin(RET_STR, I_STR);
	}
}

static void	print_octal_o(t_result *result, size_t i)
{
	if (I_L_CONV == 'o')
	{
		if (!(MOD_L || MOD_LL || MOD_H || MOD_HH))
			RET_STR = ft_strjoin(RET_STR, I_STR);
		else if (MOD_L || MOD_LL)
			RET_STR = ft_strjoin(RET_STR, I_STR);
		else if (MOD_H || MOD_HH)
			RET_STR = ft_strjoin(RET_STR, I_STR);
	}
}

static void print_decimal_u(t_result *result, size_t i)
{
	if (I_L_CONV == 'u')
	{
		if (!(MOD_L || MOD_LL || MOD_H || MOD_HH))
			RET_STR = ft_strjoin(RET_STR, I_STR);
		else if (MOD_HH || MOD_H)
			RET_STR = ft_strjoin(RET_STR, I_STR);
		else if (MOD_L || MOD_LL)
			RET_STR = ft_strjoin(RET_STR, I_STR);
	}
}

static void	print_decimal_d(t_result *result, size_t i)
{
	if (I_L_CONV == 'd')
	{
		if (!(MOD_L || MOD_LL))
			RET_STR = ft_strjoin(RET_STR, I_STR);
		else if (MOD_L || MOD_LL)
			RET_STR = ft_strjoin(RET_STR, I_STR);
	}
}

void		print_bin_dec_oct(t_result *result, size_t i)
{
	print_decimal_d(result, i);
	print_decimal_u(result, i);
	print_octal_o(result, i);
	print_binaire(result, i);
}
