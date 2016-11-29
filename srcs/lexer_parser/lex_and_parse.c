/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_and_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 12:05:23 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/29 14:54:08 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	if_undefined_percent(char *format, size_t i)
{
	int	test;

	test = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			test++;
			if (!format[i + 1] && test < 2)
				return (-1);
			if (format[i + 1] == ' ')
			{
				i++;
				while (format[i] && format[i] == ' ')
				{
					if (!format[i + 1])
						return(-1);
					i++;
				}
			}
		}
		else
			return (0);
		i++;
	}
	return (0);
}

static int	lex_and_parse(t_result *result)
{
	char	*format;
	size_t	i;

	format = result->format;
	i = 0;
	while (format[i])
	{
		if ((if_undefined_percent(format, i)) == -1)
			break;
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
