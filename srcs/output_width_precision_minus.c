/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_width_precision_minus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:32:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 16:02:26 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	if_l_conv_u(t_result *result, size_t i)
{
	if (!I_IS_MODIFIER)
	{
		while ((int)ft_strlen(RET_STR) +
				(int)ft_strlen(ft_itoa(I_U_INT)) <= PRECISION_O)
			RET_STR = ft_strjoin(RET_STR, "0");
	}
	if (MOD_L || MOD_LL)
	{
		PRECISION_CPY -= WIDTH_CPY;
		while (WIDTH_CPY-- > 0)
			RET_STR = ft_strjoin(RET_STR, "0");
	}
	if ((MOD_HH || MOD_H) && WIDTH >= PRECISION_O)
	{
		while (PRECISION_CPY-- > 0)
			RET_STR = ft_strjoin(RET_STR, "0");
	}
}

static void	is_width_precision_minus_not_sharp(t_result *result, size_t i)
{
	if (WIDTH_CPY > PRECISION_CPY)
		WIDTH_CPY -= PRECISION_CPY;
	if ((I_INT < 0 || I_L_INT < 0) && I_L_CONV == 'd')
	{
		I_INT = -I_INT;
		I_L_INT = -I_L_INT;
		RET_STR = ft_strjoin(RET_STR, "-");
		if ((int)ft_strlen(ft_litoa(I_INT + I_L_INT)) < PRECISION_O)
		{
			RET_STR = ft_strjoin(RET_STR, "0");
			WIDTH_CPY -= 1;
		}
		while (PRECISION_CPY-- > 0)
			RET_STR = ft_strjoin(RET_STR, "0");
		if (PRECISION_O > WIDTH)
			while (PRECISION_CPY-- > 0)
				RET_STR = ft_strjoin(RET_STR, "0");
	}
	if (I_L_CONV == 'u')
		if_l_conv_u(result, i);
	if (!(MOD_HH || MOD_H || I_L_CONV == 'u'))
		while (PRECISION_CPY-- > 0)
			RET_STR = ft_strjoin(RET_STR, "0");
}

static void	is_width_precision_sharp_minus(t_result *result, size_t i)
{
	if (PRECISION_CPY > 0)
		WIDTH_CPY -= PRECISION_CPY;
	WIDTH_CPY = (I_L_CONV == 'x' || I_L_CONV == 'X') ?
												WIDTH_CPY - 2 : WIDTH_CPY;
	PRECISION_CPY = (MOD_HH && (I_L_CONV == 'x' || I_L_CONV == 'X')) ?
											PRECISION_CPY + 6 : PRECISION_CPY;
	if (I_L_CONV == 'o')
	{
		WIDTH_CPY -= 1;
		RET_STR = (*RET_STR != '0') ?
			RET_STR = ft_strjoin(RET_STR, "0") : RET_STR;
		if ((MOD_HH || MOD_H) && PRECISION_CPY <= WIDTH_CPY)
		{
			PRECISION_CPY =
				(WIDTH_CPY - ft_strlen(ft_itoa_base(I_INT, 8)));
			WIDTH_CPY += 1;
		}
		else
			PRECISION_CPY--;
	}
	while (PRECISION_CPY-- > 0)
		RET_STR = ft_strjoin(RET_STR, "0");
}

static void	is_width_precision_plus_minus(t_result *result, size_t i)
{
	if (PRECISION_CPY > 0)
		WIDTH_CPY -= PRECISION_CPY;
	RET_STR = ft_strjoin(RET_STR, "+");
	while (PRECISION_CPY-- > 0)
		RET_STR = ft_strjoin(RET_STR, "0");
}

void		is_width_precision_minus(t_result *result, size_t i)
{
	if (IS_WIDTH && IS_PRECISION && MINUS && PLUS)
		is_width_precision_plus_minus(result, i);
	if (IS_WIDTH && IS_PRECISION && SHARP && MINUS)
		is_width_precision_sharp_minus(result, i);
	if (IS_WIDTH && IS_PRECISION && MINUS && !SHARP)
	{
		is_width_precision_minus_not_sharp(result, i);
		if (MOD_HH || MOD_H)
		{
			PRECISION_CPY = ((I_L_CONV == 'x' || I_L_CONV == 'X') && (MOD_HH)) ?
										PRECISION_CPY + 6 : PRECISION_CPY;
			WIDTH_CPY = (PRECISION_CPY >= WIDTH_CPY) ?
										WIDTH_CPY - PRECISION_CPY : WIDTH_CPY;
			while (PRECISION_CPY-- > 0)
				RET_STR = ft_strjoin(RET_STR, "0");
		}
	}
}
