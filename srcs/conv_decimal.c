/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:46:16 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/21 23:45:40 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_decimal_d(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'd' || format[*i] == 'i')
	{
		L_CONV = 'd';
		if (!(v_args->f_conv[v_args->i_args]->modifier->ll ||
			v_args->f_conv[v_args->i_args]->modifier->l))
		{
			INT = va_arg(*args, int);
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
												ft_strlen(ft_itoa(INT));
			v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
												ft_strlen(ft_itoa(INT));
		}
		else if (v_args->f_conv[v_args->i_args]->modifier->l ||
				v_args->f_conv[v_args->i_args]->modifier->ll)
		{
			L_INT = va_arg(*args, long);
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
											ft_strlen(ft_litoa(L_INT));
			v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
											ft_strlen(ft_litoa(L_INT));
		}
		if (A_PLUS == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		if (A_SPACE == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
	}
}

void	conv_decimal_ld(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'D')
	{
		L_CONV = 'D';
		L_INT = va_arg(*args, long int);
		v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
												ft_strlen(ft_litoa(L_INT));
		v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
												ft_strlen(ft_itoa(L_INT));
		if (A_PLUS == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		if (A_SPACE == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
	}
}

void	conv_u_decimal_u(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'u')
	{
		if (!(v_args->f_conv[v_args->i_args]->modifier->ll ||
			v_args->f_conv[v_args->i_args]->modifier->l))
		{
			L_CONV = 'u';
			U_INT = va_arg(*args, unsigned int);
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
												ft_strlen(ft_litoa(U_INT));
			v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
												ft_strlen(ft_itoa(U_INT));
			if (A_PLUS == 1)
				v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
			if (A_SPACE == 1)
				v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		}
	}
}

void	conv_lu_decimal_lu(va_list *args, t_args *v_args, const char *format,
					size_t * i)
{
	if (format[*i] == 'U' || (format[*i] == 'u' &&
		(v_args->f_conv[v_args->i_args]->modifier->l ||
			v_args->f_conv[v_args->i_args]->modifier->ll)))
	{
		L_CONV = 'U';
		U_L_INT = va_arg(*args, unsigned long);
		v_args->f_conv[v_args->i_args]->width_precision->width_cpy -=
												ft_strlen(ft_ulitoa(U_L_INT));
		v_args->f_conv[v_args->i_args]->width_precision->precision_cpy -=
												ft_strlen(ft_itoa(U_L_INT));
		if (A_PLUS == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
		if (A_SPACE == 1)
			v_args->f_conv[v_args->i_args]->width_precision->width_cpy--;
	}
}
