/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:37:13 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/16 02:26:29 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_caracters_is_positive(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->type->nb >= 0 &&
		v_args->f_conv[i]->type->l_nb >= 0 &&
		(long int)v_args->f_conv[i]->type->u_l_nb >= 0)
	{
		if (v_args->f_conv[i]->caracters->plus == 1 &&
			v_args->f_conv[i]->is_precision == 0)
		{
			if	((v_args->f_conv[i]->is_width == 0) ||
					(v_args->f_conv[i]->is_width == 1 &&
				v_args->f_conv[i]->caracters->minus == 1))
			RET_STR = ft_strcat(RET_STR, "+");
		}
	}
}

void	is_caracters_is_space(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->caracters->space == 1 &&
		v_args->f_conv[i]->type->nb >= 0 &&
		v_args->f_conv[i]->type->l_nb >= 0)
	{
		if (v_args->f_conv[i]->l_conv == 'd' ||
			v_args->f_conv[i]->l_conv == 'D' ||
			v_args->f_conv[i]->l_conv == 'b')
			RET_STR = ft_strcat(RET_STR, " ");
	}
}

static void	is_space_plus_width(t_args *v_args, size_t i)
{
	is_caracters_is_sharp(v_args, i);
	is_caracters_is_space(v_args, i);
	is_caracters_is_positive(v_args, i);
	is_width_in_format(v_args, i);
}

int		print_format(t_args *v_args)
{
	size_t	i;
	size_t	test_c;

	i = 0;
	test_c = 0;
	while (v_args->index--)
	{
		is_space_plus_width(v_args, i);
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
		if (v_args->f_conv[i]->l_conv == '%')
			ft_putstr(v_args->f_conv[i]->type->str);
		is_caracters_is_neg_and_precision(v_args, i);
		i++;
	}
	ft_putstr(RET_STR);
	return (ft_strlen(RET_STR) + test_c);
}
