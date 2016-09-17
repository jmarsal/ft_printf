/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 01:07:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/17 01:58:14 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_caracters_is_neg_and_precision(t_args *v_args, size_t i) //un prob va se poser ici...
{
	if (MINUS && IS_WIDTH)
	{
		while (WIDTH_CPY > 0)
		{
			RET_STR = ft_strcat(RET_STR, " ");
			WIDTH_CPY--;
		}
	}
}

void	is_width_precision_plus_minus(t_args *v_args, size_t i)
{
	if (IS_WIDTH && IS_PRECISION && MINUS && PLUS)
	{
		if (PRECISION_CPY > 0)
			WIDTH_CPY -= PRECISION_CPY;
		RET_STR = ft_strcat(RET_STR, "+");
		while (PRECISION_CPY-- > 0)
			RET_STR = ft_strcat(RET_STR, "0");
	}
	else if (IS_WIDTH && IS_PRECISION && SHARP && MINUS)
	{
		if (I_L_CONV == 'x' || I_L_CONV == 'X')
			WIDTH_CPY -= 2;
		else
			WIDTH_CPY -= 1;
		if (PRECISION_CPY > 0)
			WIDTH_CPY -= PRECISION_CPY;
		while (PRECISION_CPY-- > 0)
			RET_STR = ft_strcat(RET_STR, "0");
	}
}

static void is_width_precision(t_args *v_args, size_t i)
{
	if (PRECISION_CPY > 0)
		WIDTH_CPY -= PRECISION_CPY;
	while (WIDTH_CPY-- > 0)
		RET_STR = ft_strcat(RET_STR, " ");
	if (IS_PRECISION && PLUS)
		RET_STR = ft_strcat(RET_STR, "+");
	while (PRECISION_CPY-- > 0)
		RET_STR = ft_strcat(RET_STR, "0");
	if (PLUS == 1 && MINUS == 0 && !IS_PRECISION)
		RET_STR = ft_strcat(RET_STR, "+");
}

void	is_width_precision_and_not_minus(t_args *v_args, size_t i)
{
	if (IS_WIDTH && !MINUS)
	{
		if (ZERO && !IS_PRECISION)
		{
			if (PLUS)
				RET_STR = ft_strcat(RET_STR, "+");
			if ((I_INT < 0 || I_L_INT < 0) &&
				(I_L_CONV != 'x' && I_L_CONV != 'X'))
				{
					I_INT = -I_INT;
					RET_STR = ft_strcat(RET_STR, "-");
				}
			while (WIDTH_CPY > 0)
			{
				RET_STR = ft_strcat(RET_STR, "0");
				WIDTH_CPY--;
			}
		}
		else
			is_width_precision(v_args, i);
	}
}

void	is_caracters_is_sharp(t_args *v_args, size_t i)
{
	if (SHARP == 1)
	{
		if (I_L_CONV == 'o' || I_L_CONV == 'O')
			RET_STR = ft_strcat(RET_STR, "0");
		else if (I_L_CONV == 'x')
			RET_STR = ft_strcat(RET_STR, "0x");
		else if (I_L_CONV == 'X')
			RET_STR = ft_strcat(RET_STR, "0X");
	}
}
