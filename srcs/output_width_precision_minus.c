/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_width_precision_minus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:32:24 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/15 00:45:28 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	if_l_conv_u(t_result *result, size_t i)
{
	if (!I_IS_MODIFIER)
	{
		while ((int)ft_strlen(RET_STR) +
				I_STRLEN < PRECISION_O)
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
	if (*I_STR == '-' && I_L_CONV == 'd')
	{
		I_STR = ft_strdup(I_STR + 1);
		RET_STR = ft_strjoin(RET_STR, "-");
		if (I_STRLEN < PRECISION_O)
		{
			RET_STR = ft_strjoin(RET_STR, "0");
			WIDTH_CPY -= 1;
		}
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
	if (I_L_CONV == 'o')
	{
		WIDTH_CPY -= 1;
		RET_STR = (*RET_STR != '0') ?
			RET_STR = ft_strjoin(RET_STR, "0") : RET_STR;
		if ((MOD_HH || MOD_H) && PRECISION_CPY <= WIDTH_CPY)
		{
			PRECISION_CPY = (WIDTH_CPY - I_STRLEN);
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
	RET_STR = ft_strjoin(RET_STR, "+");
	while (PRECISION_CPY-- > 0)
		RET_STR = ft_strjoin(RET_STR, "0");
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
			while (PRECISION_CPY-- > 0)
				RET_STR = ft_strjoin(RET_STR, "0");
		}
	}
}
