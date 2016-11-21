/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_if_caracters_is_sharp.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:17:37 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/21 12:23:44 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_zero_or_zero_x_if_not_minus(t_result *result, size_t i)
{
	if (*I_STR == '0' || (I_L_CONV == 'o' || I_L_CONV == 'O'))
	{
		ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
		if (WIDTH_CPY > 0)
			WIDTH_CPY--;
	}
	else if (I_L_CONV == 'x' ?
		ft_buffer_add(RET_STR, RET_STR->len, "0x", 2) :
		ft_buffer_add(RET_STR, RET_STR->len, "0X", 2))
	{
		if (WIDTH_CPY > 1)
			WIDTH_CPY -= 2;
	}
}

void		if_caracters_is_sharp(t_result *result, size_t i)
{
	if (SHARP && !ft_strchr("GOOD_SHARP", I_L_CONV) &&
		!IS_PRECISION && !IS_WIDTH && I_L_CONV != 'c')
		add_zero_or_zero_x_if_not_minus(result, i);
	else if (((SHARP && MINUS) || (SHARP && ZERO)) &&
		(I_L_CONV == 'x' || I_L_CONV == 'X'))
	{
		I_L_CONV == 'x' ? ft_buffer_add(RET_STR, RET_STR->len, "0x", 2) :
							ft_buffer_add(RET_STR, RET_STR->len, "0X", 2);
		if (WIDTH_CPY > 1 && WIDTH_CPY >= PRECISION_CPY)
			WIDTH_CPY -= 2;
	}
	else if (SHARP && MINUS && (I_L_CONV == 'o'))
	{
		ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
		if (WIDTH_CPY && WIDTH_CPY >= PRECISION_CPY && (!(MOD_H || MOD_HH)))
			WIDTH_CPY--;
		else if (PRECISION_CPY && PRECISION_CPY > WIDTH_CPY)
			PRECISION_CPY--;
	}
	else if (SHARP && IS_PRECISION && PRECISION_CPY == 0 && I_L_CONV == 'o')
		ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
}
