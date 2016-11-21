/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/17 18:38:37 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
			{
				if ((int)RET_STR->len < PRECISION_O)
					while (WIDTH_CPY-- > 0)
						ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
			}
			else if (WIDTH > PRECISION_O)
			{
				if ((int)RET_STR->len < WIDTH)
				{
					ft_buffer_set(RET_STR, ' ', WIDTH - RET_STR->len);
					WIDTH_CPY = 0;
				}
			}
		}
	}
}

static void	if_space_or_positive(t_result *result, size_t i)
{
	if (SPACE && !ft_strchr("GOOD_SPACE", I_L_CONV) && !PLUS &&
		(((*I_STR != '-' && *I_STR != '0') && (I_L_CONV != 'c')) ||
		(*I_STR == '0' && ZERO && I_L_CONV == 'd')))
	{
		if (I_L_CONV != 'u' && I_L_CONV != 's' && I_L_CONV != 'p' &&
			I_L_CONV != 'o' && I_L_CONV != 'x' && I_L_CONV != 'X' &&
			((!IS_WIDTH && !IS_PRECISION) || (ZERO && WIDTH && I_L_CONV == 'd')))
		{
			ft_buffer_add(RET_STR, RET_STR->len, " ", 1);
			if (WIDTH_CPY)
				WIDTH_CPY -= 1;
		}
	}
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

static void	if_caracters_is_sharp(t_result *result, size_t i)
{
	if (SHARP && !ft_strchr("GOOD_SHARP", I_L_CONV) &&
		!IS_PRECISION && !IS_WIDTH && I_L_CONV != 'c')
	{
		if (*I_STR == '0' || (I_L_CONV == 'o' || I_L_CONV == 'O'))
		{
			ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
			if (WIDTH_CPY > 0)
				WIDTH_CPY--;
		}
		else if (I_L_CONV == 'x' ? 
			ft_buffer_add(RET_STR, RET_STR->len, "0x", 2) :
			ft_buffer_add(RET_STR, RET_STR->len, "0X", 2))
		{
			if (WIDTH_CPY > 1)
				WIDTH_CPY -= 2;
		}
	}
	else if (((SHARP && MINUS) || (SHARP && ZERO)) && (I_L_CONV == 'x' || I_L_CONV == 'X'))
	{
		I_L_CONV == 'x' ? ft_buffer_add(RET_STR, RET_STR->len, "0x", 2) :
							ft_buffer_add(RET_STR, RET_STR->len, "0X", 2);
		if (WIDTH_CPY > 1 && WIDTH_CPY >= PRECISION_CPY)
			WIDTH_CPY -= 2;
	}
	else if (SHARP && MINUS && (I_L_CONV == 'o'))
	{
		ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
		if (WIDTH_CPY && WIDTH_CPY >= PRECISION_CPY && (!(MOD_H || MOD_HH)))
			WIDTH_CPY--;
		else if (PRECISION_CPY && PRECISION_CPY > WIDTH_CPY)
			PRECISION_CPY--;
	}
	else if (SHARP && IS_PRECISION && PRECISION_CPY == 0 && I_L_CONV == 'o')
		ft_buffer_add(RET_STR, RET_STR->len, "0", 1);
}

static void	if_zero_without_minus(t_result *result, size_t i)
{
	if (IS_WIDTH && ZERO &&
		(!MINUS && ((PRECISION_CPY >= (int)I_STRLEN) || (!IS_PRECISION))))
	{
		if (*I_STR == '-' && (!(I_L_CONV == 'x' && I_L_CONV == 'X')))
		{
			I_STR = I_STR + 1;
			ft_buffer_add(RET_STR, RET_STR->len, "-", 1);
		}
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
			WIDTH_CPY -= 1;
			I_STRLEN = ((int)I_STRLEN == 1 && *I_STR == '0') ? 0 : 1;
		}
		if (I_L_CONV == 'c' && WIDTH_CPY - (int)I_STRLEN > 0 && *I_STR == '\0')
			WIDTH_CPY -= 1;
		if (PRECISION_CPY)
			PRECISION_CPY -= 1;
		if (WIDTH_CPY - (int)I_STRLEN > 0 && I_L_CONV != 's' && I_L_CONV != 'p')
			ft_buffer_set(RET_STR, '0', WIDTH_CPY - (int)I_STRLEN);
		WIDTH_CPY = (WIDTH_CPY >= (int)RET_STR->len) ? WIDTH_CPY - RET_STR->len : 0;
		PRECISION_CPY = 0;
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
		if (I_L_CONV == 'c' && *I_STR == '\0' && RET_STR->len < 1 && (IS_WIDTH || PRECISION_CPY))
			test_arg++;
		ft_buffer_add(result->result_str, RESULT_LEN, RET_STR->str, RET_STR->len);
		i++;
	}
	return (RESULT_LEN - test_arg);
}
