/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_without_minus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 01:54:42 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/17 14:40:14 by jmarsal          ###   ########.fr       */
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
		if ((int)I_STRLEN < WIDTH_CPY)
		{
			if (*I_STR == '0' && IS_PRECISION)
				I_STRLEN = 0;
			if (SHARP && (I_L_CONV == 'x' || I_L_CONV == 'X'))
				WIDTH_CPY -= 2;
			if (WIDTH_CPY >= PRECISION_CPY && PRECISION_CPY > (int)I_STRLEN)
				ft_buffer_set(RET_STR, ' ', WIDTH_CPY - PRECISION_CPY);
			else if (WIDTH_CPY - (int)I_STRLEN > 0 && WIDTH_CPY >= PRECISION_CPY
					&& PRECISION_CPY <= (int)I_STRLEN)
				ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
		}
		if (I_L_CONV == 'x' && SHARP && !ZERO)
			ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
		else if (I_L_CONV == 'X' && SHARP && !ZERO)
			ft_buffer_add(RET_STR, RET_STR->len, "0X", 2);
		if (!SHARP && *I_STR == '0' && (I_L_CONV == 'x' || I_L_CONV == 'X'))
			WIDTH_CPY -= 2;
		if (WIDTH > (int)RET_STR->len + (int)I_STRLEN)
			ft_buffer_set(RET_STR, '0', WIDTH - RET_STR->len - (int)I_STRLEN);
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
		if (SHARP)
			PRECISION_CPY += 2;
		if (PRECISION_CPY > (int)RET_STR->len + (int)I_STRLEN)
			ft_buffer_set(RET_STR, '0', PRECISION_CPY - RET_STR->len
							- (int)I_STRLEN);
	}
}

static void is_width_precision(t_result *result, size_t i)
{
	if ((I_L_CONV == 'o' || I_L_CONV == 'd') && WIDTH_CPY &&
		!result->tab_conv[i]->is_wildchar_width)
	{
		if (WIDTH_CPY && SHARP && (!(MOD_HH || MOD_H)))
			WIDTH_CPY--;
		if ((PLUS && WIDTH_CPY && !ft_strchr("GOOD_PLUS", I_L_CONV) &&
			*I_STR != '-' && IS_PRECISION))
			WIDTH_CPY--;
		if (IS_PRECISION && PRECISION_CPY == 0 && *I_STR == '0')
			WIDTH_CPY += 1;
		if (PRECISION_CPY >(int)I_STRLEN && (WIDTH_CPY - PRECISION_CPY) > 0)
		{
			if (*I_STR == '-')
				WIDTH_CPY--;
			ft_buffer_set(RET_STR, ' ', (WIDTH_CPY - PRECISION_CPY));
		}
		else if (PRECISION_O < (int)I_STRLEN &&
			(WIDTH_CPY - (int)I_STRLEN) > 0 && !result->tab_conv[i]->is_wildchar_prec)
			ft_buffer_set(RET_STR, ' ', (WIDTH_CPY - (int)I_STRLEN));
		else if (PRECISION_O < (int)I_STRLEN &&
			(WIDTH_CPY - (int)I_STRLEN) > 0 && result->tab_conv[i]->is_wildchar_prec)
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
		WIDTH_CPY = 0;
	}
	if (IS_PRECISION && PLUS)
		ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
	if (I_L_CONV == 'x' || I_L_CONV == 'X')
	{
		is_precision_sup_width(result, i);
		is_width_sup_precision(result, i);
	}
	else if (ZERO && WIDTH >= PRECISION_O && WIDTH_CPY > (int)I_STRLEN && I_L_CONV != 'p')
	{
		ft_buffer_set(RET_STR, '0', WIDTH_CPY - (int)I_STRLEN);
		WIDTH_CPY = 0;
	}
	else if (I_L_CONV != 'p' && PRECISION_CPY >= (int)I_STRLEN &&
		((!result->tab_conv[i]->is_wildchar_width) ||
		(result->tab_conv[i]->is_wildchar_width &&
		result->tab_conv[i]->is_wildchar_prec)))
	{
		if (*I_STR == '-' && *RET_STR->str != '-')
		{
			ft_buffer_add(RET_STR, RET_STR->len, "-", 1);
			I_STR = I_STR + 1;
			if ((int)I_STRLEN > 1)
				I_STRLEN -= 1;
		}
		if (WIDTH_CPY <= PRECISION_CPY)
		{
			if (*I_STR != '0')
				ft_buffer_set(RET_STR, '0', PRECISION_CPY - (int)I_STRLEN);
			else
				ft_buffer_set(RET_STR, '0', PRECISION_CPY);
			PRECISION_CPY = 0;
			WIDTH_CPY = 0;
		}
		else
		{
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - PRECISION_CPY);
			WIDTH_CPY = 0;
		}
	}
	else if (I_L_CONV != 'p' && PRECISION_CPY >= (int)I_STRLEN &&
		result->tab_conv[i]->is_wildchar_width)
	{
		ft_buffer_set(RET_STR, ' ', PRECISION_CPY - I_STRLEN);
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
		if (WIDTH_CPY > PRECISION_CPY)
			WIDTH_CPY -= RET_STR->len + 1;
		PRECISION_CPY = 0;
	}
	is_sharp_and_o(result, i);
	if (PLUS && !IS_PRECISION && !ZERO)
		ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
}

void		if_not_minus(t_result *result, size_t i)
{
	if ((IS_WIDTH || PRECISION_CPY > 0) && !MINUS)
	{
		if (I_L_CONV == 's' || I_L_CONV == 'c')
		{
			if (PRECISION_CPY <= (int)I_STRLEN && PRECISION_CPY >= WIDTH_CPY)
				WIDTH_CPY += PRECISION_CPY;
			if ((I_L_CONV == 'c' || I_L_CONV == 'C') && *I_STR == 0)
				WIDTH_CPY--;
			if (WIDTH_CPY - (int)I_STRLEN > 0 && *I_STR != '0' && !ZERO)
			{
				if ((!PRECISION_CPY && *I_STR != '%') ||
					PRECISION_CPY >= WIDTH_CPY ||
					(WIDTH_CPY > PRECISION_CPY && PRECISION_CPY > (int)I_STRLEN))
					ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
				else if (WIDTH_CPY >= PRECISION_CPY &&
					WIDTH_CPY - PRECISION_CPY < WIDTH)
				{
					ft_buffer_set(RET_STR, ' ', WIDTH_CPY - PRECISION_CPY);
				}
				WIDTH_CPY = 0;
			}
		}
		else
			is_width_precision(result, i);
	}
}
