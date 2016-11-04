/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_width_precision_minus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:32:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/04 16:50:01 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	if_l_conv_u(t_result *result, size_t i)
{
	if (!I_IS_MODIFIER)
		add_padding(result, i, 0, '0');
	if ((MOD_HH || MOD_H) && WIDTH >= PRECISION_O)
		add_padding(result, i, -1, '0');
}

static void	is_width_precision_minus_not_sharp(t_result *result, size_t i)
{
	if (*I_STR == '-' && I_L_CONV == 'd')
	{
		I_STR = I_STR + 1;
		ft_buffer_add(RET_STR, RET_STR->len, "-", 1);
		if (I_STRLEN < PRECISION_O)
		{
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
			WIDTH_CPY -= 1;
		}
		add_padding(result, i, -1, '0');
	}
	if (I_L_CONV == 'u')
		if_l_conv_u(result, i);
	if (!(MOD_HH || MOD_H || I_L_CONV == 'u' || I_L_CONV == 's' ||
		I_L_CONV == 'c'))
		add_padding(result, i, -1, '0');
}

static void	is_width_precision_sharp_minus(t_result *result, size_t i)
{
	if (I_L_CONV == 'o')
	{
		WIDTH_CPY -= 1;
		if (*RET_STR->str != '0')
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
		if ((MOD_HH || MOD_H) && PRECISION_CPY <= WIDTH_CPY)
		{
			PRECISION_CPY = (WIDTH_CPY - I_STRLEN);
			WIDTH_CPY += 1;
		}
		else
			PRECISION_CPY--;
	}
	add_padding(result, i, -1, '0');
}

static void	is_width_precision_plus_minus(t_result *result, size_t i)
{
	ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
	add_padding(result, i, -1, '0');
}

void		is_width_precision_minus(t_result *result, size_t i)
{
	if (IS_WIDTH && IS_PRECISION && MINUS && PLUS)
		is_width_precision_plus_minus(result, i);
	else if (IS_WIDTH && IS_PRECISION && SHARP && MINUS)
		is_width_precision_sharp_minus(result, i);
	else if (IS_WIDTH && IS_PRECISION && MINUS && !SHARP)
	{
		is_width_precision_minus_not_sharp(result, i);
		if (MOD_HH || MOD_H)
		{
			WIDTH_CPY = (PRECISION_CPY >= WIDTH_CPY) ?
						WIDTH_CPY - PRECISION_CPY : WIDTH_CPY;
			add_padding(result, i, -1, '0');
		}
	}
}
