/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 22:53:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/29 00:36:06 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ajust_width_precision_itoa_base(t_args *v_args, int base)
{
	if (L_CONV == 'd' || L_CONV == 'x' || L_CONV == 'X' || L_CONV == 'b' ||
		(L_CONV == 'o' && (I_MOD_H || I_MOD_HH)))
	{
		I_WIDTH_CPY -= ft_strlen(ft_itoa_base(INT, base));
		I_PRECISION_CPY -= ft_strlen(ft_itoa_base(INT, base));
	}
	else if (L_CONV == 'c')
	{
		I_WIDTH_CPY -= ft_strlen(ft_itoa_base(C, base));
		I_PRECISION_CPY -= ft_strlen(ft_itoa_base(C, base));
	}
	else if (L_CONV == 'u' && (I_MOD_H || I_MOD_HH))
	{
		I_WIDTH_CPY -= ft_strlen(ft_itoa(U_INT));
		I_PRECISION_CPY -= ft_strlen(ft_itoa(U_INT));
	}
}

void	ajust_width_precision_litoa_base(t_args *v_args, int base)
{
	if (L_CONV != 'u' && L_CONV != 'x' && L_CONV != 'X' && L_CONV != 'o')
	{
		I_WIDTH_CPY -= ft_strlen(ft_litoa_base(L_INT, base));
		I_PRECISION_CPY -= ft_strlen(ft_litoa_base(L_INT, base));
	}
	else if ((L_CONV == 'u' || L_CONV == 'o')
			&& !(I_MOD_LL || I_MOD_L || I_MOD_H || I_MOD_HH))
	{
		I_WIDTH_CPY -= ft_strlen(ft_litoa_base(U_INT, base));
		I_PRECISION_CPY -= ft_strlen(ft_litoa_base(U_INT, base));
	}
	else if ((L_CONV == 'x' || L_CONV == 'X') && (I_MOD_L || I_MOD_LL))
	{
		I_WIDTH_CPY -= ft_strlen(ft_litoa_base(U_L_INT, base));
		I_PRECISION_CPY -= ft_strlen(ft_litoa_base(U_L_INT, base));
	}
}

void	ajust_width_precision_ulitoa_base(t_args *v_args, int base)
{
	if (L_CONV == 'U' || (L_CONV == 'u' && (I_MOD_L || I_MOD_LL)))
	{
		I_WIDTH_CPY -= ft_strlen(ft_ulitoa_base(U_L_INT, base));
		I_PRECISION_CPY -= ft_strlen(ft_itoa_base(U_L_INT, base));
	}
	else if (L_CONV == 'O' || (L_CONV == 'o' && (I_MOD_L || I_MOD_LL)))
	{
		I_WIDTH_CPY -= ft_strlen(ft_ulitoa_base(U_L_INT, base));
		I_PRECISION_CPY -= ft_strlen(ft_ulitoa_base(U_L_INT, base));
	}
}

void	get_specifier_and_ajust_width(char specifier, t_args *v_args)
{
	if (A_PLUS == 1)
		I_WIDTH_CPY--;
	if (A_SPACE == 1)
		I_WIDTH_CPY--;
	L_CONV = specifier;
}
