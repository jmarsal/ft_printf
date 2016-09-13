/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:05:15 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/14 01:03:27 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_hex_x(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'x')
	{
		RET_STR = ft_strcat(RET_STR,
				ft_strtolower(ft_itoa_base(v_args->f_conv[i]->type->nb, 16)));
	}
}

void	print_hex_lx(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'X')
	{
		RET_STR = ft_strcat(RET_STR,
							ft_itoa_base(v_args->f_conv[i]->type->nb, 16));
	}
}

void	print_hex_b(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->l_conv == 'b')
	{
		if (v_args->f_conv[i]->type->nb == INT_MIN)
			RET_STR = ft_strjoin(RET_STR,
							"10000000000000000000000000000000");
		else
			RET_STR = ft_strcat(RET_STR,
							ft_itoa_base(v_args->f_conv[i]->type->nb, 2));
	}
}
