/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/30 02:05:44 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	is_neg_and_precision(t_args *v_args, size_t i)
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

static void	is_space_or_positive(t_args *v_args, size_t i)
{
	if (SPACE == 1 && I_INT >= 0 && I_L_INT >= 0)
	{
		if (I_L_CONV == 'd' || I_L_CONV == 'D' || I_L_CONV == 'b')
			RET_STR = ft_strcat(RET_STR, " ");
	}
	if (I_INT >= 0 && I_L_INT >= 0 && (long int)I_U_L_INT >= 0)
	{
		if (PLUS == 1 && IS_PRECISION == 0)
		{
			if	((IS_WIDTH == 0) || (IS_WIDTH == 1 && MINUS == 1))
				RET_STR = ft_strcat(RET_STR, "+");
		}
	}
}

static void	is_caracters_is_sharp(t_args *v_args, size_t i)
{
	if (SHARP == 1)
	{
		if ((I_L_CONV == 'o' || I_L_CONV == 'O') && WIDTH <= PRECISION_O)
			RET_STR = ft_strjoin(RET_STR, "0");
		if (MINUS && (I_L_CONV == 'x' || I_L_CONV == 'X'))
		{
			if (I_L_CONV == 'x')
				RET_STR = ft_strjoin(RET_STR, "0x");
			else if (I_L_CONV == 'X')
				RET_STR = ft_strjoin(RET_STR, "0X");
		}
		if (!WIDTH && !PRECISION_O && (I_L_CONV == 'x' || I_L_CONV == 'X'))
		{
			if (I_L_CONV == 'x')
				RET_STR = ft_strjoin(RET_STR, "0x");
			else if (I_L_CONV == 'X')
				RET_STR = ft_strjoin(RET_STR, "0X");
		}
	}
}

static void	is_flags_width_precision(t_args *v_args, size_t i)
{
	is_caracters_is_sharp(v_args, i);
	is_space_or_positive(v_args, i);
	is_width_precision_and_not_minus(v_args, i);
	is_width_precision_minus(v_args, i);
}

int			print_format(t_args *v_args)
{
	size_t	i;
	size_t	test_c;

	i = 0;
	test_c = 0;
	while (v_args->index--)
	{
		is_flags_width_precision(v_args, i);
		print_char_str(v_args, i, &test_c);
		print_bin_dec_oct(v_args, i);
		print_hex_x(v_args, i);
		print_ptr(v_args, i);
		is_neg_and_precision(v_args, i);
		i++;
	}
	ft_putstr(RET_STR);
	return (ft_strlen(RET_STR) + test_c);
}
