/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 23:56:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/10/07 12:03:01 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	find_witch_caracters(const char *format, size_t *i, t_args *v_args)
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

static void	get_flags(const char *format, size_t *i, t_args *v_args)
{
	while (is_conversion_flag(format, i, CARACTERS) == 1)
	{
		find_witch_caracters(format, i, v_args);
		*i += 1;
	}
	get_width_in_format(format, i, v_args);
}

static void	get_content_flags(va_list *args, t_args *v_args,
								const char *format, size_t *i)
{
	size_t	len;

	len = 0;
	*i += 1;
	get_flags(format, i, v_args);
	if (is_conversion_flag(format, i, C_SPECIFIERS) == 1)
	{
		conv_str_s(args, v_args, format, i);
		conv_bin_dec_oct(args, v_args, format, i);
		conv_hex_x(args, v_args, format, i);
		conv_mem_p(args, v_args, format, i);
		v_args->i_args++;
		*i += 1;
	}
}

static void	get_str_in_format(const char *format, size_t *i, t_args *v_args)
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
			v_args->i_args++;
			*i = (format[*i]) ? *i +1 : *i;
			j = 0;
			break ;
		}
		*i += 1;
		j++;
	}
}

void		get_content_format(va_list *args, const char *format,
								t_args *v_args)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		get_str_in_format(format, &i, v_args);
		if (format[i] == '{')
		{
			L_CONV = 's';
			get_is_color(format, &i, v_args);
			v_args->i_args++;
		}
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			L_CONV = 's';
			STR = "%";
			i += 2;
			v_args->i_args++;
		}
		else if (format[i + 1] && format[i] == '%' && format[i + 1] != '%')
			get_content_flags(args, v_args, format, &i);
	}
}
