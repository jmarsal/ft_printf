/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:05:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/21 15:06:21 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		is_width_sup_precision(t_result *result, size_t i)
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

void		is_precision_sup_width(t_result *result, size_t i)
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

void		print_hex_x(t_result *result, size_t i)
{
	if ((I_L_CONV == 'x' || I_L_CONV == 'X') && ((SHARP && *I_STR != '0') ||
		(!SHARP && (WIDTH || PRECISION)) ||
		(SHARP && *I_STR == '0' && !WIDTH && !PRECISION)))
	{
		if ((*I_STR == '0' && !IS_PRECISION) || (*I_STR != '0'))
		{
			if (I_L_CONV == 'x')
				ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
			else
				ft_buffer_add(RET_STR, RET_STR->len, ft_strtoupper(I_STR),
					ft_strlen(I_STR));
		}
	}
}
