/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_if_space_or_positive.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:24:42 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 11:38:21 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	is_have_to_add_space(t_result *result, size_t i)
{
	if (I_L_CONV != 'u' && I_L_CONV != 's' && I_L_CONV != 'p' &&
		I_L_CONV != 'o' && I_L_CONV != 'x' && I_L_CONV != 'X' &&
		((!IS_WIDTH && !IS_PRECISION) || (ZERO && WIDTH && I_L_CONV == 'd')))
	{
		ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
		if (WIDTH_CPY && !SHARP)
			WIDTH_CPY -= 1;
	}
}

void		if_space_or_positive(t_result *result, size_t i)
{
	if (SPACE && !ft_strchr("GOOD_SPACE", I_L_CONV) && !PLUS &&
		(((*I_STR != '-' && *I_STR != '0') && (I_L_CONV != 'c')) ||
		(*I_STR == '0' && ZERO && I_L_CONV == 'd')))
		is_have_to_add_space(result, i);
	else if ((PLUS && !ft_strchr("GOOD_PLUS", I_L_CONV) && *I_STR != '-' &&
			!IS_PRECISION))
	{
		if (I_L_CONV != 'u' && I_L_CONV != 'c' && I_L_CONV != 'o' &&
			I_L_CONV != 's' && I_L_CONV != 'p' && I_L_CONV != 'x' &&
			I_L_CONV != 'X')
		{
			ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
			if (WIDTH_CPY)
				WIDTH_CPY -= 1;
		}
	}
}
