/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bin_dec_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:55:09 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/11 11:49:34 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_binaire(t_result *result, size_t i)
{
	char	*int_min_bin;

	int_min_bin = "10000000000000000000000000000000";
	if (I_L_CONV == 'b')
	{
		if (ft_atoi(I_STR) == INT_MIN)
			ft_buffer_add(RET_STR, RET_STR->len, int_min_bin, ft_strlen(int_min_bin));
		else
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
	}
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
			ft_buffer_add(RET_STR, RET_STR->len, I_STR, ft_strlen(I_STR));
	}
}

static void print_decimal_u(t_result *result, size_t i)
{
	if (I_L_CONV == 'u')
	{
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

void		print_bin_dec_oct(t_result *result, size_t i)
{
	print_decimal_d(result, i);
	print_decimal_u(result, i);
	print_octal_o(result, i);
	print_binaire(result, i);
}
