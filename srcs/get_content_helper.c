/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 01:47:32 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/19 22:23:03 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_width_in_format(const char *format, size_t *i, t_args *v_args)
{
	char *get_width;

	if (is_conversion_flag(format, i, F_WIDTH) == 1)
	{
		get_width = ft_get_number(format, i);
		v_args->f_conv[v_args->i_args]->width_precision->width = ft_atoi(get_width);
		v_args->f_conv[v_args->i_args]->width_precision->width_cpy =
		v_args->f_conv[v_args->i_args]->width_precision->width;
		free(get_width);
		v_args->f_conv[v_args->i_args]->is_width = 1;
	}
}

void	get_precision_in_format(const char *format, size_t *i, t_args *v_args)
{
	char *get_precision;

	if (is_conversion_flag(format, i, PRECISION) == 1)
	{
		*i += 1;
		get_precision = ft_get_number(format, i);
		if (ft_atoi(get_precision) >= 0)
		{
			v_args->f_conv[v_args->i_args]->width_precision->precision = ft_atoi(get_precision);
			v_args->f_conv[v_args->i_args]->width_precision->precision_cpy =
			v_args->f_conv[v_args->i_args]->width_precision->precision;
			v_args->f_conv[v_args->i_args]->is_precision = 1;
			free(get_precision);
		}
		else if (ft_atoi(get_precision) <= 0)
			RET_STR = ft_strcat(RET_STR, format);
		else
			v_args->f_conv[v_args->i_args]->is_precision = 0;
	}
}

static void find_witch_modifier(t_args *v_args, char *tmp_modifier)
{
	if (ft_strcmp(tmp_modifier, "hh") == 0)
		v_args->f_conv[v_args->i_args]->modifier->hh = 1;
	else if (ft_strcmp(tmp_modifier, "h") == 0)
		v_args->f_conv[v_args->i_args]->modifier->h = 1;
	else if (ft_strcmp(tmp_modifier, "l") == 0)
		v_args->f_conv[v_args->i_args]->modifier->l = 1;
	else if (ft_strcmp(tmp_modifier, "ll") == 0)
		v_args->f_conv[v_args->i_args]->modifier->ll = 1;
	else if (ft_strcmp(tmp_modifier, "j") == 0)
		v_args->f_conv[v_args->i_args]->modifier->j = 1;
	else if (ft_strcmp(tmp_modifier, "z") == 0)
		v_args->f_conv[v_args->i_args]->modifier->z = 1;
}

void	get_modifier_in_format(const char *format, size_t *i, t_args *v_args)
{
	char	tmp_modifier[3];
	size_t	index;

	index = 0;
	while (is_conversion_flag(format, i, L_MODIFIER) == 1)
	{
		v_args->f_conv[v_args->i_args]->is_modifier = 1;
		tmp_modifier[index++] = format[*i];
		*i += 1;
	}
	tmp_modifier[index] = '\0';
	if (v_args->f_conv[v_args->i_args]->is_modifier == 1)
		find_witch_modifier(v_args, tmp_modifier);
}
