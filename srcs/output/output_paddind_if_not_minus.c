/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_paddind_if_not_minus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 01:03:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 16:30:18 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_minus_and_padding_zero_or_space(t_result *result, size_t i)
{
	char *tmp;

	tmp = NULL;
	if (*I_STR == '-' && *RET_STR->str != '-')
	{
		ft_buffer_add(RET_STR, RET_STR->len, "-", 1);
		tmp = ft_strdup(I_STR + 1);
		I_STR = tmp;
		if ((int)I_STRLEN > 1)
			I_STRLEN -= 1;
	}
	if (WIDTH_CPY <= PRECISION_CPY)
	{
		*I_STR != '0' ?
			ft_buffer_set(RET_STR, '0', PRECISION_CPY - (int)I_STRLEN) :
			ft_buffer_set(RET_STR, '0', PRECISION_CPY);
		PRECISION_CPY = 0;
		WIDTH_CPY = 0;
	}
	else
	{
		ft_buffer_set(RET_STR, ' ', WIDTH_CPY - PRECISION_CPY);
		WIDTH_CPY = 0;
	}
}

void		add_padding(t_result *result, size_t i)
{
	if (I_L_CONV == 'x' || I_L_CONV == 'X')
	{
		is_precision_sup_width(result, i);
		is_width_sup_precision(result, i);
	}
	else if (ZERO && WIDTH >= PRECISION_O &&
		WIDTH_CPY > (int)I_STRLEN && I_L_CONV != 'p')
	{
		ft_buffer_set(RET_STR, '0', WIDTH_CPY - (int)I_STRLEN);
		WIDTH_CPY = 0;
	}
	else if (I_L_CONV != 'p' && PRECISION_CPY >= (int)I_STRLEN &&
		((!IS_WILDCARD_WIDTH) || (IS_WILDCARD_WIDTH && IS_WILDCARD_PRECISION)))
		add_minus_and_padding_zero_or_space(result, i);
	else if (I_L_CONV != 'p' && PRECISION_CPY >= (int)I_STRLEN &&
		IS_WILDCARD_WIDTH)
	{
		ft_buffer_set(RET_STR, ' ', PRECISION_CPY - I_STRLEN);
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, I_STRLEN);
		if (WIDTH_CPY > PRECISION_CPY)
			WIDTH_CPY -= RET_STR->len + 1;
		PRECISION_CPY = 0;
	}
}

void		add_padding_space_if_not_minus(t_result *result, size_t i)
{
	if (WIDTH_CPY - (int)I_STRLEN > 0 && *I_STR != '0' && !ZERO)
	{
		if ((!PRECISION_CPY && *I_STR != '%') ||
			PRECISION_CPY >= WIDTH_CPY ||
			(WIDTH_CPY > PRECISION_CPY && PRECISION_CPY > (int)I_STRLEN))
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
		else if (WIDTH_CPY >= PRECISION_CPY &&
			WIDTH_CPY - PRECISION_CPY < WIDTH)
		{
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - PRECISION_CPY);
		}
		WIDTH_CPY = 0;
	}
}
