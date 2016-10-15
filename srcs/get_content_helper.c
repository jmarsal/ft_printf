/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 01:47:32 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/16 00:00:27 by jmarsal          ###   ########.fr       */
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

static void	get_modifier_in_format(t_result *result, size_t *i)
{
	char	*format;
	char	tmp_modifier[3];
	size_t	index;

	format = result->format;
	index = 0;
	while (is_conversion_flag(format, i, L_MODIFIER) == 1)
	{
		IS_MODIFIER = 1;
		tmp_modifier[index++] = format[*i];
		*i += 1;
	}
	tmp_modifier[index] = '\0';
	if (IS_MODIFIER == 1)
		find_witch_modifier(result, tmp_modifier);
}

static void	get_precision_in_format(t_result *result, size_t *i)
{
	char	*get_precision;
	char	*format;

	get_precision = NULL;
	format = result->format;
	if (is_conversion_flag(format, i, PRECISION) == 1)
	{
		*i += 1;
		get_precision = ft_get_number(format, i);
		if ((I_PRECISION_O = ft_atoi(get_precision)) > 0)
		{
			I_PRECISION_CPY = I_PRECISION_O;
			I_IS_PRECISION = 1;
		}
		else if (I_PRECISION_O <= 0)
			I_IS_PRECISION = 0; // Je pense qu'il y a un soucis, peut etre exit (-1) ? A voir...
		ft_free_null(get_precision);
	}
	get_modifier_in_format(result, i);
}

void		get_width_in_format(t_result *result, size_t *i)
{
	char	*get_width;
	char	*format;

	get_width = NULL;
	format = result->format;
	if (is_conversion_flag(format, i, F_WIDTH) == 1)
	{
		get_width = ft_get_number(format, i);
		I_WIDTH = ft_atoi(get_width);
		I_WIDTH_CPY = I_WIDTH;
		ft_free_null(get_width);
		I_IS_WIDTH = 1;
	}
	get_precision_in_format(result, i);
}
