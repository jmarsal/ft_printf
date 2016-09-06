/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 01:07:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/06 16:08:25 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_f_caracters_is_positive(t_v_args *v_args, size_t i)
{
	if ((v_args->f_conv[i]->nb >= 0 && v_args->f_conv[i]->l_nb >= 0
		&& (long int)v_args->f_conv[i]->u_l_nb >= 0) &&
		v_args->f_conv[i]->f_caracters == '+')
	{
		ft_putchar('+');
		v_args->ret_ft_printf += 1;
	}
}

void	is_f_caracters_is_neg_and_precision(t_v_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->f_caracters == '-')
	{
		while (v_args->f_conv[i]->f_width-- > 0)
		{
			ft_putchar(' ');
			v_args->ret_ft_printf += 1;
		}
	}
}

void	is_precision(t_v_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->f_caracters != '-')
	{
		while (v_args->f_conv[i]->f_width-- > 0)
		{
			if (v_args->f_conv[i]->f_width_zero == 0)
				ft_putchar(' ');
			else
				ft_putchar('0');
			v_args->ret_ft_printf += 1;
		}
	}
}

void	is_f_caracters_is_sharp(t_v_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->f_caracters == '#')
	{
		if (v_args->f_conv[i]->l_conv == 'o' ||
			v_args->f_conv[i]->l_conv == 'O')
				ft_putchar('0');
		else if (v_args->f_conv[i]->l_conv == 'x')
		{
			v_args->ret_ft_printf += 1;
			ft_putstr("0x");
		}
		else if (v_args->f_conv[i]->l_conv == 'X')
		{
			v_args->ret_ft_printf += 1;
			ft_putstr("0X");
		}
		v_args->ret_ft_printf += 1;
	}
}
