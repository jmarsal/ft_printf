/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:10:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/17 11:51:02 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_ptr(t_result *result, size_t i)
{
	if (I_L_CONV == 'p')
	{
		if (!MINUS && !ZERO && (WIDTH_CPY - (I_STRLEN + 2)) > 0 &&
			WIDTH_CPY > PRECISION_CPY && WIDTH_CPY > (int)I_STRLEN)
		{
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (I_STRLEN + 2));
			WIDTH_CPY = 0;
		}
		if (!IS_MODIFIER && PRECISION_CPY <= WIDTH_CPY)
		{
			ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
			PRECISION_CPY = (PRECISION_CPY && WIDTH_CPY) ?
				PRECISION_CPY -= 1 : PRECISION_CPY;
			if ((*I_STR != '0' && PRECISION_CPY <= (int)I_STRLEN) ||
				(*I_STR == '0' && !IS_PRECISION))
				ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
		}
		if ((ZERO && WIDTH_CPY && (WIDTH_CPY - ((int)I_STRLEN + 2)) > 0) ||
			(!WIDTH && PRECISION_CPY && *I_STR == '0'))
		{
			if (WIDTH_CPY)
			{
				ft_buffer_set(RET_STR, '0', WIDTH_CPY - (I_STRLEN + 2));
				WIDTH_CPY = 0;
			}
			else if (PRECISION_CPY)
			{
				if (!MINUS)
					ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
				ft_buffer_set(RET_STR, '0', PRECISION_CPY);
				PRECISION_CPY = 0;
			}
		}
		if (WIDTH_CPY && PRECISION_CPY - WIDTH_CPY > 0 &&
			!MINUS && PRECISION_CPY > WIDTH_CPY &&
				!result->tab_conv[i]->is_wildchar_prec)
		{
			if (WIDTH_CPY >= (int)I_STRLEN)
				ft_buffer_set(RET_STR, '0', PRECISION_CPY - WIDTH_CPY);
			else if (PRECISION_CPY - (I_STRLEN + 1) > 0)
			{
				ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
				PRECISION_CPY -= 1;
				ft_buffer_set(RET_STR, '0', PRECISION_CPY - I_STRLEN + 1);
			}
			PRECISION_CPY = 0;
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
		}
		if ((WIDTH_CPY - RET_STR->len) > 0 && WIDTH_CPY > PRECISION_CPY &&
			WIDTH_CPY > (int)RET_STR->len && MINUS)
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - RET_STR->len);
		if (WIDTH_CPY < PRECISION_CPY && result->tab_conv[i]->is_wildchar_prec)
		{
			ft_buffer_set(RET_STR, ' ', PRECISION_CPY - (int)I_STRLEN - 2);
			ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
		}
		else if (WIDTH_CPY < PRECISION_CPY && !result->tab_conv[i]->is_wildchar_prec)
		{
			ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
		}
	}
}
