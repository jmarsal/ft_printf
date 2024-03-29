/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 01:03:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/28 15:51:10 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	if_l_conv_u(t_result *result, size_t i)
{
	if (!I_IS_MODIFIER)
	{
		if ((PRECISION_CPY - (int)I_STRLEN) > 0)
		{
			ft_buffer_set(RET_STR, '0', PRECISION_CPY - (int)I_STRLEN);
			PRECISION_CPY = 0;
		}
	}
	if ((MOD_HH || MOD_H) && WIDTH >= PRECISION_O)
	{
		if (PRECISION_CPY - (int)I_STRLEN > 0)
		{
			ft_buffer_set(RET_STR, '0', PRECISION_CPY - (int)I_STRLEN);
			PRECISION_CPY = 0;
		}
	}
}

static void	if_str_negative_and_l_conv_d(t_result *result, size_t i)
{
	char	*tmp;

	tmp = NULL;
	if (*I_STR == '-' && I_L_CONV == 'd')
	{
		tmp = ft_strdup(I_STR + 1);
		ft_free(I_STR);
		I_STR = tmp;
		ft_buffer_add(RET_STR, RET_STR->len, "-", 1);
		if ((int)I_STRLEN < PRECISION_O)
		{
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
			WIDTH_CPY -= 1;
		}
		if (PRECISION_CPY > (int)I_STRLEN)
		{
			ft_buffer_set(RET_STR, '0', PRECISION_CPY - (int)I_STRLEN);
			WIDTH_CPY -= PRECISION_CPY;
			PRECISION_CPY = 0;
		}
	}
}

static void	is_width_precision_minus_not_sharp(t_result *result, size_t i)
{
	if_str_negative_and_l_conv_d(result, i);
	if (I_L_CONV == 'u')
		if_l_conv_u(result, i);
	if (!(MOD_HH || MOD_H || I_L_CONV == 'u' || I_L_CONV == 's' ||
		I_L_CONV == 'c'))
	{
		if (PRECISION_CPY > (int)I_STRLEN)
		{
			if (!IS_WIDTH || (!IS_WILDCARD_PRECISION))
				ft_buffer_set(RET_STR, '0', PRECISION_CPY - (int)I_STRLEN);
			else if (WIDTH_CPY - (int)I_STRLEN > 0)
			{
				ft_buffer_set(RET_STR, '0', WIDTH_CPY - (int)I_STRLEN);
				WIDTH_CPY = 0;
			}
			PRECISION_CPY = 0;
		}
	}
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
			if (PRECISION_CPY &&
				(WIDTH_CPY - (int)I_STRLEN - PRECISION_CPY) > 0)
			{
				ft_buffer_set(RET_STR, '0', WIDTH_CPY -
					(int)I_STRLEN - PRECISION_CPY);
				PRECISION_CPY = 0;
			}
			else if (PRECISION_CPY > (int)I_STRLEN && PRECISION_O >= WIDTH)
			{
				ft_buffer_set(RET_STR, '0', PRECISION_CPY - (int)I_STRLEN);
				PRECISION_CPY -= (int)I_STRLEN;
			}
		}
	}
}
