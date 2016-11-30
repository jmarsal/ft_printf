/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_if_zero_without_minus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 01:03:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 16:26:58 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	if_have_to_add_zero_or_space(t_result *result, size_t i)
{
	if (PRECISION_CPY >= WIDTH_CPY)
	{
		ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
		WIDTH_CPY -= 1;
	}
	else if (PRECISION_CPY < WIDTH_CPY && (int)I_STRLEN == 1 && IS_PRECISION)
	{
		ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
		WIDTH_CPY -= 1;
		I_STRLEN = ((int)I_STRLEN == 1 && *I_STR == '0') ? 0 : 1;
	}
	else if (PRECISION_CPY < WIDTH_CPY && (int)I_STRLEN == 1 && I_L_CONV != 'p')
	{
		ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
		WIDTH_CPY = (*I_STR == '%') ? WIDTH_CPY : WIDTH_CPY - 1;
		I_STRLEN = ((int)I_STRLEN == 1 && *I_STR == '0') ? 0 : 1;
	}
}

static void	if_istr_negative(t_result *result, size_t i)
{
	char	*tmp;

	tmp = NULL;
	if (*I_STR == '-' && (!(I_L_CONV == 'x' && I_L_CONV == 'X')))
	{
		tmp = ft_strdup(I_STR + 1);
		ft_free(I_STR);
		I_STR = tmp;
		ft_buffer_add(RET_STR, RET_STR->len, "-", 1);
	}
}

void		if_zero_without_minus(t_result *result, size_t i)
{
	if (IS_WIDTH && ZERO &&
		(!MINUS && ((PRECISION_CPY >= (int)I_STRLEN) || (!IS_PRECISION))))
	{
		if_istr_negative(result, i);
		if_have_to_add_zero_or_space(result, i);
		if (I_L_CONV == 'c' && WIDTH_CPY - (int)I_STRLEN > 0 && *I_STR == '\0')
			WIDTH_CPY -= 1;
		if (PRECISION_CPY)
			PRECISION_CPY -= 1;
		if (WIDTH_CPY - (int)I_STRLEN > 0 && I_L_CONV != 's' && I_L_CONV != 'p')
			ft_buffer_set(RET_STR, '0', WIDTH_CPY - (int)I_STRLEN);
		WIDTH_CPY = (WIDTH_CPY >= (int)RET_STR->len) ?
			WIDTH_CPY - RET_STR->len : 0;
		PRECISION_CPY = 0;
	}
}
