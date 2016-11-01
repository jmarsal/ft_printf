/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:01:48 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/27 23:57:20 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
			return (print_error_specifier(format[*i]));
	}
	return (0);
}
