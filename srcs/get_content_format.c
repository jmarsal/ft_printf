/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 23:56:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 16:38:12 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	find_witch_caracters(const char *format, size_t *i, t_args *v_args)
{
	if (format[*i] == '-')
		v_args->f_conv[v_args->i_args]->caracters->minus = 1;
	if (format[*i] == '+')
		v_args->f_conv[v_args->i_args]->caracters->plus = 1;
	if (format[*i] == ' ')
		v_args->f_conv[v_args->i_args]->caracters->space = 1;
	if (format[*i] == '#')
		v_args->f_conv[v_args->i_args]->caracters->sharp = 1;
	if (format[*i] == '0')
		v_args->f_conv[v_args->i_args]->caracters->zero = 1;
}

static void	get_caracters(const char *format, size_t *i, t_args *v_args)
{
	while (is_conversion_specifiers(format, i, CARACTERS) == 1)
	{
		find_witch_caracters(format, i, v_args);
		*i += 1;
	}
}

static void	get_content_flags(va_list *args, t_args *v_args,
								const char *format, size_t *i)
{
	size_t	len;

	len = 0;
	*i += 1;
	get_caracters(format, i, v_args);
	get_width_in_format(format, i, v_args);
	get_precision_in_format(format, i, v_args);
	if (is_conversion_specifiers(format, i, C_SPECIFIERS) == 1)
	{
		conv_str_s(args, v_args, format, i);
		conv_decimal_d(args, v_args, format, i);
		conv_decimal_ld(args, v_args, format, i);
		conv_char_c(args, v_args, format, i);
		conv_hex_x(args, v_args, format, i);
		conv_hex_lx(args, v_args, format, i);
		conv_binary_b(args, v_args, format, i);
		conv_mem_p(args, v_args, format, i);
		conv_octal_o(args, v_args, format, i);
		conv_octal_lo(args, v_args, format, i);
		conv_u_decimal_u(args, v_args, format, i);
		conv_lu_decimal_lu(args, v_args, format, i);
		v_args->i_args++;
		*i += 1;
	}
}

void	get_content_format(va_list *args, const char *format,
								t_args *v_args)
{
	size_t		i;

	i = 0;
	while (format[i])
	{
		if (format[i] && format[i] != '%')
		{
			L_CONV = 's';
			STR = ft_strdup(ft_strchr_bef(format + i, '%'));
			i += ft_strlen(STR);
			v_args->i_args++;
		}
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			L_CONV = 's';
			STR = "%";
			i += 2;
			v_args->i_args++;
		}
		if (format[i + 1] && format[i] == '%' && format[i + 1] != '%')
			get_content_flags(args, v_args, format, &i);
	}
}
