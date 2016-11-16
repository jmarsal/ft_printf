/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:01:48 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/11 16:37:16 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		reset_flags_struct(t_result *result)
{
	A_SPACE = 0;
	I_MOD_H = 0;
	I_MOD_HH = 0;
	I_MOD_L = 0;
	I_MOD_LL = 0;
	I_MOD_J = 0;
	I_MOD_Z = 0;
	L_CONV = '\0';
}

static void	get_specifier(t_result *result, size_t *i)
{
	tab_conv_add(result, result->i_args);	
	conv_str_s(result, i);
	conv_bin_dec_oct(result, i);
	conv_hex_x(result, i);
	conv_mem_p(result, i);
	result->i_args++;
	*i += 1;
}

int			parser_specifier(t_result *result, size_t *i)
{
	char	*format;

	format = result->format;

	if (format[*i + 1] && format[*i] == '%' && format[*i + 1] != '%')
	{
		*i += 1;
		get_flags(result, i);
		if (format[*i] && ft_strchr(C_SPECIFIERS, format[*i]))
			get_specifier(result, i);
		else if (format[*i] == '%')
			parser_percent_if_flags_betwin(result, i);
		else
			reset_flags_struct(result);
			// return (print_error_specifier(format[*i]));
	}
	return (0);
}
