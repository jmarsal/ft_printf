/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/05 23:28:18 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	is_neg_and_precision(t_result *result, size_t i)
{
	if (MINUS && IS_WIDTH)
	{
		if (!I_IS_MODIFIER || MOD_L || MOD_LL)
		{
			WIDTH = (I_L_CONV == 'c' && !*I_STR && IS_WIDTH) ? WIDTH += 1 : WIDTH;
			while ((int)RET_STR->len < WIDTH)
				ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
		}
		else
		{
			if (PRECISION_O > WIDTH)
			{
				if ((int)RET_STR->len < PRECISION_O)
					while (WIDTH_CPY-- > 0)
						ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
			}
			else if (WIDTH > PRECISION_O)
			{
				if ((int)RET_STR->len < WIDTH)
					while (WIDTH_CPY-- > 0)
						ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
			}
		}
	}
}

static void	is_space_or_positive(t_result *result, size_t i)
{
	if ((SPACE && *I_STR != '-') &&
			(I_L_CONV == 'd' || I_L_CONV == 'D' || I_L_CONV == 'b'))
		ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
	else if ((*I_STR != '-' && PLUS && !I_IS_PRECISION) &&
			((!IS_WIDTH) || (IS_WIDTH && MINUS)))
		ft_buffer_add(RET_STR, RET_STR->len, "+", 1);
}

static void	is_caracters_is_sharp(t_result *result, size_t i)
{
	if (SHARP && *I_STR != '0')
	{
		if ((I_L_CONV == 'o' || I_L_CONV == 'O') && WIDTH <= PRECISION_O)
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
		else if (MINUS && !IS_PRECISION && (I_L_CONV == 'o' || I_L_CONV == 'O'))
				ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
		else if (MINUS && (I_L_CONV == 'x' || I_L_CONV == 'X'))
		{
			if (I_L_CONV == 'x')
				ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
			else if (I_L_CONV == 'X')
				ft_buffer_add(RET_STR, RET_STR->len, "0X", 2);
		}
		else if (!WIDTH && !PRECISION_O && (I_L_CONV == 'x' || I_L_CONV == 'X'))
		{
			if (I_L_CONV == 'x')
				ft_buffer_add(RET_STR, RET_STR->len, "0x", 2);
			else if (I_L_CONV == 'X')
				ft_buffer_add(RET_STR, RET_STR->len, "0X", 2);
		}
	}
	else if (SHARP && *I_STR == '0' && i < 1)
		ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
}

static void	is_flags_width_precision(t_result *result, size_t i)
{
	is_caracters_is_sharp(result, i);
	is_space_or_positive(result, i);
	is_width_precision_and_not_minus(result, i);
	is_width_precision_minus(result, i);
}

int			print_result(t_result *result)
{
	size_t	i;
	size_t	test_c;
	size_t	test_arg;

	i = 0;
	test_c = 0;
	test_arg = 0;
	while (result->index--) // TROUVER ou est envoyer le padding dans la string avec minus
	{
		is_flags_width_precision(result, i);
		print_char_str(result, i, &test_c);
		print_bin_dec_oct(result, i);
		print_hex_x(result, i);
		print_ptr(result, i);
		is_neg_and_precision(result, i);
		if (I_L_CONV == 'c' && *I_STR == '\0' && RET_STR->len < 1 && (IS_WIDTH || PRECISION_CPY))
			test_arg++;
		ft_buffer_add(result->result_str, result->result_str->len, RET_STR->str, RET_STR->len);
		i++;
	}
	if (test_c > 0)
		print_str_if_char_to_zero(result);
	else
		write(1, result->result_str->str, result->result_str->len);
	return (result->result_str->len - test_arg);
}
