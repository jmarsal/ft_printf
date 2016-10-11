/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 23:56:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/11 16:02:04 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	find_witch_caracters(const char *format, size_t *i, t_result *result)
{
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

static void	get_flags(const char *format, size_t *i, t_result *result)
{
	while (is_conversion_flag(format, i, CARACTERS) == 1)
	{
		find_witch_caracters(format, i, result);
		*i += 1;
	}
	get_width_in_format(format, i, result);
}

static void	get_content_flags(va_list *ap, t_result *result,
								const char *format, size_t *i)
{
	size_t	len;

	len = 0;
	*i += 1;
	get_flags(format, i, result);
	if (is_conversion_flag(format, i, C_SPECIFIERS) == 1)
	{
		conv_str_s(ap, result, format, i);
		conv_bin_dec_oct(ap, result, format, i);
		conv_hex_x(ap, result, format, i);
		conv_mem_p(ap, result, format, i);
		result->i_ap++;
		*i += 1;
	}
}

static void	get_str_in_format(const char *format, size_t *i, t_result *result)
{
	int		j;
	int		k;

	j = 0;
	k = -1;
	while (format[*i] != '%' && format[*i] != '{')
	{
		if (format[*i] == '\0' || format[*i + 1] == '%' ||
			format[*i + 1] == '{')
		{
			L_CONV = 's';
			STR = ft_strnew(j + 1);
			while (++k <= j)
				STR[k] = format[*i - j + k];
			result->i_ap++;
			*i = (format[*i]) ? *i +1 : *i;
			j = 0;
			break ;
		}
		*i += 1;
		j++;
	}
}

void		get_content_format(va_list *ap, const char *format,
								t_result *result)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		get_str_in_format(format, &i, result);
		if (format[i] == '{')
		{
			L_CONV = 's';
			get_is_color(format, &i, result);
			result->i_ap++;
		}
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			L_CONV = 's';
			STR = "%";
			i += 2;
			result->i_ap++;
		}
		else if (format[i + 1] && format[i] == '%' && format[i + 1] != '%')
			get_content_flags(ap, result, format, &i);
	}
}
