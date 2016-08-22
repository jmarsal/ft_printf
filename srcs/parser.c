/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/08/22 15:55:38 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	get_content_flags(va_list *args, t_v_args *v_args,
								const char *format, size_t *i)
{
	if (format[*i + 1] && (format[*i + 1] == 's' ||
							format[*i + 1] == 'd' ||
							format[*i + 1] == 'i' ||
							format[*i + 1] == 'c' ||
							format[*i + 1] == 'x' ||
							format[*i + 1] == 'X' ||
							format[*i + 1] == 'b'))
	{
		conv_str_s(args, v_args, format, i);
		conv_decimal_d(args, v_args, format, i);
		conv_char_c(args, v_args, format, i);
		conv_hex_x(args, v_args, format, i);
		conv_hex_lx(args, v_args, format, i);
		conv_binary_b(args, v_args, format, i);
		v_args->i_args++;
		*i += 2;
	}
}

static void	get_content_format(va_list *args, const char *format,
								t_v_args *v_args)
{
	size_t		i;

	i = 0;
	while (format[i])
	{
		if (format[i] && format[i] != '%')
		{
			L_CONV = 's';
			STR = ft_strdup(ft_strchr_bef(format + i, '%'));
			i += ft_strlen(STR);
			v_args->ret_ft_printf += ft_strlen(STR);
			v_args->i_args++;
		}
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			L_CONV = '%';
			STR = "%";
			i += 2;
			v_args->i_args++;
			v_args->ret_ft_printf++;
		}
		if (format[i + 1] && format[i] == '%' && format[i + 1] != '%')
			get_content_flags(args, v_args, format, &i);
	}
}

static int	get_index(t_v_args *v_args, const char *format, size_t *i)
{
	if (format[*i + 1] && (format[*i + 1] == 's' ||
							format[*i + 1] == 'd' ||
							format[*i + 1] == 'i' ||
							format[*i + 1] == 'c' ||
							format[*i + 1] == 'x' ||
							format[*i + 1] == 'X' ||
							format[*i + 1] == 'b'))
	{
		v_args->index += 1;
		*i += 2;
	}
	else if (format[*i + 1])
	{
		ft_putstr("warning: invalid conversion specifier '");
		ft_putchar(format[*i + 1]);
		ft_putstr("'");
		return (-1);
	}
	return (0);
}

static int	search_flags_in_format(t_v_args *v_args, const char *format)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			if ((format[i + 1] && format[i + 1] == '%') ||
				(format[i + 1] == '\0'))
				v_args->index++;
			i++;
		}
		if (format[i + 1] && (format[i] == '%' && format[i + 1] == '%'))
		{
			i += 2;
			v_args->index++;
		}
		else if (format[i] == '%' &&
				(get_index(v_args, format, &i) == -1))
			return (-1);
	}
	return (0);
}

int			treatment(va_list *args, const char *format)
{
	t_v_args	*v_args;

	if (!(v_args = init_t_v_args()))
		return (-1);
	if (search_flags_in_format(v_args, format) == -1)
		return (-1);
	if (!(v_args->f_conv = init_tab_args(v_args)))
		return (-1);
	get_content_format(args, format, v_args);
	print_format(v_args);
	return (v_args->ret_ft_printf); // Faire plusieurs test (str + flags '%s' ou int pour
				// check le retour exact)
}
