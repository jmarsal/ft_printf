/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_width_precision_not_minus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 01:54:42 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/14 23:55:25 by jmarsal          ###   ########.fr       */
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
		while (RET_STR[j])
			test_o = (RET_STR[j++] == '0') ? 1 : 0;
		if (test_o == 0)
			RET_STR = ft_strjoin(RET_STR, "0");
	}
}

static void	is_width_sup_precision(t_result *result, size_t i)
{
	if (WIDTH > PRECISION_O)
	{
		if (I_STRLEN < WIDTH)
		{
			while ((int)ft_strlen(RET_STR) + ((PRECISION_O + 2) -
					I_STRLEN) < WIDTH_CPY)
				RET_STR = ft_strjoin(RET_STR, " ");
		}
		RET_STR = (I_L_CONV == 'x') ?
			ft_strjoin(RET_STR, "0x") : ft_strjoin(RET_STR, "0X");
		while ((int)ft_strlen(RET_STR) < WIDTH_CPY)
			RET_STR = ft_strjoin(RET_STR, "0");
	}
}

static void	is_precision_sup_width(t_result *result, size_t i)
{
	if (PRECISION_O >= WIDTH)
	{
		RET_STR = (I_L_CONV == 'x') ?
			ft_strjoin(RET_STR, "0x") : ft_strjoin(RET_STR, "0X");
		PRECISION_O += 1;
		while (((int)ft_strlen(RET_STR) + I_STRLEN) <= PRECISION_O)
			RET_STR = ft_strjoin(RET_STR, "0");
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
			RET_STR = ft_strjoin(RET_STR, " ");
	}
	RET_STR = (IS_PRECISION && PLUS) ? ft_strjoin(RET_STR, "+") : RET_STR;
	if (SHARP && PRECISION_O >= WIDTH)
		PRECISION_CPY--;
	if (I_L_CONV == 'x' || I_L_CONV == 'X')
	{
		is_precision_sup_width(result, i);
		is_width_sup_precision(result, i);
	}
	else
		while (PRECISION_CPY-- > 0)
			RET_STR = ft_strjoin(RET_STR, "0");
	is_sharp_and_o(result, i);
	if (PLUS == 1 && MINUS == 0 && !IS_PRECISION)
		RET_STR = ft_strjoin(RET_STR, "+");
}

void	is_width_precision_and_not_minus(t_result *result, size_t i)
{
	if (IS_WIDTH && !MINUS)
	{
		if (ZERO && !IS_PRECISION)
		{
			RET_STR = (PLUS) ? ft_strjoin(RET_STR, "+") : RET_STR;
			if (*I_STR == '-' && (I_L_CONV != 'x' && I_L_CONV != 'X'))
				{
					I_STR = ft_strdup(I_STR + 1);
					RET_STR = ft_strjoin(RET_STR, "-");
				}
			while (WIDTH_CPY-- > 0)
				RET_STR = ft_strjoin(RET_STR, "0");
		}
		else
			is_width_precision(result, i);
	}
}
