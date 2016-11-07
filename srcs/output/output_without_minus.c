/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_without_minus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 01:54:42 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/07 17:08:28 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	is_sharp_and_o(t_result *result, size_t i)
{
	size_t	j;
	int		test_o;

	j = 0;
	test_o = 0;
	if (SHARP && I_L_CONV == 'o')
	{
		while (RET_STR->str[j])
			test_o = (RET_STR->str[j++] == '0') ? 1 : 0;
		if (test_o == 0)
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
	}
}

static void	is_width_sup_precision(t_result *result, size_t i)
{
	if (WIDTH > PRECISION_O)
	{
		if (I_STRLEN < WIDTH)
		{
			if (SHARP && (I_L_CONV == 'x' || I_L_CONV == 'X'))
				WIDTH_CPY -= 2;
			if (!SHARP && *I_STR == '0' && (I_L_CONV == 'x' || I_L_CONV == 'X'))
				WIDTH_CPY += 2;
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - RET_STR->len - I_STRLEN);
			WIDTH_CPY -= RET_STR->len;
		}
		if (I_L_CONV == 'x' && SHARP)
			ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
		else if (I_L_CONV == 'X' && SHARP)
			ft_buffer_add(RET_STR, RET_STR->len, "0X", 2);
		if (!SHARP && *I_STR == '0' && (I_L_CONV == 'x' || I_L_CONV == 'X'))
			WIDTH_CPY -= 2;
		if (WIDTH_CPY > (int)RET_STR->len - I_STRLEN)
		{
			ft_buffer_set(RET_STR, '0', WIDTH_CPY - RET_STR->len - I_STRLEN);
			WIDTH_CPY -= RET_STR->len;
		}
	}
}

static void	is_precision_sup_width(t_result *result, size_t i)
{
	if (PRECISION_O >= WIDTH)
	{
		if (I_L_CONV == 'x' && SHARP)
			ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
		else if (I_L_CONV == 'X' && SHARP)
			ft_buffer_add(RET_STR, RET_STR->len, "0X", 2);
		PRECISION_CPY += 2;
		if (PRECISION_CPY > (int)RET_STR->len + I_STRLEN)
			ft_buffer_set(RET_STR, '0', PRECISION_CPY - RET_STR->len
							- I_STRLEN);
	}
}

static void is_width_precision(t_result *result, size_t i)
{
	if (I_L_CONV == 'o' || I_L_CONV == 'd')
	{
		if (WIDTH_CPY && SHARP && (!(MOD_HH || MOD_H)))
			WIDTH_CPY--;
		if ((PLUS && WIDTH_CPY && !ft_strchr("GOOD_PLUS", I_L_CONV) &&
			*I_STR != '-' && IS_PRECISION))
			WIDTH_CPY--;
		if (I_L_CONV == 'o' && SHARP && *I_STR != '-' && IS_PRECISION)
			WIDTH_CPY++;
		ft_buffer_set(RET_STR, ' ', WIDTH_CPY - PRECISION_CPY);
		WIDTH_CPY = 0;
	}
	if (IS_PRECISION && PLUS)
		ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
	// if (SHARP && PRECISION_O >= WIDTH)
	// 	PRECISION_CPY--;
	if (I_L_CONV == 'x' || I_L_CONV == 'X')
	{
		is_precision_sup_width(result, i);
		is_width_sup_precision(result, i);
	}
	else
	{
		ft_buffer_set(RET_STR, '0', PRECISION_CPY - I_STRLEN);
		PRECISION_CPY = 0;
	}
	is_sharp_and_o(result, i);
	if (PLUS && !IS_PRECISION)
		ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
}

void		if_not_minus(t_result *result, size_t i)
{
	if (IS_WIDTH && !MINUS)
	{
		if (I_L_CONV == 's' || I_L_CONV == 'c')
		{
			if (PRECISION_O <= I_STRLEN)
				WIDTH_CPY += PRECISION_O;
			if ((I_L_CONV == 'c' || I_L_CONV == 'C') && *I_STR == 0)
				WIDTH_CPY--;
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - I_STRLEN);
			WIDTH_CPY = 0;
		}
		else
			is_width_precision(result, i);
	}
}
