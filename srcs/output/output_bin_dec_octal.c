/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bin_dec_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:55:09 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/21 13:33:46 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_binaire(t_result *result, size_t i)
{
	if (I_L_CONV == 'b')
		ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
}

static void	print_octal_o(t_result *result, size_t i)
{
	if (I_L_CONV == 'o')
	{
		if (WIDTH_CPY > (int)I_STRLEN && !MINUS)
		{
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
			WIDTH_CPY = 0;
		}
		if (*I_STR != '0' || (*I_STR == '0' &&
		(!IS_WIDTH && !IS_PRECISION)) || (*I_STR == '0' && SHARP))
		{
			if ((ft_strcmp(RET_STR->str, "0")) ||
				(!ft_strcmp(RET_STR->str, "0") && MINUS))
				ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
			else if (*I_STR != '0' && SHARP)
				ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
		}
	}
}

static void	print_decimal_u(t_result *result, size_t i)
{
	if (I_L_CONV == 'u')
	{
		if (PRECISION_CPY > (int)I_STRLEN && !WIDTH_CPY)
		{
			ft_buffer_set(RET_STR, '0', PRECISION_CPY - (int)I_STRLEN);
			PRECISION_CPY = 0;
		}
		if (WIDTH_CPY > (int)I_STRLEN && !MINUS)
		{
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
			WIDTH_CPY = 0;
		}
		if (*I_STR != '0' || (*I_STR == '0' &&
		(!IS_WIDTH && !IS_PRECISION)) || (*I_STR == '0' && SHARP))
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
	}
}

static void	print_decimal_d(t_result *result, size_t i)
{
	if (I_L_CONV == 'd')
	{
		if (ZERO && MINUS && WIDTH_CPY && *I_STR == '0')
		{
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
			WIDTH_CPY--;
		}
		if (WIDTH_CPY > (int)I_STRLEN && !MINUS)
		{
			ft_buffer_set(RET_STR, ' ', WIDTH_CPY - (int)I_STRLEN);
			WIDTH_CPY = 0;
		}
		if ((*I_STR != '0') ||
			(*I_STR == '0' && (!IS_WIDTH && !IS_PRECISION)) ||
			(*I_STR == '0' && SHARP))
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
	}
}

void		print_bin_dec_oct(t_result *result, size_t i)
{
	print_decimal_d(result, i);
	print_decimal_u(result, i);
	print_octal_o(result, i);
	print_binaire(result, i);
}
