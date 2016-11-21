/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_without_minus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 01:54:42 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/21 15:58:18 by jmarsal          ###   ########.fr       */
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
		while (RET_STR->str[j])
			test_o = (RET_STR->str[j++] == '0') ? 1 : 0;
		if (test_o == 0)
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
	}
}

static void	reajust_width_print_padding_or_str(t_result *result, size_t i)
{
	if ((I_L_CONV == 'o' || I_L_CONV == 'd') && WIDTH_CPY &&
		!IS_WILDCARD_WIDTH)
	{
		if (WIDTH_CPY && SHARP && (!(MOD_HH || MOD_H)))
			WIDTH_CPY--;
		if ((PLUS && WIDTH_CPY && !ft_strchr("GOOD_PLUS", I_L_CONV) &&
			*I_STR != '-' && IS_PRECISION))
			WIDTH_CPY--;
		if (IS_PRECISION && PRECISION_CPY == 0 && *I_STR == '0')
			WIDTH_CPY += 1;
		if (PRECISION_CPY > (int)I_STRLEN && (WIDTH_CPY - PRECISION_CPY) > 0)
		{
			if (*I_STR == '-')
				WIDTH_CPY--;
			ft_buffer_set(RET_STR, ' ', (WIDTH_CPY - PRECISION_CPY));
		}
		else if (PRECISION_O < (int)I_STRLEN &&
			(WIDTH_CPY - (int)I_STRLEN) > 0 && !IS_WILDCARD_PRECISION)
			ft_buffer_set(RET_STR, ' ', (WIDTH_CPY - (int)I_STRLEN));
		else if (PRECISION_O < (int)I_STRLEN &&
			(WIDTH_CPY - (int)I_STRLEN) > 0 && IS_WILDCARD_PRECISION)
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
		WIDTH_CPY = 0;
	}
}

static void	is_width_precision(t_result *result, size_t i)
{
	reajust_width_print_padding_or_str(result, i);
	if (IS_PRECISION && PLUS)
		ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
	add_padding(result, i);
	is_sharp_and_o(result, i);
	if (PLUS && !IS_PRECISION && !ZERO)
		ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
}

void		if_not_minus(t_result *result, size_t i)
{
	if ((IS_WIDTH || PRECISION_CPY > 0) && !MINUS)
	{
		if (I_L_CONV == 's' || I_L_CONV == 'c')
		{
			if (PRECISION_CPY <= (int)I_STRLEN && PRECISION_CPY >= WIDTH_CPY)
				WIDTH_CPY += PRECISION_CPY;
			if ((I_L_CONV == 'c') && *I_STR == 0)
				WIDTH_CPY--;
			add_padding_space_if_not_minus(result, i);
		}
		else
			is_width_precision(result, i);
	}
}
