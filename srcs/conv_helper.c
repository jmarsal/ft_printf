/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 22:53:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/15 23:09:22 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_specifier_and_ajust_width(t_result *result, char specifier)
{
	L_CONV = specifier;
	if (L_CONV != 'c' && L_CONV != 's')
	{
		if (A_PLUS == 1)
			I_WIDTH_CPY--;
		if (A_SPACE == 1)
			I_WIDTH_CPY--;
	}
	STRLEN = ft_strlen(STR);
	I_WIDTH_CPY -= STRLEN;
	I_PRECISION_CPY -= STRLEN;
	if (((I_IS_WIDTH && I_IS_PRECISION && A_MINUS && A_PLUS) ||
		(I_IS_WIDTH && I_IS_PRECISION && A_MINUS && A_SHARP)) &&
		I_PRECISION_CPY > 0)
		I_WIDTH_CPY = (L_CONV == 'x' || L_CONV == 'X') ?
			I_WIDTH_CPY - I_PRECISION_CPY - 2 : I_WIDTH_CPY - I_PRECISION_CPY;
	else if (I_IS_WIDTH && I_IS_PRECISION && A_MINUS && !A_SHARP)
		I_WIDTH_CPY -= I_PRECISION_CPY;
}

void	add_padding(t_result *result, size_t i, int size, char c)
{
	char	*padding;

	padding = NULL;
	if (size == -1 && PRECISION_CPY > 0)
	{
		padding = ft_strnew(PRECISION_CPY);
		ft_memset(padding, c, PRECISION_CPY);
		PRECISION_CPY -= PRECISION_CPY;
		RET_STR = ft_strjoin(RET_STR, padding);
	}
	else if (PRECISION_CPY > 0)
	{
		padding = ft_strnew(PRECISION_O - (I_STRLEN));
		ft_memset(padding, c, PRECISION_O - (I_STRLEN));
		RET_STR = ft_strjoin(RET_STR, padding);
	}
	free (padding);
	padding = NULL;
}
