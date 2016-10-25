/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/25 17:26:49 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	find_witch_modifier(t_result *result, char *tmp_modifier)
{
	if (ft_strcmp(tmp_modifier, "hh") == 0)
		I_MOD_HH = 1;
	else if (ft_strcmp(tmp_modifier, "h") == 0)
		I_MOD_H = 1;
	else if (ft_strcmp(tmp_modifier, "l") == 0)
		I_MOD_L = 1;
	else if (ft_strcmp(tmp_modifier, "ll") == 0)
		I_MOD_LL = 1;
	else if (ft_strcmp(tmp_modifier, "j") == 0)
		I_MOD_J = 1;
	else if (ft_strcmp(tmp_modifier, "z") == 0)
		I_MOD_Z = 1;
}

static void	parser_modifier(t_result *result, size_t *i)
{
	char	*format;
	char	tmp_modifier[3];
	size_t	index;

	format = result->format;
	index = 0;
	while (format[*i] && ft_strchr(L_MODIFIER, format[*i]))
	{
		IS_MODIFIER = 1;
		tmp_modifier[index++] = format[*i];
		*i += 1;
	}
	tmp_modifier[index] = '\0';
	if (IS_MODIFIER == 1)
		find_witch_modifier(result, tmp_modifier);
}

static void	parser_precision(t_result *result, size_t *i)
{
	char	*get_precision;
	char	*format;

	get_precision = NULL;
	format = result->format;
	if (ft_strchr(PRECISION, format[*i]))
	{
		*i += 1;
		get_precision = ft_get_number(format, i);
		if ((I_PRECISION_O = ft_atoi(get_precision)) > 0)
		{
			I_PRECISION_CPY = I_PRECISION_O;
			I_IS_PRECISION = 1;
		}
		else if (I_PRECISION_O <= 0)
			I_IS_PRECISION = 0;
		ft_free_null(get_precision);
	}
	parser_modifier(result, i);
}

static void	parser_width(t_result *result, size_t *i)
{
	char	*get_width;
	char	*format;

	get_width = NULL;
	format = result->format;
	if (ft_strchr(F_WIDTH, format[*i]))
	{
		get_width = ft_get_number(format, i);
		I_WIDTH = ft_atoi(get_width);
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
