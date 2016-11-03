/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_width_precision_not_minus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 01:54:42 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/03 13:06:32 by jmarsal          ###   ########.fr       */
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
			if (SHARP && !IS_PRECISION && (I_L_CONV == 'x' || I_L_CONV == 'X'))
				WIDTH_CPY -= 2;
			if (!SHARP && *I_STR == '0' && (I_L_CONV == 'x' || I_L_CONV == 'X'))
				WIDTH_CPY += 2;
			while ((int)RET_STR->len + ((PRECISION_O + 2) -
					I_STRLEN) < WIDTH_CPY)
				ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
		}
		if (I_L_CONV == 'x' && SHARP)
			ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
		else if (I_L_CONV == 'X' && SHARP)
			ft_buffer_add(RET_STR, RET_STR->len, "0X", 2);
		if (!SHARP && *I_STR == '0' && (I_L_CONV == 'x' || I_L_CONV == 'X'))
			WIDTH_CPY -= 2;	
		while ((int)RET_STR->len < WIDTH_CPY)
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
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
		PRECISION_O += 1;
		while (((int)RET_STR->len + I_STRLEN) <= PRECISION_O)
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
	}
}

static void is_width_precision(t_result *result, size_t i)
{
	if (I_L_CONV == 'o' || I_L_CONV == 'd')
	{
		WIDTH_CPY = (PRECISION_CPY > 0) ? WIDTH_CPY - PRECISION_CPY : WIDTH_CPY;
		if (SHARP && (!(MOD_HH || MOD_H)))
			WIDTH_CPY--;
		while (WIDTH_CPY-- > 0)
			ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
	}
	if (IS_PRECISION && PLUS)
		ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
	if (SHARP && PRECISION_O >= WIDTH)
		PRECISION_CPY--;
	if (I_L_CONV == 'x' || I_L_CONV == 'X')
	{
		is_precision_sup_width(result, i);
		is_width_sup_precision(result, i);
	}
	else
		while (PRECISION_CPY-- > 0)
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
	is_sharp_and_o(result, i);
	if (PLUS && !IS_PRECISION)
		ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
}

void		is_width_precision_and_not_minus(t_result *result, size_t i)
{
	if (IS_WIDTH && !MINUS)
	{
		if (ZERO && !IS_PRECISION)
		{
			if (PLUS)
				ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
			if (*I_STR == '-' && (I_L_CONV != 'x' && I_L_CONV != 'X'))
			{
				I_STR = I_STR + 1;
				ft_buffer_add(RET_STR, RET_STR->len, "-", 1);
			}
			if (SHARP && (I_L_CONV == 'x' || I_L_CONV == 'X'))
			{
				if (I_L_CONV == 'x')
					ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
				else if (I_L_CONV == 'X')
					ft_buffer_add(RET_STR, RET_STR->len, "0X", 2);
				WIDTH_CPY -= 2;
			}
			while (WIDTH_CPY-- > 0)
				ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
		}
		else if (I_L_CONV == 's')
		{
			// if (I_STRLEN < 1 && *I_STR != '\0')
			// 	WIDTH_CPY--;
			if (PRECISION_O <= I_STRLEN)
				WIDTH_CPY += PRECISION_O;
			while (WIDTH_CPY--)
				ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
		}
		else
			is_width_precision(result, i);
	}
}
