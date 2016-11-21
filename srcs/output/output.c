/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/21 13:26:06 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	if_width_sup_precision(t_result *result, size_t i)
{
	if ((int)RET_STR->len < WIDTH)
	{
		ft_buffer_set(RET_STR, ' ', WIDTH - RET_STR->len);
		WIDTH_CPY = 0;
	}
}

static void	if_precision_sup_width(t_result *result, size_t i)
{
	if ((int)RET_STR->len < PRECISION_O)
	{
		ft_buffer_set(RET_STR, ' ', WIDTH_CPY - RET_STR->len);
		WIDTH_CPY = 0;
	}
}

static void	is_neg_and_precision(t_result *result, size_t i)
{
	if (MINUS && IS_WIDTH)
	{
		if (!I_IS_MODIFIER || MOD_L || MOD_LL)
		{
			if (WIDTH - (int)RET_STR->len > 0)
				ft_buffer_set(RET_STR, ' ', WIDTH - RET_STR->len);
		}
		else
		{
			if (PRECISION_O > WIDTH)
				if_precision_sup_width(result, i);
			else if (WIDTH > PRECISION_O)
				if_width_sup_precision(result, i);
		}
	}
}

static void	is_flags_width_precision(t_result *result, size_t i)
{
	if_caracters_is_sharp(result, i);
	if_space_or_positive(result, i);
	if_zero_without_minus(result, i);
	if_not_minus(result, i);
	is_width_precision_minus(result, i);
}

int			print_result(t_result *result)
{
	size_t	i;
	size_t	test_arg;

	i = 0;
	test_arg = 0;
	while (result->index--)
	{
		is_flags_width_precision(result, i);
		print_char_str(result, i);
		print_bin_dec_oct(result, i);
		print_hex_x(result, i);
		print_ptr(result, i);
		is_neg_and_precision(result, i);
		if (I_L_CONV == 'c' && *I_STR == '\0' && RET_STR->len < 1 &&
			(IS_WIDTH || PRECISION_CPY))
			test_arg++;
		ft_buffer_add(result->result_str, RESULT_LEN, RET_STR->str,
			RET_STR->len);
		i++;
	}
	return (RESULT_LEN - test_arg);
}
