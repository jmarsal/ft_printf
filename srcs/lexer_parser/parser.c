/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/11/21 11:55:32 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	parser_get_precision(t_result *result, size_t *i, char **precision)
{
	if (result->format[*i] != '*')
	{
		*precision = ft_get_number(result->format, i);
		I_PRECISION_O = ft_atoi(*precision);
	}
	else if (result->format[*i] == '*' && !ft_isdigit(result->format[*i + 1]) &&
		((!result->tab_conv[result->i_args]->is_wildcard_width) ||
		(!I_WIDTH)))
	{
		result->tab_conv[result->i_args]->is_wildcard_prec = 1;
		I_PRECISION_O = (int)va_arg(R_AP, int);
		*i += 1;
	}
	if (I_PRECISION_O < 0)
	{
		I_PRECISION_O = -I_PRECISION_O;
		A_MINUS = 1;
	}
	I_PRECISION_CPY = I_PRECISION_O;
	I_IS_PRECISION = 1;
}

static void	parser_precision(t_result *result, size_t *i)
{
	char	*get_precision;
	char	*format;

	get_precision = NULL;
	format = result->format;
	if ((ft_strchr(PRECISION, format[*i])) || (ft_isdigit(format[*i]) &&
		format[*i - 1] == '*'))
	{
		if (format[*i] == '.')
			*i += 1;
		parser_get_precision(result, i, &get_precision);
		ft_free_null(get_precision);
	}
	parser_modifier(result, i);
}

static void	parser_get_width(t_result *result, size_t *i, char **get_width)
{
	if (result->format[*i] != '*')
	{
		*get_width = ft_get_number(result->format, i);
		I_WIDTH = ft_atoi(*get_width);
	}
	else if (result->format[*i] == '*')
	{
		result->tab_conv[result->i_args]->is_wildcard_width = 1;
		I_WIDTH = (int)va_arg(R_AP, int);
		if (I_WIDTH < 0)
		{
			I_WIDTH = -I_WIDTH;
			A_MINUS = 1;
		}
		*i += 1;
	}
}

static void	parser_width(t_result *result, size_t *i)
{
	char	*get_width;
	char	*format;

	get_width = NULL;
	format = result->format;
	if (ft_strchr(F_WIDTH, format[*i]))
	{
		parser_get_width(result, i, &get_width);
		I_WIDTH_CPY = I_WIDTH;
		ft_free_null(get_width);
		I_IS_WIDTH = 1;
	}
	parser_precision(result, i);
}

void		get_flags(t_result *result, size_t *i)
{
	while (ft_strchr(CARACTERS, result->format[*i]))
	{
		if (result->format[*i] == '-')
			A_MINUS = 1;
		else if (result->format[*i] == '+')
			A_PLUS = 1;
		else if (result->format[*i] == ' ')
			A_SPACE = 1;
		else if (result->format[*i] == '#')
			A_SHARP = 1;
		else if (result->format[*i] == '0')
			A_ZERO = 1;
		*i += 1;
	}
	parser_width(result, i);
}
