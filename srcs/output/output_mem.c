/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:10:44 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/15 17:05:17 by jmarsal          ###   ########.fr       */
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
		// pb par ici...
		/*if (!IS_MODIFIER)
		{
			ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
			PRECISION_CPY -= 1;
			if ((*I_STR != '0' && PRECISION_CPY <= (int)I_STRLEN) ||
				(*I_STR == '0' && !IS_PRECISION))
				ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
		}*/
		if ((ZERO && WIDTH_CPY && WIDTH_CPY - ((int)I_STRLEN + 2) > 0) ||
			(!WIDTH && PRECISION_CPY && *I_STR == '0'))
		{
			if (WIDTH_CPY)
			{
				ft_buffer_set(RET_STR, '0', WIDTH_CPY - (I_STRLEN + 2));
				WIDTH_CPY = 0;
			}
			else
			{
				ft_buffer_set(RET_STR, '0', PRECISION_CPY);
				PRECISION_CPY = 0;
			}
		}
		if (WIDTH_CPY && PRECISION_CPY - WIDTH_CPY > 0 &&
			!MINUS && PRECISION_CPY > WIDTH_CPY)
		{
			ft_buffer_set(RET_STR, '0', PRECISION_CPY - WIDTH_CPY);
			PRECISION_CPY = 0;
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
		}
		if ((WIDTH_CPY - RET_STR->len) > 0 && WIDTH_CPY > PRECISION_CPY &&
			WIDTH_CPY > (int)RET_STR->len && MINUS)
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - RET_STR->len);
	}
}
