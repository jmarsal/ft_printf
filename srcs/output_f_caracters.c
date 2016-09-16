/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 01:07:28 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/16 02:37:22 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_caracters_is_neg_and_precision(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->caracters->minus == 1 &&
		v_args->f_conv[i]->is_width == 1)
	{
		while (v_args->f_conv[i]->width_precision->width_cpy > 0)
		{
			RET_STR = ft_strcat(RET_STR, " ");
			v_args->f_conv[i]->width_precision->width_cpy--;
		}
	}
}

void	is_width_in_format(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->is_width &&
		!v_args->f_conv[i]->caracters->minus)
	{
		if (v_args->f_conv[i]->caracters->zero &&
			!v_args->f_conv[i]->is_precision)
		{
			if (v_args->f_conv[i]->caracters->plus)
				RET_STR = ft_strcat(RET_STR, "+");
			if ((v_args->f_conv[i]->type->nb < 0 ||
				v_args->f_conv[i]->type->l_nb < 0) &&
				(v_args->f_conv[i]->l_conv != 'x' &&
				v_args->f_conv[i]->l_conv != 'X'))
				{
					v_args->f_conv[i]->type->nb = -v_args->f_conv[i]->type->nb;
					v_args->f_conv[i]->type->l_nb = v_args->f_conv[i]->type->l_nb;
					RET_STR = ft_strcat(RET_STR, "-");
				}
			while (v_args->f_conv[i]->width_precision->width_cpy > 0)
			{
				RET_STR = ft_strcat(RET_STR, "0");
				v_args->f_conv[i]->width_precision->width_cpy--;
			}
		}
		else
		{
			if (v_args->f_conv[i]->width_precision->precision_cpy > 0)
				v_args->f_conv[i]->width_precision->width_cpy -=
				v_args->f_conv[i]->width_precision->precision_cpy;
			while (v_args->f_conv[i]->width_precision->width_cpy-- > 0)
				RET_STR = ft_strcat(RET_STR, " ");
			if (v_args->f_conv[i]->is_precision &&
				v_args->f_conv[i]->caracters->plus)
				RET_STR = ft_strcat(RET_STR, "+");
			while (v_args->f_conv[i]->width_precision->precision_cpy-- > 0)
				RET_STR = ft_strcat(RET_STR, "0");
			if (v_args->f_conv[i]->caracters->plus == 1 &&
				v_args->f_conv[i]->caracters->minus == 0 &&
				!v_args->f_conv[i]->is_precision)
				RET_STR = ft_strcat(RET_STR, "+");
		}
	}
}
//
void	is_caracters_is_sharp(t_args *v_args, size_t i)
{
	if (v_args->f_conv[i]->caracters->sharp == 1)
	{
		if (v_args->f_conv[i]->l_conv == 'o' ||
			v_args->f_conv[i]->l_conv == 'O')
			RET_STR = ft_strcat(RET_STR, "0");
		else if (v_args->f_conv[i]->l_conv == 'x')
			RET_STR = ft_strcat(RET_STR, "0x");
		else if (v_args->f_conv[i]->l_conv == 'X')
			RET_STR = ft_strcat(RET_STR, "0X");
	}
}
