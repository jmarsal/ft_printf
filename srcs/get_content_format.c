/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 23:56:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/16 22:21:55 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	find_witch_caracters(t_result *result, size_t *i)
{
	char	*format;

	format = result->format;
	if (format[*i] == '-')
		A_MINUS = 1;
	else if (format[*i] == '+')
		A_PLUS = 1;
	else if (format[*i] == ' ')
		A_SPACE = 1;
	else if (format[*i] == '#')
		A_SHARP = 1;
	else if (format[*i] == '0')
		A_ZERO = 1;
}

static void	get_flags(t_result *result, size_t *i)
{
	char *format;

	format = result->format;
	while (is_conversion_flag(format, i, CARACTERS) == 1)
	{
		find_witch_caracters(result, i);
		*i += 1;
	}
	get_width_in_format(result, i);
}

static void	get_content_flags(t_result *result, size_t *i)
{
	char	*format;
	size_t	len;

	format = result->format;
	len = 0;
	*i += 1;
	get_flags(result, i);
	if (is_conversion_flag(format, i, C_SPECIFIERS) == 1)
	{
		result->tab_conv = tab_conv_add(result, result->i_args);
		conv_str_s(result, i);
		conv_bin_dec_oct(result, i);
		conv_hex_x(result, i);
		conv_mem_p(result, i);
		result->i_args++;
		*i += 1;
	}
}

static void	get_str_in_format(t_result *result, size_t *i)
{
	char	*format;
	int		j;
	int		k;

	format = result->format;
	j = 0;
	k = -1;
	while (format[*i] != '%' && format[*i] != '{')
	{
		if (format[*i] == '\0' || format[*i + 1] == '%' ||
			format[*i + 1] == '{')
		{
			result->tab_conv = tab_conv_add(result, result->i_args);
			L_CONV = 's';
			STR = ft_strnew(j);
			ft_bzero(STR, j + 1);
			while (++k <= j)
				STR[k] = format[*i - j + k];
			result->i_args++;
			*i = (format[*i]) ? *i +1 : *i;
			j = 0;
			break ;
		}
		*i += 1;
		j++;
	}
}

void		get_content_format(t_result *result)
{
	char	*format;
	size_t	i;

	format = result->format;
	i = 0;
	while (format[i])
	{
		get_str_in_format(result, &i);
		if (format[i] == '{')
		{
			result->tab_conv = tab_conv_add(result, result->i_args);
			L_CONV = 's';
			get_is_color(result, &i);
			result->i_args++;
		}
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			result->tab_conv = tab_conv_add(result, result->i_args);
			L_CONV = 's';
			STR = "%";
			i += 2;
			result->i_args++;
		}
		else if (format[i + 1] && format[i] == '%' && format[i + 1] != '%')
			get_content_flags(result, &i);
	}
}
