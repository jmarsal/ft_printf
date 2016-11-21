/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_minus_sharp_or_plus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:39:32 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/21 14:42:09 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_width_precision_plus_minus(t_result *result, size_t i)
{
	ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
	if (PRECISION_CPY > 0)
	{
		ft_buffer_set(RET_STR, '0', PRECISION_CPY - I_STRLEN);
		PRECISION_CPY = 0;
	}
}

void	is_width_precision_sharp_minus(t_result *result, size_t i)
{
	if (I_L_CONV == 'o')
	{
		if (*RET_STR->str != '0' && PRECISION_O > WIDTH)
		{
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
			if ((WIDTH == PRECISION_O) || (PRECISION_O > WIDTH))
				PRECISION_CPY--;
		}
		if ((MOD_HH || MOD_H) && PRECISION_CPY <= WIDTH_CPY)
			PRECISION_CPY--;
	}
	if (PRECISION_CPY - (int)I_STRLEN >= 0)
	{
		ft_buffer_set(RET_STR, '0', PRECISION_CPY - (int)I_STRLEN);
		PRECISION_CPY = 0;
	}
}
