/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_and_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 12:05:23 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/25 17:20:01 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	lex_and_parse(t_result *result)
{
	char	*format;
	size_t	i;

	format = result->format;
	i = 0;
	while (format[i])
	{
		// printf("MINUS = %d\n", A_MINUS);
		parser_str(result, &i);
		lexer_parser_color(result, &i);
		lex_parse_percent(result, &i);
		if ((parser_specifier(result, &i)) == -1)
			return (-1);
	}
	return (0);
}

int			treatment(t_result *result)
{
	tab_conv_add(result, result->i_args);
	if ((lex_and_parse(result)) == -1)
		return (-1);
	result->index = result->i_args;
	return (0);
}
