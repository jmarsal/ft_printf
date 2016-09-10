/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 01:47:32 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/10 01:59:01 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_width_in_format(const char *format, size_t *i, t_args *v_args)
{
	char *get_width;

	if (is_conversion_specifiers(format, i, F_WIDTH) == 1)
	{
		get_width = ft_get_number(format, i);
		v_args->f_conv[v_args->i_args]->width_precision->width = ft_atoi(get_width);
		free(get_width);
		v_args->f_conv[v_args->i_args]->is_width = 1;
	}
}

void	get_precision_in_format(const char *format, size_t *i, t_args *v_args)
{
	char *get_precision;

	if (is_conversion_specifiers(format, i, PRECISION) == 1)
	{
		*i += 1;
		get_precision = ft_get_number(format, i);
		if (ft_atoi(get_precision) != 0)
		{
			v_args->f_conv[v_args->i_args]->width_precision->precision = ft_atoi(get_precision);
			v_args->f_conv[v_args->i_args]->is_precision = 1;
			free(get_precision);
		}
		else
			v_args->f_conv[v_args->i_args]->is_precision = 0;
	}
}
