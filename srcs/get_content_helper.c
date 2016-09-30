/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 01:47:32 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/29 01:50:00 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void find_witch_modifier(t_args *v_args, char *tmp_modifier)
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

static void	get_modifier_in_format(const char *format, size_t *i, t_args *v_args)
{
	char	tmp_modifier[3];
	size_t	index;

	index = 0;
	while (is_conversion_flag(format, i, L_MODIFIER) == 1)
	{
		IS_MODIFIER = 1;
		tmp_modifier[index++] = format[*i];
		*i += 1;
	}
	tmp_modifier[index] = '\0';
	if (IS_MODIFIER == 1)
		find_witch_modifier(v_args, tmp_modifier);
}

static void	get_precision_in_format(const char *format, size_t *i, t_args *v_args)
{
	char *get_precision;

	get_precision = NULL;
	if (is_conversion_flag(format, i, PRECISION) == 1)
	{
		*i += 1;
		get_precision = ft_get_number(format, i);
		if ((I_PRECISION_O = ft_atoi(get_precision)) >= 0)
		{
			I_PRECISION_CPY = I_PRECISION_O;
			I_IS_PRECISION = 1;
		}
		else if (I_PRECISION_O <= 0)
			RET_STR = ft_strcat(RET_STR, format);
		free(get_precision);
	}
	get_modifier_in_format(format, i, v_args);
}

void		get_width_in_format(const char *format, size_t *i, t_args *v_args)
{
	char *get_width;

	get_width = NULL;
	if (is_conversion_flag(format, i, F_WIDTH) == 1)
	{
		get_width = ft_get_number(format, i);
		I_WIDTH = ft_atoi(get_width);
		I_WIDTH_CPY = I_WIDTH;
		free(get_width);
		v_args->f_conv[v_args->i_args]->is_width = 1;
	}
	get_precision_in_format(format, i, v_args);
}
