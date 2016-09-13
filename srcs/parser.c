/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:03:08 by jmarsal           #+#    #+#             */
/*   Updated: 2016/09/13 16:28:44 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	if_specifier(const char *format, t_w_or_p tmp,
						size_t *i, size_t *index)
{
	while (is_conversion_specifiers(format, i, CARACTERS) == 1)
		*i += 1;
	if (is_conversion_specifiers(format, i, F_WIDTH) == 1)
	{
		while (ft_isalnum(format[*i]))
			*i += 1;
		tmp.width = 1;
	}
	if (is_conversion_specifiers(format, i, PRECISION) == 1)
	{
		*i += 1;
		while (ft_isalnum(format[*i]))
			*i += 1;
		tmp.precision = 1;
	}
	// if (is_conversion_specifiers(format, i, L_MODIFIER) == 1)
	if (tmp.width == 1 || tmp.precision == 1)
		*i -= 1;
	if (is_conversion_specifiers(format, i, C_SPECIFIERS) == 1)
	{
		*index += 1;
		*i += 1;
		return (0);
	}
	return (-1);
}

static int	get_index(t_args *v_args, const char *format, size_t *i)
{
	t_w_or_p	tmp;

	tmp.width = 0;
	tmp.precision = 0;
	*i += 1;
	if (if_specifier(format, tmp, i, &v_args->index) != -1)
		return(0);
	else
	{
		ft_putstr("error : invalid conversion specifier '");
		ft_putchar(format[*i]);
		ft_putstr("'");
	}
	return (-1);
}

static int	search_flags_in_format(t_args *v_args, const char *format)
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
		else if (format[i + 1] && format[i] == '%' &&
				(get_index(v_args, format, &i) == -1))
			return (-1);
	}
	return (0);
}

int			treatment(va_list *args, const char *format, t_args *v_args)
{
	if (search_flags_in_format(v_args, format) == -1)
		return (-1);
	if (!(v_args->f_conv = init_tab_args(v_args)))
		return (-1);
	get_content_format(args, format, v_args);
	return (0);
}
