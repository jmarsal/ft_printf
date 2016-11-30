/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:01:48 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/30 09:20:24 by jmarsal          ###   ########.fr       */
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
	char	*format;

	format = result->format;
	if (format[*i] == 'c' || format[*i] == 'C' ||
		format[*i] == 's' || format[*i] == 'S')
		conv_str_s(result, i);
	else if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'D' ||
		format[*i] == 'o' || format[*i] == 'O' ||
		format[*i] == 'u' || format[*i] == 'U' ||
		format[*i] == 'b')
		conv_bin_dec_oct(result, i);
	else if (format[*i] == 'x' || format[*i] == 'X')
		conv_hex_x(result, i);
	else if (format[*i] == 'p')
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
		tab_conv_add(result, result->i_args);
		if ((get_flags(result, i)) == -1)
			return (-1);
		if (format[*i] && ft_strchr(C_SPECIFIERS, format[*i]))
			get_specifier(result, i);
		else if (format[*i] == '%')
			parser_percent_if_flags_betwin(result, i);
		else
			reset_flags_struct(result);
	}
	return (0);
}
