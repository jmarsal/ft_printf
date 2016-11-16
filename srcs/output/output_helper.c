/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 22:53:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/10 15:52:49 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_specifier_and_ajust_width(t_result *result, char specifier)
{
	L_CONV = specifier;
	STRLEN = ft_strlen(STR);
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
		ft_buffer_add(RET_STR, RET_STR->len, padding, ft_strlen(padding));
	}
	else if (PRECISION_CPY > 0)
	{
		padding = ft_strnew(PRECISION_O - ((int)I_STRLEN));
		ft_memset(padding, c, PRECISION_O - ((int)I_STRLEN));
		ft_buffer_add(RET_STR, RET_STR->len, padding, ft_strlen(padding));
	}
	ft_free_null (padding);
}
