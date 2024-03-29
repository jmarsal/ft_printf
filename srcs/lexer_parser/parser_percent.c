/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:42:01 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/29 13:29:26 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	lex_parse_percent(t_result *result, size_t *i)
{
	char	*format;

	format = result->format;
	if (format[*i + 1] && (format[*i] == '%' && format[*i + 1] == '%'))
	{
		ft_free(STR);
		tab_conv_add(result, result->i_args);
		L_CONV = 's';
		STR = ft_strdup("%");
		*i += 2;
		result->i_args++;
	}
}

void	parser_percent_if_flags_betwin(t_result *result, size_t *i)
{
	ft_free(STR);
	tab_conv_add(result, result->i_args);
	L_CONV = 's';
	A_SPACE = 0;
	if (I_WIDTH)
		I_WIDTH_CPY -= 1;
	STR = ft_strdup("%");
	STRLEN = 1;
	*i += 1;
	result->i_args++;
}
