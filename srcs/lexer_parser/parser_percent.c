/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:42:01 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/03 15:30:17 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	lex_parse_percent(t_result *result, size_t *i)
{
	char	*format;

	format = result->format;
	if (format[*i + 1] && (format[*i] == '%' && format[*i + 1] == '%'))
		{
			tab_conv_add(result, result->i_args);		
			L_CONV = 's';
			STR = "%";
			*i += 2;
			result->i_args++;
		}
}

void	parser_percent_if_flags_betwin(t_result *result, size_t *i)
{
	tab_conv_add(result, result->i_args);
	L_CONV = 's';
	if (I_WIDTH)
		I_WIDTH_CPY -= 1;
	STR = "%";
	*i += 1;
	result->i_args++;
}
