/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/16 22:31:09 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	is_neg_and_precision(t_result *result, size_t i)
{
	if (MINUS && IS_WIDTH)
	{
		if (!I_IS_MODIFIER || MOD_L || MOD_LL)
				while ((int)ft_strlen(RET_STR) < WIDTH)
					RET_STR = ft_strjoin(RET_STR, " ");
		else
		{
			if (PRECISION_O > WIDTH)
			{
				if ((int)ft_strlen(RET_STR) < PRECISION_O)
					while (WIDTH_CPY-- > 0)
						RET_STR = ft_strjoin(RET_STR, " ");
			}
			else if (WIDTH > PRECISION_O)
			{
				if ((int)ft_strlen(RET_STR) < WIDTH)
					while (WIDTH_CPY-- > 0)
						RET_STR = ft_strjoin(RET_STR, " ");
			}
		}
	}
}

static void	is_space_or_positive(t_result *result, size_t i)
{
	if ((SPACE && *I_STR != '-') &&
	(I_L_CONV == 'd' || I_L_CONV == 'D' || I_L_CONV == 'b'))
		RET_STR = ft_strcat(RET_STR, " ");
	else if ((*I_STR != '-' && PLUS && !I_IS_PRECISION) &&
	((!IS_WIDTH) || (IS_WIDTH && MINUS)))
		RET_STR = ft_strcat(RET_STR, "+");
}

static void	is_caracters_is_sharp(t_result *result, size_t i)
{
	if (SHARP)
	{
		if ((I_L_CONV == 'o' || I_L_CONV == 'O') && WIDTH <= PRECISION_O)
			RET_STR = ft_strjoin(RET_STR, "0");
		else if (MINUS && (I_L_CONV == 'x' || I_L_CONV == 'X'))
		{
			if (I_L_CONV == 'x')
				RET_STR = ft_strjoin(RET_STR, "0x");
			else if (I_L_CONV == 'X')
				RET_STR = ft_strjoin(RET_STR, "0X");
		}
		else if (!WIDTH && !PRECISION_O && (I_L_CONV == 'x' || I_L_CONV == 'X'))
		{
			if (I_L_CONV == 'x')
				RET_STR = ft_strjoin(RET_STR, "0x");
			else if (I_L_CONV == 'X')
				RET_STR = ft_strjoin(RET_STR, "0X");
		}
	}
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

	i = 0;
	test_c = 0;
	while (result->index--)
	{
		is_flags_width_precision(result, i);
		print_char_str(result, i, &test_c);
		print_bin_dec_oct(result, i);
		print_hex_x(result, i);
		print_ptr(result, i);
		is_neg_and_precision(result, i);
		result->result_str = ft_strjoin(result->result_str, RET_STR);
		i++;
	}
	if (test_c != 0)
		print_str_if_char_to_zero(result);
	else
		ft_putstr(result->result_str);
	return (ft_strlen(result->result_str));
}
