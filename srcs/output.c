/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/17 01:17:33 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_caracters_is_positive(t_args *v_args, size_t i)
{
	if (I_INT >= 0 && I_L_INT >= 0 && (long int)I_U_L_INT >= 0)
	{
		if (PLUS == 1 && IS_PRECISION == 0)
		{
			if	((IS_WIDTH == 0) || (IS_WIDTH == 1 && MINUS == 1))
			RET_STR = ft_strcat(RET_STR, "+");
		}
	}
}

void	is_caracters_is_space(t_args *v_args, size_t i)
{
	if (SPACE == 1 && I_INT >= 0 && I_L_INT >= 0)
	{
		if (I_L_CONV == 'd' || I_L_CONV == 'D' || I_L_CONV == 'b')
			RET_STR = ft_strcat(RET_STR, " ");
	}
}

static void	is_flags_and_width(t_args *v_args, size_t i)
{
	is_caracters_is_sharp(v_args, i);
	is_caracters_is_space(v_args, i);
	is_caracters_is_positive(v_args, i);
	is_width_precision_and_not_minus(v_args, i);
	is_width_precision_plus_minus(v_args, i);
}

int		print_format(t_args *v_args)
{
	size_t	i;
	size_t	test_c;

	i = 0;
	test_c = 0;
	while (v_args->index--)
	{
		is_flags_and_width(v_args, i);
		print_str_s(v_args, i);
		print_decimal_d(v_args, i);
		print_decimal_ld(v_args, i);
		print_decimal_u(v_args, i);
		print_decimal_lu(v_args, i);
		print_char_c(v_args, i, &test_c);
		print_hex_x(v_args, i);
		print_hex_lx(v_args, i);
		print_hex_b(v_args, i);
		print_ptr(v_args, i);
		print_octal_o(v_args, i);
		print_octal_lo(v_args, i);
		if (I_L_CONV == '%')
			ft_putstr(I_STR);
		is_caracters_is_neg_and_precision(v_args, i);
		i++;
	}
	ft_putstr(RET_STR);
	return (ft_strlen(RET_STR) + test_c);
}
