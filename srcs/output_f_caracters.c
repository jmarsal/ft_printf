/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 01:07:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/07 01:44:16 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_f_caracters_is_positive(t_v_args *v_args, size_t i)
{
	if ((v_args->f_conv[i]->nb >= 0 && v_args->f_conv[i]->l_nb >= 0
		&& (long int)v_args->f_conv[i]->u_l_nb >= 0) &&
		v_args->f_conv[i]->f_caracters->plus == 1)
	{
		ft_putchar('+');
			v_args->ret_ft_printf += 1;
	}
}

void	is_f_caracters_is_neg_and_precision(t_v_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->f_caracters->minus == 1)
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
	if (v_args->f_conv[i]->f_caracters->minus != 1)
	{
		while (v_args->f_conv[i]->f_width-- > 0)
		{
			if (v_args->f_conv[i]->f_caracters->zero == 0)
				ft_putchar(' ');
			else
				ft_putchar('0');
			v_args->ret_ft_printf += 1;
		}
	}
}

void	is_f_caracters_is_sharp(t_v_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->f_caracters->sharp == 1)
	{
		if (v_args->f_conv[i]->l_conv == 'o' ||
			v_args->f_conv[i]->l_conv == 'O')
				ft_putchar('0');
		else if (v_args->f_conv[i]->l_conv == 'x')
		{
			ft_putstr("0x");
				v_args->ret_ft_printf += 1;
		}
		else if (v_args->f_conv[i]->l_conv == 'X')
		{
			ft_putstr("0X");
				v_args->ret_ft_printf += 1;
		}
			v_args->ret_ft_printf += 1;
	}
}

void	is_f_caracters_is_space(t_v_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->f_caracters->space == 1 &&
					v_args->f_conv[i]->nb >= 0 &&
					v_args->f_conv[i]->l_nb >= 0)
	{
		if (v_args->f_conv[i]->l_conv == 'd' ||
			v_args->f_conv[i]->l_conv == 'D')
				ft_putchar(' ');
		v_args->ret_ft_printf += 1;
	}
}
